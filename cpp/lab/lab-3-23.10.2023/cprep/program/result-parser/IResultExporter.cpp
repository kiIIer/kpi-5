//
// Created by Michael Molchanov on 24.10.2023.
//

#include "IResultExporter.h"
#include "ResultExporter.h"

fruit::Component<IResultExporter> getIResultExporterComponent(){
    return fruit::createComponent().bind<IResultExporter, ResultExporter>();
};
