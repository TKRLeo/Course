//
// Created by Lev on 10.12.2023.
//

#ifndef COURSEPRJ_STACKVEC_H
#define COURSEPRJ_STACKVEC_H
#include "Vector"

using namespace std;

template <typename T>
class Stack{
private:
    Vector<T> vec;
public:

    Stack() {};
    ~Stack() {};
    void push(T value) {
        vec.push_back(value);
    }

    void pop() {
        if (this->empty()) return;
        vec.pop_back();
    }

    bool empty() {
        return vec.size() == 0;
    }

    T top() {
        return vec.back();
    }

    size_t size() {
        return vec.size();
    }

};
#endif //COURSEPRJ_STACKVEC_H
