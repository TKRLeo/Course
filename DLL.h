//
// Created by Lev on 12.12.2023.
//

#ifndef COURSEPRJ_DLL_H
#define COURSEPRJ_DLL_H


#include <iostream>

template <typename T>
class DLList {
private:
    struct Node{
        T val;
        Node* next;
        Node* prev;

        Node() {
            next = nullptr;
            prev = nullptr;
        }
        Node(T value) {
            this->val = value;
            next = nullptr;
            prev = nullptr;
        }
    };
    Node* head;
    Node* tail;
public:

    void push_back(T value) {
        Node *node = new Node(value);
        if (head == nullptr) {
            head = node;
            tail = node;

            return;
        }
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    bool empty() {
        return head == nullptr;
    }

    void push_front(T value) {
        Node* node = new Node(value);
        if (head == nullptr) {
            head = node;
            tail = node;
            return;
        }
        node->next = head;
        head->prev = node;
        head = node;
    }

    void pop_front() {
        Node* ptr = head;
        head = head->next;
        head->prev = nullptr;
        free(ptr);
    }

    void pop_back() {
        if (this->empty()) return;
        if (head == tail) {
            free(tail);
            return;
        }

        tail->prev->next = nullptr;
        free(tail);
    }

    DLList() {
        head = nullptr;
        tail = nullptr;
    }

    void print() {
        Node *curr = head;

        while (curr) {
            std::cout << curr->val << ' ';
            curr = curr->next;
        }
    }

    Node* first() {
        return head;
    }

    Node* last() {
        return tail;
    }

};


#endif //COURSEPRJ_DLL_H
