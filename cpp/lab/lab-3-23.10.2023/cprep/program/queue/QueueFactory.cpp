//
// Created by Michael Molchanov on 24.10.2023.
//

#include "QueueFactory.h"
#include "Queue.h"

std::unique_ptr<IQueue<RegexTask>> QueueFactory::createTask() {
    return std::make_unique<Queue<RegexTask>>();
}

std::unique_ptr<IQueue<RegexResult>> QueueFactory::createResult() {
    return std::make_unique<Queue<RegexResult>>();
}

QueueFactory::QueueFactory() {

}
