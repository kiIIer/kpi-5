//
// Created by Michael Molchanov on 09.10.2023.
//

#include "MoveCommand.h"

MoveCommand::MoveCommand(IJsonParser *parser) : parser(parser) {}

void MoveCommand::move(Employee example, std::string newPlace) {
    std::vector<Employee> employees = this->parser->readJson();
    std::vector<Employee> updatedEmployees;

    for (Employee &employee : employees) {
        // Check if the employee matches the criteria for updating the address
        if ((example.getEmployeeCode() == 0 || employee.getEmployeeCode() == example.getEmployeeCode()) &&
            (example.getFullName().empty() || employee.getFullName() == example.getFullName()) &&
            (example.getAge() == 0 || employee.getAge() == example.getAge()) &&
            (example.getGender().empty() || employee.getGender() == example.getGender()) &&
            (example.getAddress().empty() || employee.getAddress() == example.getAddress()) &&
            (example.getPassportData().empty() || employee.getPassportData() == example.getPassportData()) &&
            (example.getJobCode() == 0 || employee.getJobCode() == example.getJobCode())) {
            // Update the address for matching employees
            employee.setAddress(newPlace);
        }
        updatedEmployees.push_back(employee);
    }

    this->parser->writeJson(updatedEmployees, false);
}