//
// Created by Lev on 17.12.2023.
//

#ifndef COURSEPRJ_SORTS_H
#define COURSEPRJ_SORTS_H

#include <algorithm>
#include <vector>
void bubbleSort(std::vector<int>& arr);
void selectionSort(std::vector<int>& arr);
void insertionSort(std::vector<int>& arr);
int partition(std::vector<int>& arr, int low, int high);
void quickSort(std::vector<int>& arr, int low, int high);
void mergeSort(std::vector<int>& arr, int left, int right);
void merge(std::vector<int>& arr, int left, int middle, int right);



#endif //COURSEPRJ_SORTS_H
