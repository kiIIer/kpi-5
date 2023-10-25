//
// Created by Michael Molchanov on 23.10.2023.
//

#ifndef CPREP_IPROGRAM_H
#define CPREP_IPROGRAM_H

#include "fruit/fruit.h"

class IProgram {
public:
    virtual int run(int argc, char *argv[]) = 0;
};

fruit::Component<IProgram> getIProgramComponent();

#endif //CPREP_IPROGRAM_H
