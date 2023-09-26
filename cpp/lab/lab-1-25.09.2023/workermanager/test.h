//
// Created by Michael Molchanov on 26.09.2023.
//

#ifndef WORKERMANAGER_TEST_H
#define WORKERMANAGER_TEST_H


#include "IJsonParser.h"
#include "fruit/macro.h"

class test {
private:
    IJsonParser *jsonParser;

public:
    INJECT(test(IJsonParser *jsonParser));
};


#endif //WORKERMANAGER_TEST_H
