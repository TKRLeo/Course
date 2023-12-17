//
// Created by Lev on 17.12.2023.
//

#ifndef COURSEPRJ_SEARCH_H
#define COURSEPRJ_SEARCH_H
#include <vector>
#include <algorithm>

int linearSearch(const std::vector<int>& arr, int target);
int binarySearch(const std::vector<int>& arr, int target);
int fastLinearSearch(const std::vector<int>& arr, int target);
int blockSearch(const std::vector<int>& arr, int target, int blockSize);
#endif //COURSEPRJ_SEARCH_H
