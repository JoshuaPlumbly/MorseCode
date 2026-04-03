#include "cli.h"
#include <iostream>

static const OptionSpec* findSpec(
    const std::vector<OptionSpec>& specs,
    const std::string& name
) {
    for (const auto& spec : specs) {
        if (spec.longName == name || spec.shortName == name) {
            return &spec;
        }
    }
    return nullptr;
}

ParsedArgs parseArgs(
    int argc,
    char* argv[],
    const std::vector<OptionSpec>& specs,
    bool& success
) {
    ParsedArgs args;
    success = true;

    if (argc < 2) return args;

    args.command = argv[1];
    bool endOfOptions = false;

    for (int i = 2; i < argc; ++i) {
        std::string current = argv[i];

        // End of options marker
        if (current == "--") {
            endOfOptions = true;
            continue;
        }

        // Long option
        if (!endOfOptions && current.rfind("--", 0) == 0) {
            const OptionSpec* spec = findSpec(specs, current);

            if (!spec) {
                std::cerr << "Unknown option: " << current << "\n";
                success = false;
                return args;
            }

            if (spec->requiresValue) {
                if (i + 1 >= argc) {
                    std::cerr << "Option requires value: " << current << "\n";
                    success = false;
                    return args;
                }
                args.options[spec->longName] = argv[++i];
            }
            else {
                args.flags.insert(spec->longName);
            }
        }
        // Short flags (can be combined)
        else if (!endOfOptions && current.rfind("-", 0) == 0 && current.length() > 1) {
            for (size_t j = 1; j < current.length(); ++j) {
                std::string shortOpt = "-" + std::string(1, current[j]);

                const OptionSpec* spec = findSpec(specs, shortOpt);

                if (!spec) {
                    std::cerr << "Unknown option: " << shortOpt << "\n";
                    success = false;
                    return args;
                }

                if (spec->requiresValue) {
                    // Value must be next argument
                    if (j != current.length() - 1) {
                        std::cerr << "Option requires value and cannot be combined: "
                            << shortOpt << "\n";
                        success = false;
                        return args;
                    }

                    if (i + 1 >= argc) {
                        std::cerr << "Option requires value: " << shortOpt << "\n";
                        success = false;
                        return args;
                    }

                    args.options[spec->longName] = argv[++i];
                }
                else {
                    args.flags.insert(spec->longName);
                }
            }
        }
        // Positional
        else {
            args.positional.push_back(current);
        }
    }

    return args;
}

std::string join(const std::vector<std::string>& vec) {
    std::string result;

    for (size_t i = 0; i < vec.size(); ++i) {
        result += vec[i];
        if (i < vec.size() - 1) result += " ";
    }

    return result;
}