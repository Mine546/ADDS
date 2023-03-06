#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>

class Player{
    public:
    char move;
    std::string name;
    virtual std::string getName();
    virtual char makeMove();
    ~Player();
};

#endif

