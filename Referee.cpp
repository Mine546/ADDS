#include "Referee.h"
#include "Player.h"
#include <iostream>
#include <string> 

Referee::Referee(){}

Referee::~Referee(){}

Player * Referee::refGame(Player * player1, Player * player2){

     char move1 = player1->makeMove();
    char move2 = player2->makeMove();

    if (move1 == move2)
    {
        return nullptr;
    }

    else if (move1=='R' && move2=='S')
    {
        return player1;
    }
    else if (move1=='S' && move2=='P')
    {
        return player1;
    }
    else if (move1=='P' && move2=='R')
    {
        return player1;
    }
    else
    {
        return player2;
    }
}



