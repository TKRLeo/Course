//
// Created by Lev on 16.12.2023.
//

#ifndef COURSEPRJ_TRIE_H
#define COURSEPRJ_TRIE_H

#include <string>
#include <vector>

using namespace std;

const int ALPHABET_SIZE = 26; // Размер алфавита (предполагаем, что используется только маленькие буквы)

// Узел Trie
struct TrieNode {
    vector<TrieNode*> children; // Хранилище дочерних узлов
    bool isEndOfWord; // Флаг, указывающий на конец слова

    TrieNode() : isEndOfWord(false) {
        children.resize(ALPHABET_SIZE, nullptr);
    }
};

// Trie
class Trie {
private:
    TrieNode* root; // Корень Trie

public:
    Trie() {
        root = new TrieNode();
    }

    // Вставка слова в Trie
    void insert(string word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            // Если узел с символом c не существует, создаем его
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true; // Устанавливаем флаг конца слова
    }

    // Поиск слова в Trie
    bool search(string word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            // Если узел с символом c не существует, слово отсутствует в Trie
            if (current->children[index] == nullptr) {
                return false;
            }
            current = current->children[index];
        }
        return current->isEndOfWord; // Возвращаем значение флага конца слова
    }

    // Проверка, есть ли слова с данным префиксом в Trie
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (char c : prefix) {
            int index = c - 'a';
            // Если узел с символом c не существует, префикс отсутствует в Trie
            if (current->children[index] == nullptr) {
                return false;
            }
            current = current->children[index];
        }
        return true;
    }
};
#endif //COURSEPRJ_TRIE_H
