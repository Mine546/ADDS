#include "Finder.h"


#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::vector<int> Finder::findSubstrings(std::string s1, std::string s2) {
    std::vector<int> result;
    size_t found = 0;
    for (size_t i = 0; i < s2.size(); i++) {
        if (i==1 && result.at(0)==0){
            found = s1.find(s2.substr(0,i+1), found);
        } else{
            found = s1.find(s2.substr(0,i+1), found-i);
        }
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
