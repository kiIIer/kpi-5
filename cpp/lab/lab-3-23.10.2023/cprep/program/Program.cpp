//
// Created by Michael Molchanov on 24.10.2023.
//

#include "Program.h"

Program::Program(IOptionParser* optionParser, IWorker* worker, IResultExporter* exporter, IQueueFactory* queueFactory)
: optionParser(optionParser), worker(worker), exporter(exporter) {
    taskQueue = queueFactory->create<Task>();
    resultQueue = queueFactory->create<Result>();
}

void Program::distributeTasks(Options *userOptions) {

}
