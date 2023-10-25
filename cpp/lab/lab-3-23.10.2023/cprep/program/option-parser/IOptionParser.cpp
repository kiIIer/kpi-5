//
// Created by Michael Molchanov on 24.10.2023.
//

#include "IOptionParser.h"
#include "OptionParser.h"
#include "fruit/fruit.h"

fruit::Component<IOptionParser> getIOptionParserComponent() {
    return fruit::createComponent().bind<IOptionParser, OptionParser>();
};
