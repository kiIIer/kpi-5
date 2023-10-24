//
// Created by Michael Molchanov on 24.10.2023.
//

#ifndef CPREP_QUEUE_H
#define CPREP_QUEUE_H


#include <mutex>
#include <condition_variable>
#include <queue>
#include "IQueue.h"

template<typename T>
class Queue : public IQueue<T> {
public:
    void push(const T &item) override;

    bool pop(T &item) override;

    void shouldTerminate() override;

private:
    mutable std::mutex mtx;
    std::condition_variable cv;
    std::queue<T> data;
    bool terminate = false;
};
};


#endif //CPREP_QUEUE_H
