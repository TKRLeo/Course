//
// Created by Lev on 16.12.2023.
//

#ifndef COURSEPRJ_HASHTABLE_H
#define COURSEPRJ_HASHTABLE_H
#include <list>
#include <algorithm>
#include <functional>

using namespace std;

template <typename KeyType, typename ValueType>
class HashTable {
private:
    static const int hashTableSize = 10;  // Размер хэш-таблицы
    list<std::pair<KeyType, ValueType>> data[hashTableSize];  // Хранение данных в списке

public:
    // Функция для вычисления хэша ключа
    int hashFunction(KeyType key) {
        return std::hash<KeyType>{}(key) % hashTableSize;
    }

    // Функция для добавления элемента в хэш-таблицу
    void insert(KeyType key, const ValueType& value) {
        int index = hashFunction(key);
        data[index].push_back(std::make_pair(key, value));
    }

    // Функция для удаления элемента из хэш-таблицы
    void remove(KeyType key) {
        int index = hashFunction(key);
        auto& bucket = data[index];
        auto it = std::find_if(bucket.begin(), bucket.end(), [&](const std::pair<KeyType, ValueType>& element) {
            return element.first == key;
        });

        if (it != bucket.end()) {
            bucket.erase(it);
        }
    }

    // Функция для получения значения по ключу
    ValueType get(KeyType key) {
        int index = hashFunction(key);
        auto& bucket = data[index];
        auto it = std::find_if(bucket.begin(), bucket.end(), [&](const std::pair<KeyType, ValueType>& element) {
            return element.first == key;
        });

        if (it != bucket.end()) {
            return it->second;
        } else {
            return ValueType();  // Возвращаем значение по умолчанию, если ключ не найден
        }
    }
};



#endif //COURSEPRJ_HASHTABLE_H
