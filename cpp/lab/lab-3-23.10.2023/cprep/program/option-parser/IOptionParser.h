//
// Created by Michael Molchanov on 24.10.2023.
//

#ifndef CPREP_IOPTIONPARSER_H
#define CPREP_IOPTIONPARSER_H


#include "../utils/Option.h"

class IOptionParser {

public:
    virtual Options *parse(int i, char **args) = 0;
};


#endif //CPREP_IOPTIONPARSER_H
