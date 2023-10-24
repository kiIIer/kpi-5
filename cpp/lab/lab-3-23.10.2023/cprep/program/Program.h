//
// Created by Michael Molchanov on 24.10.2023.
//

#ifndef CPREP_PROGRAM_H
#define CPREP_PROGRAM_H


#include "option-parser/IOptionParser.h"
#include "worker/IWorker.h"
#include "result-parser/IResultExporter.h"
#include "queue/IQueueFactory.h"
#include "IProgram.h"
#include "utils/Task.h"
#include "utils/Result.h"
#include "queue/IQueue.h"

class Program {
private:
    IOptionParser *optionParser;
    IWorker *worker;
    IResultExporter *exporter;
    std::unique_ptr<IQueue<Task>> taskQueue;
    std::unique_ptr<IQueue<Result>> resultQueue;

    void readPatternsFromFile(Options *opts);

    void distributeTasks(Options *userOptions);

    std::vector<Result> gatherResultsFromAllWorkers();

public:
    INJECT(Program(IOptionParser * optionParser, IWorker * worker, IResultExporter * exporter,
                   IQueueFactory * queueFactory));

    int run(int argc, char *argv[]);
};


#endif //CPREP_PROGRAM_H
