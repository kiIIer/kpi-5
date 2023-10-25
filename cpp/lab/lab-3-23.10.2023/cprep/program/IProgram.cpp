//
// Created by Michael Molchanov on 23.10.2023.
//

#include "IProgram.h"
#include "option-parser/IOptionParser.h"
#include "worker/IWorker.h"
#include "result-parser/IResultExporter.h"
#include "queue/IQueueFactory.h"
#include "Program.h"

fruit::Component<IProgram> getIProgramComponent() {
    return fruit::createComponent().install(getIOptionParserComponent).install(getIWorkerComponent).install(
            getIResultExporterComponent).install(
            getIQueueFactoryComponent).bind<IProgram, Program>();
};

