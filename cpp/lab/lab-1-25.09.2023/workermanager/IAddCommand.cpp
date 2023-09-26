#include "IAddCommand.h"
#include "IJsonParser.h"
#include "AddCommand.h"

fruit::Component<IAddCommand> getIAddCommandComponent() {
    return fruit::createComponent().install(getIJsonParserComponent).bind<IAddCommand, AddCommand>();
}

