//
// Created by Michael Molchanov on 24.10.2023.
//

#include <iostream>
#include "Queue.h"
#include "../utils/RegexTask.h"
#include "../utils/RegexResult.h"

template<typename T>
void Queue<T>::push(const T &item) {
    {
        std::lock_guard<std::mutex> lock(mtx);
        data.push(item);
    }
    cv.notify_one();
}

template<typename T>
bool Queue<T>::pop(T &item) {
    std::cerr << "Queue locking" << std::endl;
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [this]() { return !data.empty() || terminate; });

    if (terminate && data.empty()) {
        std::cerr << "Queue returning false" << std::endl;
        return false;
    }

    item = data.front();
    data.pop();
    std::cerr << "Queue returning true" << std::endl;
    return true;
}

template<typename T>
void Queue<T>::shouldTerminate() {
    std::cerr << "Queue terminating" << std::endl;
    std::unique_lock<std::mutex> lock(mtx);
    terminate = true;
    cv.notify_all();
}

template class Queue<RegexResult>;
template class Queue<RegexTask>;