#include <iostream>
#include <vector>
#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

int main() {
    // Create an unsorted list of integers
    std::vector<int> unsortedListA = {1, 3, 5, 4, -5, 100, 7777, 2014, 0};
    std::vector<int> unsortedListB = {0, 3, 5, 4, -5, 100, 7777, 2014};
    std::vector<int> unsortedListC = {-5, -8, -4, -2, -1};
    std::vector<int> unsortedListD = {3,2,1};
    std::vector<int> unsortedListE = {3,2};
    std::vector<int> unsortedListF = {1};

    // Sort the list using QuickSort
    QuickSort quickSort;
    std::vector<int> sortedQuick = quickSort.sort(unsortedListA);

    // Perform a binary search on the sorted list
    RecursiveBinarySearch binarySearch;
    int target = 1; // Change this to the element you want to search for
    bool found = binarySearch.search(sortedQuick, target);

    if (found==1) {
        std::cout << "true ";
        for (int num : sortedQuick) {
            std::cout << num << " ";
        }
    } else {
        std::cout << "false ";
        for (int num : sortedQuick) {
            std::cout << num << " ";
        }
    }

    std::cout<<std::endl;

    sortedQuick = quickSort.sort(unsortedListB);


    found = binarySearch.search(sortedQuick, target);

    if (found==1) {
        std::cout << "true ";
        for (int num : sortedQuick) {
            std::cout << num << " ";
        }
    } else {
        std::cout << "false ";
        for (int num : sortedQuick) {
            std::cout << num << " ";
        }
    }

    std::cout<<std::endl;

    // Sort the list using BubbleSort
    BubbleSort bubbleSort;
    sortedQuick = bubbleSort.sort(unsortedListC);


    found = binarySearch.search(sortedQuick, target);

    if (found==1) {
        std::cout << "true ";
        for (int num : sortedQuick) {
            std::cout << num << " ";
        }
    } else {
        std::cout << "false ";
        for (int num : sortedQuick) {
            std::cout << num << " ";
        }
    }


    std::cout<<std::endl;


    sortedQuick = quickSort.sort(unsortedListD);


    found = binarySearch.search(sortedQuick, target);

    if (found==1) {
        std::cout << "true ";
        for (int num : sortedQuick) {
            std::cout << num << " ";
        }
    } else {
        std::cout << "false ";
        for (int num : sortedQuick) {
            std::cout << num << " ";
        }
    }

    std::cout<<std::endl;


    sortedQuick = quickSort.sort(unsortedListE);


    found = binarySearch.search(sortedQuick, target);

    if (found==1) {
        std::cout << "true ";
        for (int num : sortedQuick) {
            std::cout << num << " ";
        }
    } else {
        std::cout << "false ";
        for (int num : sortedQuick) {
            std::cout << num << " ";
        }
    }

    std::cout<<std::endl;

    sortedQuick = quickSort.sort(unsortedListF);


    found = binarySearch.search(sortedQuick, target);

    if (found==1) {
        std::cout << "true ";
        for (int num : sortedQuick) {
            std::cout << num << " ";
        }
    } else {
        std::cout << "false ";
        for (int num : sortedQuick) {
            std::cout << num << " ";
        }
    }

    std::cout<<std::endl;


    sortedQuick = bubbleSort.sort(unsortedListE);


    found = binarySearch.search(sortedQuick, target);

    if (found==1) {
        std::cout << "true ";
        for (int num : sortedQuick) {
            std::cout << num << " ";
        }
    } else {
        std::cout << "false ";
        for (int num : sortedQuick) {
            std::cout << num << " ";
        }
    }


    std::cout<<std::endl;

    sortedQuick = bubbleSort.sort(unsortedListF);


    found = binarySearch.search(sortedQuick, target);

    if (found==1) {
        std::cout << "true ";
        for (int num : sortedQuick) {
            std::cout << num << " ";
        }
    } else {
        std::cout << "false ";
        for (int num : sortedQuick) {
            std::cout << num << " ";
        }
    }


    std::cout<<std::endl;

    return 0;
}
