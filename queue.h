//
// Created by Lev on 12.12.2023.
//

#ifndef COURSEPRJ_QUEUE_H
#define COURSEPRJ_QUEUE_H

#include <cstdio>
#include "OLL.h"

template <typename T>
class Queue{
    List<T> l;
    size_t sz = 0;

    void pop() {
        --sz;
        l.pop_front();
    }

    void push(T value) {
        ++sz;
        l.push_back(value);
    }

    T& front() {
        return l.first()->val;
    }

    size_t size() {
        return sz;
    }

    bool empty() {
        return l.empty();
    }

    T& back() {
        return l.tail()->val;
    }

    };

#endif //COURSEPRJ_QUEUE_H
