//
// Created by Michael Molchanov on 26.09.2023.
//

#ifndef WORKERMANAGER_JSONPARSER_H
#define WORKERMANAGER_JSONPARSER_H

#pragma once

#include "IJsonParser.h"
#include "fruit/macro.h"

class JsonParser : public IJsonParser {
public:
    INJECT(JsonParser());

    std::vector<Employee> readJson() override;

    void writeJson(std::vector<Employee> employees, bool to_terminal) override;
};


#endif //WORKERMANAGER_JSONPARSER_H
