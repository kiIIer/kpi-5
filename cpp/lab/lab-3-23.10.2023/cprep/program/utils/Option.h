#include <string>
#include "thread"

struct Options {
    bool ignoreCase = false;   // -i
    bool invertMatch = false;  // -v
    std::vector<std::string> patterns;  // -e (multiple allowed)
    std::string patternFile;   // -f
    int afterContext = 0;      // -A
    int beforeContext = 0;     // -B
    int context = 0;           // -C
    bool showLineNumber = false;  // -n
    int threads = 1;           // --threads
    std::optional<std::string> inputFile;  // If provided, read from this file, else stdin
};