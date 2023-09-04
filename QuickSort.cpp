#include "QuickSort.h"
#include <iostream>

std::vector<int> QuickSort::sort(std::vector<int> list) {
    int n = list.size();

    if (n <= 1) {
        return list; // Base case: already sorted
    }

    int pivot = list[n / 2]; // Choose the middle element as the pivot
    std::vector<int> left, equal, right;

    for (int num : list) {
        if (num < pivot) {
            left.push_back(num);
        } else if (num == pivot) {
            equal.push_back(num);
        } else {
            right.push_back(num);
        }
    }

    // Recursively sort the left and right sublists
    left = sort(left);
    right = sort(right);

    // Combine the sorted sublists and pivot
    left.insert(left.end(), equal.begin(), equal.end());
    left.insert(left.end(), right.begin(), right.end());

    return left;
}
