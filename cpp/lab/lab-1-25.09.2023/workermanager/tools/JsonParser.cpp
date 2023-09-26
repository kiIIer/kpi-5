//
// Created by Michael Molchanov on 26.09.2023.
//

#include <fstream>
#include "JsonParser.h"
#include "fruit/macro.h"
#include <iostream>

const std::string filename = "/Users/killer/proj/KPI/kpi-5/cpp/lab/lab-1-25.09.2023/workermanager/test.json";

std::vector<Employee> JsonParser::readJson() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("File not found: " + filename);
    }

    nlohmann::json jsonArray;
    file >> jsonArray;
    file.close();

    std::vector<Employee> employees;

    for (const auto &item: jsonArray) {
        employees.emplace_back(item);
    }

    return employees;
}

void JsonParser::writeJson(std::vector<Employee> employees, bool to_terminal) {
    nlohmann::json jsonArray;

    for (const Employee &employee: employees) {
        jsonArray.push_back(employee.toJson());
    }

    if (to_terminal) {
        std::cout << jsonArray << std::endl;
    } else {

        std::ofstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file for writing: " + filename);
        }

        file << jsonArray.dump(4);
        file.close();
    }
}

JsonParser::JsonParser() = default;
