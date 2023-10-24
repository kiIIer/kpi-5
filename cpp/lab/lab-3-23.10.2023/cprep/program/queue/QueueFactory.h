//
// Created by Michael Molchanov on 24.10.2023.
//

#ifndef CPREP_QUEUEFACTORY_H
#define CPREP_QUEUEFACTORY_H


#include "IQueueFactory.h"
#include "fruit/macro.h"

class QueueFactory : public IQueueFactory {
public:
    INJECT (QueueFactory());

    std::unique_ptr<IQueue<Task>> createTask() override;

    std::unique_ptr<IQueue<Result>> createResult() override;
};


#endif //CPREP_QUEUEFACTORY_H
