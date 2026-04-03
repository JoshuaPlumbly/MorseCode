#include <iostream>
#include <fstream>

#include "cli.h"
#include "morse.h"

int main(int argc, char* argv[]) {
    // Define allowed options
    std::vector<OptionSpec> specs = {
        {"--output", "-o", true},
        {"--input",  "-i", true},
        {"--verbose","-v", false}
    };

    bool success;
    ParsedArgs args = parseArgs(argc, argv, specs, success);

    if (!success) return 1;

    if (args.command.empty() || args.command == "help") {
        std::cout << "Usage:\n";
        std::cout << "  morse encode \"text\" [-o file]\n";
        std::cout << "  morse decode \"morse\" [-i file]\n";
        return 0;
    }

    std::string input;

    if (args.options.count("--input")) {
        std::ifstream file(args.options["--input"]);
        if (!file) {
            std::cerr << "Error: Cannot open input file\n";
            return 1;
        }
        std::getline(file, input, '\0');
    }
    else {
        input = join(args.positional);
    }

    std::string result;

    if (args.command == "encode") {
        result = morse::encode(input);
    }
    else if (args.command == "decode") {
        result = morse::decode(input);
    }
    else {
        std::cerr << "Unknown command\n";
        return 1;
    }

    if (args.flags.count("--verbose")) {
        std::cout << "[DEBUG] Input: " << input << "\n";
    }

    if (args.options.count("--output")) {
        std::ofstream file(args.options["--output"]);
        file << result;
    }
    else {
        std::cout << result << "\n";
    }

    return 0;
}