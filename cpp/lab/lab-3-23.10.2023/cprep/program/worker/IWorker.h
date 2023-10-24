//
// Created by Michael Molchanov on 24.10.2023.
//

#ifndef CPREP_IWORKER_H
#define CPREP_IWORKER_H


#include "../queue/IQueue.h"
#include "../utils/Task.h"
#include "../utils/Result.h"
#include "fruit/component.h"

class IWorker {

public:
    virtual void work(IQueue<Task> *taskQueue, IQueue<Result> *resultQueue, Options *options) = 0;
};

fruit::Component<IWorker> getIWorkerComponent();


#endif //CPREP_IWORKER_H
