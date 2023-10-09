//
// Created by Michael Molchanov on 09.10.2023.
//

#ifndef WORKERMANAGER_IMOVECOMMAND_H
#define WORKERMANAGER_IMOVECOMMAND_H


#include "../../entities/Employee.h"
#include "fruit/component.h"

class IMoveCommand {
public:
    virtual void move(Employee example, std::string newPlace) = 0;
};

fruit::Component<IMoveCommand> getIMoveCommandComponent();


#endif //WORKERMANAGER_IMOVECOMMAND_H
