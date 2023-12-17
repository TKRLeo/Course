//
// Created by Lev on 10.12.2023.
//
#ifndef COURSEPRJ_VECTOR_H
#define COURSEPRJ_VECTOR_H

#include <cstdlib>
template<typename T>
class Vector {
private:
    T* arr;
    size_t sz;
    size_t cap;
public:
    Vector() {
        sz = 0;
        cap = 0;
    }
    Vector(size_t sz) {
        this->arr = new T[sz];
        this->sz = 0;
        this->cap = 0;
    }
    Vector(size_t sz, T value) {
        this->arr = new T[sz];
        for(size_t i = 0; i < sz; ++i) {
            this->arr[i] = value;
        }

        this->sz = sz;
        this->cap = sz;
    }
    ~Vector() {
        delete []this->arr;
    }

    T operator[](size_t i) {
        return this->arr[i];
    }

    void operator=(Vector<T>& v) {
        for (size_t i = 0; i < this->capacity() && i < v.size(); ++i) {
            this->arr[i] = v[i];
        }
        this->sz = this->cap;
    }

    size_t empty() {
        return this->sz == 0;
    }

    void erase(size_t pos) {
        if (pos == 0 || pos > this->sz) return;

        for (size_t i = pos; i < this->sz; ++i) {
            this->arr[i - 1] = this->arr[i];
        }
        this->sz--;
    }

    void push_back( T value) {
        if(this->sz == this->cap) {
            this->resize(this->cap * 2);
        }
        if (this->sz == 0 && this->capacity() == 0) {
            this->arr = new T[1];
            this->cap++;
        }


        this->arr[this->sz++] = value;

    }

    size_t size() {
        return this->sz;
    }
    size_t capacity() {
        return this->cap;
    }

    void resize(size_t size) {
        if (this->sz >= size) {
            this->sz = size;
            return;
        }
        Vector<T> temp;
        temp.arr = new T[this->sz];
        for (size_t i = 0; i < this->sz; ++i) {
            temp.arr[i] = this->arr[i];
        }
        delete []this->arr;

        this->arr = new T[size];
        for (size_t i = 0; i < this->size(); ++i) {
            this->arr[i] = temp[i];
        }
        this->cap *=2;
        delete []temp.arr;
    }

    void insert(size_t pos, T value) {
        if (this->capacity() == 0 && this->size() == 0) {
            push_back(value);
            return;
        }
        if (this->capacity() <= this->size()) this->resize(2 * this->cap);

        for (size_t i = this->size() - 1; i >= pos; --i) {
            this->arr[i + 1] = this->arr[i];
        }
        this->arr[pos - 1] = value;
        this->sz++;
    }
    void pop_back() {
        if (this->size() == 0) return;
        this->sz--;
    }

    T& back() {
        return this->arr[this->size() - 1];
    }

};


#endif //COURSEPRJ_VECTOR_H
