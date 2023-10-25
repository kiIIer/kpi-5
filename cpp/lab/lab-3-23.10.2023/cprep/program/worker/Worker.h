//
// Created by Michael Molchanov on 24.10.2023.
//

#ifndef CPREP_WORKER_H
#define CPREP_WORKER_H

#include <regex>
#include "IWorker.h"
#include "fruit/macro.h"

class Worker : public IWorker {
public:
    virtual void work(IQueue<RegexTask> *taskQueue, IQueue<RegexResult> *resultQueue, UserOptions *options) override;

    INJECT(Worker());

private:
    bool matchesPattern(const std::string &line, const std::vector<std::regex> &compiledPatterns);
};


#endif //CPREP_WORKER_H
