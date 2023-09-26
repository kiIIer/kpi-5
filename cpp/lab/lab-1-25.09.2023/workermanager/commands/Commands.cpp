//
// Created by Michael Molchanov on 26.09.2023.
//

#include "Commands.h"

Commands::Commands(IGetCommand *getCommand, IAddCommand *addCommand, IDeleteCommand *deleteCommand) : getCommand(
        getCommand), addCommand(addCommand), deleteCommand(deleteCommand) {}

fruit::Component<Commands> getCommandsComponent() {
    return fruit::createComponent().install(getIGetCommandComponent).install(getIAddCommandComponent).install(
            getIDeleteCommandComponent);
}
