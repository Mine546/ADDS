#include "Player.h"
#include "Computer.h"
#include <iostream>
#include <string>

Computer::Computer(){
    name="Computer";
    move='R';
}

char Computer::makeMove(){
    move='R';
    return move;
}

void Computer::setName(std::string Name){
    
}
Computer::~Computer(){}