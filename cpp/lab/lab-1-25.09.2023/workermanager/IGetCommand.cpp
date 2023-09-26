//
// Created by Michael Molchanov on 26.09.2023.
//

#include "IGetCommand.h"
#include "fruit/fruit.h"
#include "GetCommand.h"

fruit::Component<IGetCommand> getIGetCommandComponent() {
    return fruit::createComponent().install(getIJsonParserComponent)
            .bind<IGetCommand, GetCommand>();
}
