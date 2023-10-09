//
// Created by Michael Molchanov on 26.09.2023.
//

#include "Commands.h"

Commands::Commands(IGetCommand *getCommand, IAddCommand *addCommand, IDeleteCommand *deleteCommand,
                   IMoveCommand *moveCommand) : getCommand(
        getCommand), addCommand(addCommand), deleteCommand(deleteCommand), moveCommand(moveCommand) {}

fruit::Component<Commands> getCommandsComponent() {
    return fruit::createComponent().install(getIGetCommandComponent).install(getIAddCommandComponent).install(
            getIDeleteCommandComponent).install(getIMoveCommandComponent);
}
