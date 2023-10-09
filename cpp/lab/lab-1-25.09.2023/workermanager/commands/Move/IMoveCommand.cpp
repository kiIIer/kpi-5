//
// Created by Michael Molchanov on 09.10.2023.
//

#include "IMoveCommand.h"
#include "../../tools/IJsonParser.h"
#include "MoveCommand.h"

fruit::Component<IMoveCommand> getIMoveCommandComponent() {
    return fruit::createComponent().install(getIJsonParserComponent).bind<IMoveCommand, MoveCommand>();
}

