#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"
#include <iostream>
#include <string>

class Human: public Player{
    public:
        Human();
        char makeMove(); 
        Human(std::string Name);
        void setName(std::string Name);
        ~Human();
};

#endif