#ifndef COMPUTER_H
#define COMPUTER_H
#include "Player.h"
#include <iostream>
#include <string>

class Computer: public Player{
    public:
        Computer();
        char makeMove();
        void setName(std::string Name);
        ~Computer();
};

#endif