//
// Created by Michael Molchanov on 26.09.2023.
//

#ifndef WORKERMANAGER_IJSONPARSER_H
#define WORKERMANAGER_IJSONPARSER_H


#include "Employee.h"
#include "fruit/macro.h"

class IJsonParser {
public:
    virtual ~IJsonParser() = default;

    virtual std::vector<Employee> readJson() = 0;

    virtual void writeJson(std::vector<Employee> employees, bool to_terminal) = 0;

    INJECT(IJsonParser()) = default;
};

fruit::Component<IJsonParser> getIJsonParserComponent();

#endif //WORKERMANAGER_IJSONPARSER_H
