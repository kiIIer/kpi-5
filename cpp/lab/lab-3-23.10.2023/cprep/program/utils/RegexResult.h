#include "string"

#ifndef RESULT_H
#define RESULT_H

struct RegexResult {
    int lineNumber;
    std::string *matchedText;
};

#endif // RESULT_H
