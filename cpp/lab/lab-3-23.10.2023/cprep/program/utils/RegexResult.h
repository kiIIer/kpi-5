#include "string"

#ifndef RESULT_H
#define RESULT_H

struct RegexResult {
    int lineNumber;
    std::string *matchedText; // Will use heap pointers directly
};

#endif // RESULT_H
