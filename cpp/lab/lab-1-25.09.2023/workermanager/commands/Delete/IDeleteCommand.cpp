//
// Created by Michael Molchanov on 26.09.2023.
//

#include "IDeleteCommand.h"
#include "../../tools/IJsonParser.h"
#include "DeleteCommand.h"

fruit::Component<IDeleteCommand> getIDeleteCommandComponent() {
    return fruit::createComponent().install(getIJsonParserComponent).bind<IDeleteCommand, DeleteCommand>();
}
