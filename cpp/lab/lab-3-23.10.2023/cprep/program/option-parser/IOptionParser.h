//
// Created by Michael Molchanov on 24.10.2023.
//

#ifndef CPREP_IOPTIONPARSER_H
#define CPREP_IOPTIONPARSER_H


#include "../utils/Options.h"
#include "CLI11.hpp"
#include "fruit/component.h"

class IOptionParser {

public:
    virtual std::unique_ptr<Options> parse(CLI::App &app) = 0;
};

fruit::Component<IOptionParser> getIOptionParserComponent();

#endif //CPREP_IOPTIONPARSER_H
