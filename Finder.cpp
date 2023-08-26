#include "Finder.h"


#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::vector<int> Finder::findSubstrings(std::string s1, std::string s2) {
    std::vector<int> result;


    for (size_t i = 0; i < s2.size(); i++) {
        size_t found = s1.find(s2.substr(0,i+1), found-(i-(i-1));
        if (found != std::string::npos) {
            result.push_back(found);

        } else {
            for (int j=i;j<s2.size(); j++){
                result.push_back(-1);
            }
            break;
        }
    }
    return result;
}
