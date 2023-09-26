//
// Created by Michael Molchanov on 26.09.2023.
//

#include "AddCommand.h"

AddCommand::AddCommand(IJsonParser *parser) : parser(parser) {}

void AddCommand::add(Employee *employee) {
    std::vector<Employee> employees = parser->readJson();

    employees.push_back(*employee);

    parser->writeJson(employees, false);

    std::vector<Employee> newOne;
    newOne.push_back(*employee);
    parser->writeJson(newOne, true);
}
