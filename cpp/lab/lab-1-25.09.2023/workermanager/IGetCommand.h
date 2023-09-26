//
// Created by Michael Molchanov on 26.09.2023.
//

#ifndef WORKERMANAGER_IGETCOMMAND_H
#define WORKERMANAGER_IGETCOMMAND_H


#include "Employee.h"
#include "fruit/component.h"
#include "IJsonParser.h"

class IGetCommand {
public:
    virtual void getAll() = 0;

    virtual void getSearch(Employee example) = 0;
};

fruit::Component<IGetCommand> getIGetCommandComponent();

#endif //WORKERMANAGER_IGETCOMMAND_H
