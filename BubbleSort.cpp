// BubbleSort.cpp
#include "BubbleSort.h"

std::vector<int> BubbleSort::sort(std::vector<int> list) {
    int n = list.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                // Swap list[j] and list[j + 1]
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                swapped = true;
            }
        }

        // If no two elements were swapped in inner loop, the array is already sorted
        if (!swapped) {
            break;
        }
    }

    return list; // Return the sorted list
}
