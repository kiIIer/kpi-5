#include <string>
#include "thread"

struct Options {
public:
    bool ignoreCase = false;   // -i
    bool invertMatch = false;  // -v
    std::vector<std::string> patterns;  // -e (multiple allowed)
    bool showLineNumber = false;  // -n
    int threads = 1;           // --threads
    std::optional<std::string> inputFile;  // If provided, read from this file, else stdin
};