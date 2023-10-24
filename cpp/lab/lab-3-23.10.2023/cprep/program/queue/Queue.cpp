//
// Created by Michael Molchanov on 24.10.2023.
//

#include "Queue.h"
#include "../utils/Task.h"

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
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [this]() { return !data.empty() || terminate; });

    if (terminate && data.empty()) {
        return false;
    }

    item = data.front();
    data.pop();
    return true;
}

template<typename T>
void Queue<T>::shouldTerminate() {
    std::unique_lock<std::mutex> lock(mtx);
    terminate = true;
    cv.notify_all();
}