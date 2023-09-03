// QuickSort.cpp
#include "QuickSort.h"

std::vector<int> QuickSort::sort(std::vector<int> list) {
    int low = 0;
    int high = list.size() - 1;

    quicksort(list, low, high);

    return list;
}

void QuickSort::quicksort(std::vector<int>& list, int low, int high) {
    if (low < high) {
        int pivot_index = partition(list, low, high);
        quicksort(list, low, pivot_index - 1);
        quicksort(list, pivot_index + 1, high);
    }
}

int QuickSort::partition(std::vector<int>& list, int low, int high) {
    // Select the pivot element (third element)
    int pivot = list[low + 2]; // Using the third element as the pivot

    // Initialize pointers
    int i = low - 1;
    int j = high + 1;

    while (true) {
        // Find an element greater than or equal to the pivot from the left
        do {
            i++;
        } while (list[i] < pivot);

        // Find an element less than or equal to the pivot from the right
        do {
            j--;
        } while (list[j] > pivot);

        // If the pointers meet or cross, the partitioning is complete
        if (i >= j) {
            return j;
        }

        // Swap list[i] and list[j]
        std::swap(list[i], list[j]);
    }
}
