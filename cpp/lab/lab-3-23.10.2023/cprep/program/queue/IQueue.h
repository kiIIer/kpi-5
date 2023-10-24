//
// Created by Michael Molchanov on 24.10.2023.
//

#ifndef CPREP_IQUEUE_H
#define CPREP_IQUEUE_H


template<typename T>
class IQueue {
public:
    // Push an item onto the queue
    virtual void push(const T& item) = 0;

    // Try to pop an item from the queue. Returns false if the queue is empty.
    virtual bool pop(T& item) = 0;

    // Check if the queue is empty
    virtual void shouldTerminate() const = 0;
};


#endif //CPREP_IQUEUE_H
