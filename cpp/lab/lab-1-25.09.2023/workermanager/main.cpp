#include <iostream>
#include "fruit/fruit.h"
#include "tools/IJsonParser.h"
#include "dep/CLI11.hpp"
#include "commands/Get/IGetCommand.h"
#include "commands/Commands.h"

int main(int argc, char *argv[]) {
    CLI::App app("Employee Management CLI");
    fruit::Injector<Commands> injector(getCommandsComponent);

    Commands *commands = injector.get<Commands *>();

    auto *cmdGet = app.add_subcommand("get", "Gets current employees");
    auto *cmdAdd = app.add_subcommand("add", "Adds new employer");
    auto *cmdDelete = app.add_subcommand("delete", "Deletes employers");
    auto *cmdMove = app.add_subcommand("move", "Moves employer to new address");

    bool isAll{false};
    cmdGet->add_flag("-a", isAll, "Gets all employees");
    cmdDelete->add_flag("-a", isAll, "Deletes ALL employees");

    int employeeCode{0};
    cmdGet->add_option("--code", employeeCode, "Employee Code to be searched for");
    cmdAdd->add_option("--code", employeeCode, "Employee Code of new employee")->required();
    cmdDelete->add_option("--code", employeeCode, "Employee Code of employees to be deleted");
    cmdMove->add_option("--code", employeeCode, "Employee Code of employees to be moved");

    std::string fullName;
    cmdGet->add_option("--name", fullName, "Full name of employee to search for");
    cmdAdd->add_option("--name", fullName, "Full name of new employee")->required();
    cmdDelete->add_option("--name", fullName, "Full name of employees to be deleted");
    cmdMove->add_option("--name", fullName, "Full name of employees to be moved");

    int age{0};
    cmdGet->add_option("--age", age, "Age of employee to search for");
    cmdAdd->add_option("--age", age, "Age of new employee")->required();
    cmdDelete->add_option("--age", age, "Age of employees to be deleted");
    cmdMove->add_option("--age", age, "Age of employees to be moved");

    std::string gender;
    cmdGet->add_option("--gender", gender, "Gender of employee to search for");
    cmdAdd->add_option("--gender", gender, "Gender of new employee")->required();
    cmdDelete->add_option("--gender", gender, "Gender of employees to be deleted");
    cmdMove->add_option("--gender", gender, "Gender of employees to be moved");

    std::string address;
    cmdGet->add_option("--address", address, "Address of employee to search for");
    cmdAdd->add_option("--address", address, "Address of new employee")->required();
    cmdDelete->add_option("--address", address, "Address of employees to be deleted");
    cmdMove->add_option("--address", address, "Address of employees to be moved");

    std::string passportData;
    cmdGet->add_option("--passport", passportData, "Passport data of employee to search for");
    cmdAdd->add_option("--passport", passportData, "Passport data of new employee")->required();
    cmdDelete->add_option("--passport", passportData, "Passport data of employees to be deleted");
    cmdMove->add_option("--passport", passportData, "Passport data of employees to be moved");

    int jobCode{0};
    cmdGet->add_option("--job", jobCode, "Job code of employee to search for");
    cmdAdd->add_option("--job", jobCode, "Job code of new employee")->required();
    cmdDelete->add_option("--job", jobCode, "Job code of employees to be deleted");
    cmdMove->add_option("--job", jobCode, "Job code of employees to be moved");

    std::string newPlace;
    cmdMove->add_option("--new-place", newPlace, "Address of employees to be moved to");

    cmdGet->callback([commands, &isAll, &employeeCode, &fullName, &age, &gender, &address, &passportData, &jobCode]() {
        if (isAll) {
            commands->getCommand->getAll();
            return;
        }

        Employee *example = new Employee(employeeCode, fullName, age, gender, address, passportData, jobCode);
        commands->getCommand->getSearch(*example);
    });

    cmdAdd->callback([commands, &employeeCode, &fullName, &age, &gender, &address, &passportData, &jobCode]() {
        Employee *newEmployee = new Employee(employeeCode, fullName, age, gender, address, passportData, jobCode);

        commands->addCommand->add(newEmployee);
    });

    cmdDelete->callback(
            [commands, &isAll, &employeeCode, &fullName, &age, &gender, &address, &passportData, &jobCode]() {
                if (isAll) {
                    commands->deleteCommand->removeAll();
                    return;
                }
                Employee *example = new Employee(employeeCode, fullName, age, gender, address, passportData, jobCode);
                commands->deleteCommand->remove(example);
            });

    cmdMove->callback(
            [commands, &employeeCode, &fullName, &age, &gender, &address, &passportData, &jobCode, &newPlace]() {
                Employee *example = new Employee(employeeCode, fullName, age, gender, address, passportData, jobCode);
                commands->moveCommand->move(*example, newPlace);
            });

    try {
        app.parse(argc, argv);
    } catch (const CLI::ParseError &e) {
        return app.exit(e);
    }

    return 0;
}
