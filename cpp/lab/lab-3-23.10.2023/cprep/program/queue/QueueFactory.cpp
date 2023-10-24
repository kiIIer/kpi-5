//
// Created by Michael Molchanov on 24.10.2023.
//

#include "QueueFactory.h"
#include "Queue.h"

std::unique_ptr<IQueue<Task>> QueueFactory::createTask() {
    return std::make_unique<Queue<Task>>();
}

std::unique_ptr<IQueue<Result>> QueueFactory::createResult() {
    return std::make_unique<Queue<Result>>();
}

QueueFactory::QueueFactory() {

}
