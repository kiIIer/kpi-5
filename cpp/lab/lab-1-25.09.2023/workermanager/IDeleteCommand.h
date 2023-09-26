//
// Created by Michael Molchanov on 26.09.2023.
//

#ifndef WORKERMANAGER_IDELETECOMMAND_H
#define WORKERMANAGER_IDELETECOMMAND_H


#include "Employee.h"
#include "fruit/fruit.h"

class IDeleteCommand {
public:
    virtual void remove(Employee *example) = 0;
    virtual void removeAll() =0;
};

fruit::Component<IDeleteCommand> getIDeleteCommandComponent();

#endif //WORKERMANAGER_IDELETECOMMAND_H
