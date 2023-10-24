//
// Created by Michael Molchanov on 24.10.2023.
//

#ifndef CPREP_IRESULTEXPORTER_H
#define CPREP_IRESULTEXPORTER_H


#include <vector>
#include "../utils/Result.h"

class IResultExporter {

public:
    virtual void exportResults(std::__1::vector<Result> results) = 0;
};


#endif //CPREP_IRESULTEXPORTER_H
