#ifndef CLI_H
#define CLI_H

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

struct ParsedArgs {
    std::string command;
    std::vector<std::string> positional;
    std::unordered_map<std::string, std::string> options;
    std::unordered_set<std::string> flags; // boolean flags
};

// Config for allowed options
struct OptionSpec {
    std::string longName;
    std::string shortName;
    bool requiresValue;
};

ParsedArgs parseArgs(
    int argc,
    char* argv[],
    const std::vector<OptionSpec>& specs,
    bool& success
);

std::string join(const std::vector<std::string>& vec);

#endif