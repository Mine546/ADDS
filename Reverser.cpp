#include "Reverser.h"

    Reverser::Reverser(){
        rMemoD.assign(100,0);
    }

    int Reverser::reverseDigit(int value) {
        if (value<0){
            return -1;
        }
        if (rMemoD[value]!=0){
            return rMemoD[value];
        }
        if (value<=9) {
            rMemoD[value]=value;
            return value;
        }
        int last=value%10;
        int remaining=value/10;
        int digits=1;
        int temporary=value;
        while (temporary>=10) {
            digits*=10;
            temporary/=10;
        }
        rMemoD[value]=last*digits+reverseDigit(remaining);
        return last*digits+reverseDigit(remaining);
    }

    std::string Reverser::reverseString(std::string characters){
        if (characters.length()<1){
            return "ERROR";
        }
        if (rMemoS.find(characters)!=rMemoS.end()){
            return rMemoS[characters];
        }
        if (characters.length()==1) {
            rMemoS[characters]=characters;
            return characters;
        }
            char last=characters.back();
            characters.pop_back();
            rMemoS[characters+last]=last + reverseString(characters);
            return last + reverseString(characters);
    }

    Reverser::~Reverser(){}