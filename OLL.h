//
// Created by Lev on 11.12.2023.
//

#ifndef COURSEPRJ_OLL_H
#define COURSEPRJ_OLL_H

template <typename T>
class List {
private:
    struct Node{
        T val;
        struct Node* next;

        Node() {
            next = nullptr;
        }
        explicit Node(T value) {
            this->val = value;
            next = nullptr;
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
        head = node;
    }

    void pop_front() {
        Node* ptr = head;
        head = head->next;
        free(ptr);
    }

    void pop_back() {
        if (this->empty()) return;
        Node *curr = head;
        if (curr == tail) {
            free(tail);
            return;
        }

        while (curr->next != tail)
            curr = curr->next;

        Node* ptr = tail;
        tail = curr;
        tail->next = nullptr;

        free(ptr);
    }

    List() {
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
#endif //COURSEPRJ_OLL_H
