#include <iostream>
#include <vector>
#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

int main() {
    // Create an unsorted list of integers
    std::vector<int> unsortedList = {5, 2, 9, 1, 5, 3};

    // Sort the list using BubbleSort
    BubbleSort bubbleSort;
    std::vector<int> sortedBubble = bubbleSort.sort(unsortedList);

    // Sort the list using QuickSort
    QuickSort quickSort;
    std::vector<int> sortedQuick = quickSort.sort(unsortedList);

    // Print the sorted lists
    std::cout << "Bubble Sort Result:" << std::endl;
    for (int num : sortedBubble) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Quick Sort Result:" << std::endl;
    for (int num : sortedQuick) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Perform a binary search on the sorted list
    RecursiveBinarySearch binarySearch;
    int target = 5; // Change this to the element you want to search for
    bool found = binarySearch.search(sortedQuick, target);

    if (found) {
        std::cout << "Element " << target << " found in the sorted list." << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the sorted list." << std::endl;
    }

    return 0;
}
