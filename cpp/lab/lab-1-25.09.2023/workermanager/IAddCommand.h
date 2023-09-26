//
// Created by Michael Molchanov on 26.09.2023.
//

#ifndef WORKERMANAGER_IADDCOMMAND_H
#define WORKERMANAGER_IADDCOMMAND_H


#include "Employee.h"
#include "fruit/fruit.h"

class IAddCommand {
public:
    virtual void add(Employee *employee) = 0;
};

fruit::Component<IAddCommand> getIAddCommandComponent();

#endif //WORKERMANAGER_IADDCOMMAND_H
