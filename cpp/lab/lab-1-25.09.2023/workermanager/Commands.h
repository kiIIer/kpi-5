//
// Created by Michael Molchanov on 26.09.2023.
//

#ifndef WORKERMANAGER_COMMANDS_H
#define WORKERMANAGER_COMMANDS_H


#include "IGetCommand.h"
#include "IAddCommand.h"
#include "IDeleteCommand.h"

class Commands {
public:
    IGetCommand *getCommand;
    IAddCommand *addCommand;
    IDeleteCommand *deleteCommand;

    INJECT(Commands(IGetCommand * getCommand, IAddCommand * addCommand, IDeleteCommand * deleteCommand));
};

fruit::Component<Commands> getCommandsComponent();

#endif //WORKERMANAGER_COMMANDS_H
