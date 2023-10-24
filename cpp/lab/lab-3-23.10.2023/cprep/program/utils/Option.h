#include <string>
#include "thread"

struct Options {
    bool ignoreCase = false;
    bool invertMatch = false;
    std::string pattern;
    std::string patternFile;
    int afterContext = 0;
    int beforeContext = 0;
    int context = 0;
    bool showLineNumber = false;
    unsigned int threads = std::thread::hardware_concurrency(); // default to the number of CPU cores
};