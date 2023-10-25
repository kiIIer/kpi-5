//
// Created by Michael Molchanov on 24.10.2023.
//

#ifndef CPREP_OPTIONPARSER_H
#define CPREP_OPTIONPARSER_H

#include "IOptionParser.h"
#include "fruit/macro.h"

class OptionParser : public IOptionParser {
public:
    INJECT(OptionParser());

    std::unique_ptr<UserOptions> parse(CLI::App &app) override;
};


#endif //CPREP_OPTIONPARSER_H
