#include "Employee.h"

#include <utility>

Employee::Employee(
        int employeeCode,
        std::string fullName,
        int age,
        std::string gender,
        std::string address,
        std::string passportData,
        int jobCode
) : employeeCode(employeeCode), fullName(std::move(fullName)), age(age), gender(std::move(gender)),
    address(std::move(address)), passportData(std::move(passportData)), jobCode(jobCode) {}

int Employee::getEmployeeCode() const {
    return employeeCode;
}

const std::string &Employee::getFullName() const {
    return fullName;
}

int Employee::getAge() const {
    return age;
}

const std::string &Employee::getGender() const {
    return gender;
}

const std::string &Employee::getAddress() const {
    return address;
}

const std::string &Employee::getPassportData() const {
    return passportData;
}

int Employee::getJobCode() const {
    return jobCode;
}

void Employee::setEmployeeCode(int employeeCode) {
    Employee::employeeCode = employeeCode;
}

void Employee::setFullName(const std::string &fullName) {
    Employee::fullName = fullName;
}

void Employee::setAge(int age) {
    Employee::age = age;
}

void Employee::setGender(const std::string &gender) {
    Employee::gender = gender;
}

void Employee::setAddress(const std::string &address) {
    Employee::address = address;
}

void Employee::setPassportData(const std::string &passportData) {
    Employee::passportData = passportData;
}

void Employee::setJobCode(int jobCode) {
    Employee::jobCode = jobCode;
}

Employee::Employee(const nlohmann::json &json) {
    employeeCode = json["code"];
    fullName = json["fullName"];
    age = json["age"];
    gender = json["gender"];
    address = json["address"];
    passportData = json["passportData"];
    jobCode = json["jobCode"];
}

nlohmann::json Employee::toJson() const {
    nlohmann::json j;
    j["code"] = employeeCode;
    j["fullName"] = fullName;
    j["age"] = age;
    j["gender"] = gender;
    j["address"] = address;
    j["passportData"] = passportData;
    j["jobCode"] = jobCode;

    return j;
}

std::string Employee::toString() const {
    std::string result = "Employee Code: " + std::to_string(employeeCode) + "\n";
    result += "Full Name: " + fullName + "\n";
    result += "Age: " + std::to_string(age) + "\n";
    result += "Gender: " + gender + "\n";
    result += "Address: " + address + "\n";
    result += "Passport Data: " + passportData + "\n";
    result += "Job Code: " + std::to_string(jobCode) + "\n";

    return result;
}