//
// Created by Michael Molchanov on 24.10.2023.
//

#ifndef CPREP_IRESULTEXPORTER_H
#define CPREP_IRESULTEXPORTER_H


#include <vector>
#include "../utils/Result.h"
#include "../utils/Options.h"
#include "fruit/fruit.h"

class IResultExporter {

public:
    virtual void exportResults(std::vector<Result> results, Options *options) = 0;
};

fruit::Component<IResultExporter> getIResultExporterComponent();


#endif //CPREP_IRESULTEXPORTER_H
