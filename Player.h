#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>

class Player{
    protected:
    std::string name;
    char move;
    public:
    Player();
    ~Player();

    virtual void setName(std::string Name)=0;
    virtual std::string getName();
    virtual char makeMove()=0;
};

#endif

