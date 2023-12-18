//
// Created by Lev on 18.12.2023.
//

#ifndef COURSEPRJ_SEGMENTTREE_H
#define COURSEPRJ_SEGMENTTREE_H
#include <vector>
template<typename T>
class SegmentTree {
private:
    std::vector<T> arr;
    std::vector<T> segmentTree;
    int size;

    void buildSegmentTree(std::vector<T>& arr, std::vector<T>& segmentTree, int low, int high, int pos) {
        if (low == high) {
            segmentTree[pos] = arr[low];
        } else {
            int mid = (low + high) / 2;
            buildSegmentTree(arr, segmentTree, low, mid, 2 * pos + 1);
            buildSegmentTree(arr, segmentTree, mid + 1, high, 2 * pos + 2);
            segmentTree[pos] = segmentTree[2 * pos + 1] + segmentTree[2 * pos + 2];
        }
    }

    void updateSegmentTree(std::vector<T>& segmentTree, int low, int high, int idx, T diff, int pos) {
        if (idx < low || idx > high) {
            return;
        }
        segmentTree[pos] += diff;
        if (low != high) {
            int mid = (low + high) / 2;
            updateSegmentTree(segmentTree, low, mid, idx, diff, 2 * pos + 1);
            updateSegmentTree(segmentTree, mid + 1, high, idx, diff, 2 * pos + 2);
        }
    }

    T getSum(std::vector<T>& segmentTree, int low, int high, int qlow, int qhigh, int pos) {
        if (qlow <= low && qhigh >= high) {
            return segmentTree[pos];
        }
        if (high < qlow || low > qhigh) {
            return 0; // Assuming T is numeric type
        }
        int mid = (low + high) / 2;
        return getSum(segmentTree, low, mid, qlow, qhigh, 2 * pos + 1) +
               getSum(segmentTree, mid + 1, high, qlow, qhigh, 2 * pos + 2);
    }

public:
    SegmentTree(const std::vector<T>& input) {
        size = input.size();
        arr = input;
        segmentTree.resize(4 * size);
        buildSegmentTree(arr, segmentTree, 0, size - 1, 0);
    }

    void update(int idx, T value) {
        T diff = value - arr[idx];
        arr[idx] = value;
        updateSegmentTree(segmentTree, 0, size - 1, idx, diff, 0);
    }

    T query(int qlow, int qhigh) {
        return getSum(segmentTree, 0, size - 1, qlow, qhigh, 0);
    }
};
#endif //COURSEPRJ_SEGMENTTREE_H
