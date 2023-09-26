//
// Created by Michael Molchanov on 26.09.2023.
//

#include <iostream>
#include "GetCommand.h"

GetCommand::GetCommand(IJsonParser *parser) : parser(parser) {

}

void GetCommand::getAll() {
    std::vector<Employee> employees = this->parser->readJson();

    this->parser->writeJson(employees, true);
}

void GetCommand::getSearch(Employee example) {
    std::vector<Employee> employees = this->parser->readJson();
    std::vector<Employee> filtered;

    for (const Employee &employee: employees) {
        if ((example.getEmployeeCode() == 0 || employee.getEmployeeCode() == example.getEmployeeCode()) &&
            (example.getFullName().empty() || employee.getFullName() == example.getFullName()) &&
            (example.getAge() == 0 || employee.getAge() == example.getAge()) &&
            (example.getGender().empty() || employee.getGender() == example.getGender()) &&
            (example.getAddress().empty() || employee.getAddress() == example.getAddress()) &&
            (example.getPassportData().empty() || employee.getPassportData() == example.getPassportData()) &&
            (example.getJobCode() == 0 || employee.getJobCode() == example.getJobCode())) {
            // Add the employee to the filtered result
            filtered.push_back(employee);
        }
    }

    this->parser->writeJson(filtered, true);
}
