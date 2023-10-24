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
    while (data.empty()) {
        cv.wait(lock);
    }

    // If the line number indicates worker termination, break out without waiting
    if constexpr (std::is_same_v<T, Task>) {
        if (data.front().lineNumber == -1) {
            item = data.front();
            data.pop();
            return true;
        }
    }

    if (data.empty())
        return false;

    item = data.front();
    data.pop();
    return true;
}

template<typename T>
bool Queue<T>::isEmpty() const {
    std::lock_guard<std::mutex> lock(mtx);
    return data.empty();
}