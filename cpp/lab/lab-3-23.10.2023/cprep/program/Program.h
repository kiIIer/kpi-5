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
#include "utils/RegexTask.h"
#include "utils/RegexResult.h"
#include "queue/IQueue.h"

class Program : public IProgram {
private:
    IOptionParser *optionParser;
    IWorker *worker;
    IResultExporter *exporter;
    std::unique_ptr<IQueue<RegexTask>> taskQueue;
    std::unique_ptr<IQueue<RegexResult>> resultQueue;

    void distributeTasks(UserOptions *userOptions);

    std::vector<RegexResult> gatherResultsFromAllWorkers();

public:
    INJECT(Program(IOptionParser * optionParser, IWorker * worker, IResultExporter * exporter,
                   IQueueFactory * queueFactory));

    int run(int argc, char *argv[]) override;
};


#endif //CPREP_PROGRAM_H
