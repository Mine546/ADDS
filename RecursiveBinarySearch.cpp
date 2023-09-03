// RecursiveBinarySearch.cpp
#include "RecursiveBinarySearch.h"

bool RecursiveBinarySearch::search(const std::vector<int>& sorted_list, int target) {
    int start = 0;
    int end = sorted_list.size() - 1;

    return binarySearch(sorted_list, target, start, end);
}

bool RecursiveBinarySearch::binarySearch(const std::vector<int>& sorted_list, int target, int start, int end) {
    if (start > end) {
        // Base case: The target element is not found
        return false;
    }

    int mid = start + (end - start) / 2;

    if (sorted_list[mid] == target) {
        // Base case: The target element is found
        return true;
    } else if (sorted_list[mid] > target) {
        // Recursive case: Search in the left half of the array
        return binarySearch(sorted_list, target, start, mid - 1);
    } else {
        // Recursive case: Search in the right half of the array
        return binarySearch(sorted_list, target, mid + 1, end);
    }
}
