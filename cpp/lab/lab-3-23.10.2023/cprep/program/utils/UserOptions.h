#include <string>
#include "thread"

#ifndef USER_OPTIONS_H
#define USER_OPTIONS_H


struct UserOptions {
public:
    bool ignoreCase = false;   // -i
    bool invertMatch = false;  // -v
    std::vector<std::string> patterns;  // -e (multiple allowed)
    bool showLineNumber = false;  // -n
    int threads = 1;           // --threads
    std::optional<std::string> inputFile;  // If provided, read from this file, else stdin
    std::string log_file = "/dev/null";
};

#endif // USER_OPTIONS_H
