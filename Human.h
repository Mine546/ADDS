#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"
#include <iostream>
#include <string>

class Human: public Player{
    public:
        std::string getName(); 
        char makeMove(); 
        Human();
    

    ~Human();
};

#endif