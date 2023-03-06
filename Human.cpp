#include "Player.h"
#include "Human.h"
#include <iostream>
#include <string>

Human::Human(){
    std::string name="Human";
    char move;
}

std::string Human::getName(){
    std::cout<<"Enter Name: "<<std::endl;
    std::cin>>name;
    return name;
}

char Human::makeMove(){
    std::cout<<"R, P or C?: "<<std::endl;
    std::cin>>move;
    return move;
}

Human::~Human(){
}