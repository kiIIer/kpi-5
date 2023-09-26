//
// Created by Michael Molchanov on 26.09.2023.
//

#ifndef WORKERMANAGER_GETCOMMAND_H
#define WORKERMANAGER_GETCOMMAND_H


#include "IGetCommand.h"
#include "fruit/macro.h"
#include "IJsonParser.h"

class GetCommand : public IGetCommand {
private:
    IJsonParser *parser;
public:
    INJECT(GetCommand(IJsonParser * parser));

    void getAll() override;

    void getSearch(Employee example) override;
};


#endif //WORKERMANAGER_GETCOMMAND_H
