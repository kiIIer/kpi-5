#include "IAddCommand.h"
#include "../../tools/IJsonParser.h"
#include "AddCommand.h"

fruit::Component<IAddCommand> getIAddCommandComponent() {
    return fruit::createComponent().install(getIJsonParserComponent).bind<IAddCommand, AddCommand>();
}

