//
// Created by Michael Molchanov on 24.10.2023.
//

#ifndef CPREP_IQUEUE_H
#define CPREP_IQUEUE_H


template<typename T>
class IQueue {
public:
    virtual void push(const T &item) = 0;

    virtual bool pop(T &item) = 0;

    virtual void shouldTerminate() = 0;

    virtual ~IQueue() = default;
};


#endif //CPREP_IQUEUE_H
