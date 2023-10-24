#include <string>
#include "Option.h"

struct Task {
    int lineNumber;
    std::string* lineText;
    Options* userOptions;
};
