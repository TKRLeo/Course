//
// Created by Lev on 17.12.2023.
//

#include "sorts.h"

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    int minIndex;
    for (int i = 0; i < n - 1; ++i) {
        minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    int key, j;
    for (int i = 1; i < n; ++i) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(std::vector<int>& arr, int left, int middle, int right) {
    int size1 = middle - left + 1;
    int size2 = right - middle;

    // Создание временных массивов
    std::vector<int> leftArr(size1);
    std::vector<int> rightArr(size2);

    // Копирование данных во временные массивы
    for (int i = 0; i < size1; ++i) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < size2; ++j) {
        rightArr[j] = arr[middle + 1 + j];
    }

    // Слияние временных массивов обратно в основной массив
    int i = 0;  // Индекс первого подмассива
    int j = 0;  // Индекс второго подмассива
    int k = left;  // Индекс основного массива

    while (i < size1 && j < size2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    // Копирование оставшихся элементов первого массива (если такие есть)
    while (i < size1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    // Копирование оставшихся элементов второго массива (если такие есть)
    while (j < size2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        // Находим середину массива
        int middle = left + (right - left) / 2;

        // Рекурсивно сортируем первую и вторую половины
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Объединяем отсортированные половины
        merge(arr, left, middle, right);
    }
}