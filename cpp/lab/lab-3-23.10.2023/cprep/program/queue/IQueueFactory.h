//
// Created by Michael Molchanov on 24.10.2023.
//

#ifndef CPREP_IQUEUEFACTORY_H
#define CPREP_IQUEUEFACTORY_H

#include <memory>
#include "IQueue.h"

template<typename T>
class IQueueFactory {
public:
    virtual std::unique_ptr<IQueue<T>> create() = 0;
};


#endif //CPREP_IQUEUEFACTORY_H
