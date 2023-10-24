//
// Created by Michael Molchanov on 24.10.2023.
//

#ifndef CPREP_IQUEUEFACTORY_H
#define CPREP_IQUEUEFACTORY_H

#include <memory>
#include "IQueue.h"
#include "../utils/Result.h"
#include "../utils/Task.h"

class IQueueFactory {
public:
    virtual std::unique_ptr<IQueue<Task>> create_task() = 0;

    virtual std::unique_ptr<IQueue<Result>> create_result() = 0;
};


#endif //CPREP_IQUEUEFACTORY_H
