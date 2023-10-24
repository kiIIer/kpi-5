#include <string>
#include "Options.h"

struct Task {
    int lineNumber;
    std::string *lineText;
    Options *userOptions;
};
