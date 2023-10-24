#include "string"

struct Result {
    int lineNumber;
    std::string *matchedText; // Will use heap pointers directly
};