#ifndef REVERSER_H
#define REVERSER_H
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Reverser {
    private:
        std::vector<int> rMemoD;
        std::unordered_map<std::string, std::string> rMemoS;
    public:
        Reverser();
        int reverseDigit(int value);
        std::string reverseString(std::string characters);
        ~Reverser();
};

#endif
