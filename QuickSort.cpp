#include "QuickSort.h"
#include <iostream>

std::vector<int> QuickSort::sort(std::vector<int> list)
{
    if (list.size() <= 2){
        return list;
    }

    std::vector<int> part1, part2;
    int end = list.size();
    int pt = 2;
    int pivot = list.at(pt);

    for (int i = 0; i < end; i++)
    {
        if (i == pt){
            continue;
        }
        if(list.at(i) < pivot){
            part1.push_back(list.at(i));
        } if (list.at(i) >= pivot) {
            part2.push_back(list.at(i));
        }
    };

    std::vector<int> left = sort(part1);
    std::vector<int> right = sort(part2);
    std::vector<int> result = left;
    result.push_back(pivot);
    result.insert(result.end(), right.begin(),right.end());
    return result;
};
