#include "Finder.h"


#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::vector<int> Finder::findSubstrings(std::string s1, std::string s2) {
    std::vector<int> result;

    size_t foundPos = 0;

    for (size_t i = 0; i < s2.size(); i++) {
        size_t found = s1.find(s2[i], foundPos);
        if (found != std::string::npos) {
            result.push_back(found-i);
            foundPos = found+1;
        } else {
            result.push_back(-1);
        }
    }

    return result;
}