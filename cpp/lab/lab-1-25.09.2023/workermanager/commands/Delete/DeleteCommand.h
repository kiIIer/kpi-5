//
// Created by Michael Molchanov on 26.09.2023.
//

#ifndef WORKERMANAGER_DELETECOMMAND_H
#define WORKERMANAGER_DELETECOMMAND_H


#include "IDeleteCommand.h"
#include "../../tools/IJsonParser.h"

class DeleteCommand : public IDeleteCommand {
private:
    IJsonParser *parser;
public:
    void remove(Employee *example) override;
    void removeAll() override;

    INJECT(DeleteCommand(IJsonParser * parser));
};


#endif //WORKERMANAGER_DELETECOMMAND_H
