//
// Created by Michael Molchanov on 09.10.2023.
//

#ifndef WORKERMANAGER_MOVECOMMAND_H
#define WORKERMANAGER_MOVECOMMAND_H


#include "IMoveCommand.h"
#include "../../tools/IJsonParser.h"

class MoveCommand : public IMoveCommand {
private:
    IJsonParser *parser;
public:
    INJECT(MoveCommand(IJsonParser * parser));


    void move(Employee example, std::string newPlace) override;
};


#endif //WORKERMANAGER_MOVECOMMAND_H
