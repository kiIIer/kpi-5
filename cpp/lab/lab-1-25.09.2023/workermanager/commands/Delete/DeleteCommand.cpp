//
// Created by Michael Molchanov on 26.09.2023.
//

#include "DeleteCommand.h"

DeleteCommand::DeleteCommand(IJsonParser *parser) : parser(parser) {}

void DeleteCommand::remove(Employee *example) {
    std::vector<Employee> employees = this->parser->readJson();
    std::vector<Employee> employeesToKeep;

    for (const Employee &employee: employees) {
        // Check if the employee matches the criteria for removal
        if ((example->getEmployeeCode() == 0 || employee.getEmployeeCode() == example->getEmployeeCode()) &&
            (example->getFullName().empty() || employee.getFullName() == example->getFullName()) &&
            (example->getAge() == 0 || employee.getAge() == example->getAge()) &&
            (example->getGender().empty() || employee.getGender() == example->getGender()) &&
            (example->getAddress().empty() || employee.getAddress() == example->getAddress()) &&
            (example->getPassportData().empty() || employee.getPassportData() == example->getPassportData()) &&
            (example->getJobCode() == 0 || employee.getJobCode() == example->getJobCode())) {
        } else {
            employeesToKeep.push_back(employee);
        }
    }

    this->parser->writeJson(employeesToKeep, false);
}

void DeleteCommand::removeAll() {
    std::vector<Employee> employees;

    this->parser->writeJson(employees, false);
}
