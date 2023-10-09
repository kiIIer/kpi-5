#ifndef WORKERMANAGER_EMPLOYEE_H
#define WORKERMANAGER_EMPLOYEE_H

#include <string>
#include "nlohmann/json.hpp"

class Employee {
public:
    Employee(
            int employeeCode,
            std::string fullName,
            int age,
            std::string gender,
            std::string address,
            std::string passportData,
            int jobCode
    );

    Employee(const nlohmann::json &json);

    int getEmployeeCode() const;

    const std::string &getFullName() const;

    int getAge() const;

    const std::string &getGender() const;

    const std::string &getAddress() const;

    const std::string &getPassportData() const;

    int getJobCode() const;

    void setEmployeeCode(int employeeCode);

    void setFullName(const std::string &fullName);

    void setAge(int age);

    void setGender(const std::string &gender);

    void setAddress(const std::string &address);

    void setPassportData(const std::string &passportData);

    void setJobCode(int jobCode);

    nlohmann::json toJson() const;

    std::string toString() const;

private:
    int employeeCode;
    std::string fullName;
    int age;
    std::string gender;
    std::string address;
    std::string passportData;
    int jobCode;

};


#endif //WORKERMANAGER_EMPLOYEE_H
