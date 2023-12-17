//
// Created by Lev on 17.12.2023.
//
#include "search.h"
int linearSearch(const std::vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i;  // Возвращаем индекс, если элемент найден
        }
    }
    return -1;  // Возвращаем -1, если элемент не найден
}

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;  // Возвращаем индекс, если элемент найден
        }

        if (target < arr[mid]) {
            right = mid - 1;  // Ищем в левой половине массива
        } else {
            left = mid + 1;  // Ищем в правой половине массива
        }
    }

    return -1;  // Возвращаем -1, если элемент не найден
}

int fastLinearSearch(const std::vector<int>& arr, int target) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;  // найден элемент, возвращаем его индекс
        }
    }

    return -1;  // элемент не найден
}

int blockSearch(const std::vector<int>& arr, int target, int blockSize) {
    int n = arr.size();
    int blockIndex = 0;

    // Находим блок, в котором находится искомый элемент
    while (blockIndex < n && arr[blockIndex] <= target) {
        blockIndex += blockSize;
    }

    // Определяем границы блока
    int start = blockIndex - blockSize;
    int end = std::min(blockIndex, n) - 1;

    // Ищем элемент внутри блока
    for (int i = start; i <= end; ++i) {
        if (arr[i] == target) {
            return i;  // элемент найден, возвращаем индекс
        }
    }

    return -1;  // элемент не найден
}