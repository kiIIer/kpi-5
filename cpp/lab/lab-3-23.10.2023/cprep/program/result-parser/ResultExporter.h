//
// Created by Michael Molchanov on 24.10.2023.
//

#ifndef CPREP_RESULTEXPORTER_H
#define CPREP_RESULTEXPORTER_H


#include "IResultExporter.h"

class ResultExporter : public IResultExporter {
public:
    INJECT(ResultExporter());

    void exportResults(std::vector<Result> results, Options *options) override;
};


#endif //CPREP_RESULTEXPORTER_H
