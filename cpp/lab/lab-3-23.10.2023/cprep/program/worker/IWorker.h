//
// Created by Michael Molchanov on 24.10.2023.
//

#ifndef CPREP_IWORKER_H
#define CPREP_IWORKER_H


#include "../queue/IQueue.h"
#include "../utils/RegexTask.h"
#include "../utils/RegexResult.h"
#include "fruit/component.h"

class IWorker {

public:
    virtual void work(IQueue<RegexTask> *taskQueue, IQueue<RegexResult> *resultQueue, UserOptions *options) = 0;
};

fruit::Component<IWorker> getIWorkerComponent();


#endif //CPREP_IWORKER_H
