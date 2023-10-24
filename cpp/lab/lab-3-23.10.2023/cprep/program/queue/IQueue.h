//
// Created by Michael Molchanov on 24.10.2023.
//

#ifndef CPREP_IQUEUE_H
#define CPREP_IQUEUE_H


template<typename T>
class IQueue {
public:
    virtual void push(T value) = 0;

    virtual bool pop(T &value) = 0;

    virtual void terminate() = 0;
};


#endif //CPREP_IQUEUE_H
