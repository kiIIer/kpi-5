//
// Created by Michael Molchanov on 24.10.2023.
//

#ifndef CPREP_IQUEUEFACTORY_H
#define CPREP_IQUEUEFACTORY_H

#include <memory>
#include "IQueue.h"
#include "../utils/RegexResult.h"
#include "../utils/RegexTask.h"
#include "fruit/component.h"

class IQueueFactory {
public:
    virtual std::unique_ptr<IQueue<RegexTask>> createTask() = 0;

    virtual std::unique_ptr<IQueue<RegexResult>> createResult() = 0;
};

fruit::Component<IQueueFactory> getIQueueFactoryComponent();

#endif //CPREP_IQUEUEFACTORY_H
