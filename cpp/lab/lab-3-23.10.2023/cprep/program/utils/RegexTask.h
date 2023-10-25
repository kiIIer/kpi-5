#include <string>
#include "UserOptions.h"

#ifndef TASK_H
#define TASK_H


struct RegexTask {
    int lineNumber;
    std::string *lineText;
    UserOptions *userOptions;
};

#endif // TASK_H
