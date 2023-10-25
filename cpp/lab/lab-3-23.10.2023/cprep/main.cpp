#include <iostream>
#include "program/IProgram.h"

int main(int argc, char **args) {
    fruit::Injector<IProgram> injector(getIProgramComponent);

    IProgram *program = injector.get<IProgram *>();

    return program->run(argc, args);
}
