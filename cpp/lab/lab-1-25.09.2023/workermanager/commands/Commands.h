//
// Created by Michael Molchanov on 26.09.2023.
//

#ifndef WORKERMANAGER_COMMANDS_H
#define WORKERMANAGER_COMMANDS_H


#include "Get/IGetCommand.h"
#include "Add/IAddCommand.h"
#include "Delete/IDeleteCommand.h"
#include "Move/IMoveCommand.h"

class Commands {
public:
    IGetCommand *getCommand;
    IAddCommand *addCommand;
    IDeleteCommand *deleteCommand;
    IMoveCommand *moveCommand;

    INJECT(Commands(IGetCommand * getCommand, IAddCommand * addCommand, IDeleteCommand * deleteCommand,
                    IMoveCommand * moveCommand));
};

fruit::Component<Commands> getCommandsComponent();

#endif //WORKERMANAGER_COMMANDS_H
