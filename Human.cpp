#include "Player.h"
#include "Human.h"
#include <iostream>
#include <string>

Human::Human(){
    name="Human";
}

Human::Human(std::string Name){
    name=Name;
}

void Human::setName(std::string Name){
    name=Name;
}

char Human::makeMove(){
    std::cout<<"Enter move: "<<std::endl;
    std::cin>>move;
    return move;
}

Human::~Human(){
}