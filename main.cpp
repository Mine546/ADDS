#include <iostream>
#include <vector>
#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

int main() {
    // Create an unsorted list of integers
    std::vector<int> unsortedListA = {1, 3, 5, 4, -5, 100, 7777, 2014, 0};

    // Sort the list using QuickSort
    QuickSort quickSort;
    std::vector<int> sortedQuick = quickSort.sort(unsortedListA);

    // Perform a binary search on the sorted list
    RecursiveBinarySearch binarySearch;
    int target = 1; // Change this to the element you want to search for
    bool found = binarySearch.search(sortedQuick, target);

    if (found==1) {
        std::cout << "true ";
    } else {
        std::cout << "Element " << target << " not found in the sorted list." << std::endl;
    }

    for (int num : sortedQuick) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Sort the list using BubbleSort
    BubbleSort bubbleSort;
    std::vector<int> sortedBubble = bubbleSort.sort(unsortedListA);




    for (int num : sortedBubble) {
        std::cout << num << " ";
    }
    std::cout << std::endl;







    return 0;
}
