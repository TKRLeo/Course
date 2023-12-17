//
// Created by Lev on 16.12.2023.
//

#ifndef COURSEPRJ_AVL_H
#define COURSEPRJ_AVL_H
#include <iostream>
#include <algorithm>

// Узел AVL-дерева
template <typename T>
struct AVLNode {
    T data;                       // Значение узла
    AVLNode<T>* left;             // Левое поддерево
    AVLNode<T>* right;            // Правое поддерево
    int height;                   // Высота узла

    AVLNode(T value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

// AVL-дерево
template <typename T>
class AVLTree {
private:
    AVLNode<T>* root;             // Корень дерева

    // Расчет высоты узла
    int getHeight(AVLNode<T>* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    // Расчет разницы высоты поддеревьев
    int getBalanceFactor(AVLNode<T>* node) {
        if (node == nullptr) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    // Обновление высоты узла
    void updateHeight(AVLNode<T>* node) {
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        node->height = 1 + std::max(leftHeight, rightHeight);
    }

    // Малое правое вращение
    AVLNode<T>* rotateRight(AVLNode<T>* node) {
        AVLNode<T>* newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;
        updateHeight(node);
        updateHeight(newRoot);
        return newRoot;
    }

    // Малое левое вращение
    AVLNode<T>* rotateLeft(AVLNode<T>* node) {
        AVLNode<T>* newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;
        updateHeight(node);
        updateHeight(newRoot);
        return newRoot;
    }

    // Балансировка узла
    AVLNode<T>* balanceNode(AVLNode<T>* node) {
        updateHeight(node);
        int balanceFactor = getBalanceFactor(node);

        // Лево-левое вращение
        if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0) {
            return rotateRight(node);
        }

        // Лево-правое вращение
        if (balanceFactor > 1 && getBalanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Право-правое вращение
        if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0) {
            return rotateLeft(node);
        }

        // Право-левое вращение
        if (balanceFactor < -1 && getBalanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    // Вставка значения в дерево
    AVLNode<T>* insertValue(AVLNode<T>* node, T value) {
        if (node == nullptr) {
            return new AVLNode<T>(value);
        }

        if (value < node->data) {
            node->left = insertValue(node->left, value);
        } else {
            node->right = insertValue(node->right, value);
        }

        return balanceNode(node);
    }

    // Поиск минимального значения в дереве
    AVLNode<T>* findMinValueNode(AVLNode<T>* node) {
        if (node == nullptr || node->left == nullptr) {
            return node;
        }
        return findMinValueNode(node->left);
    }

    // Удаление значения из дерева
    AVLNode<T>* removeValue(AVLNode<T>* node, T value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->data) {
            node->left = removeValue(node->left, value);
        } else if (value > node->data) {
            node->right = removeValue(node->right, value);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            } else if (node->left == nullptr) {
                AVLNode<T>* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                AVLNode<T>* temp = node->left;
                delete node;
                return temp;
            } else {
                AVLNode<T>* minNode = findMinValueNode(node->right);
                node->data = minNode->data;
                node->right = removeValue(node->right, minNode->data);
            }
        }

        return balanceNode(node);
    }

public:
    AVLTree() : root(nullptr) {}

    // Вставка значения в дерево
    void insert(T value) {
        root = insertValue(root, value);
    }

    // Удаление значения из дерева
    void remove(T value) {
        root = removeValue(root, value);
    }

    // Поиск значения в дереве
    bool search(T value) {
        AVLNode<T>* current = root;
        while (current != nullptr) {
            if (value == current->data) {
                return true;
            } else if (value < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }

    // Вывод дерева в инфиксном порядке
    void printInorder(AVLNode<T>* node) {
        if (node == nullptr) {
            return;
        }
        printInorder(node->left);
        std::cout << node->data << " ";
        printInorder(node->right);
    }

    // Вывод дерева
    void print() {
        printInorder(root);
        std::cout << std::endl;
    }
};
#endif //COURSEPRJ_AVL_H
