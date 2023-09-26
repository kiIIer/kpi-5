//
// Created by Michael Molchanov on 26.09.2023.
//

#ifndef WORKERMANAGER_ADDCOMMAND_H
#define WORKERMANAGER_ADDCOMMAND_H


#include "IAddCommand.h"
#include "../../tools/IJsonParser.h"

class AddCommand : public IAddCommand {
private:
    IJsonParser *parser;
public:
    void add(Employee *employee) override;

    INJECT(AddCommand(IJsonParser * parser));
};


#endif //WORKERMANAGER_ADDCOMMAND_H
