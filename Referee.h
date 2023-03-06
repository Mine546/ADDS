#ifndef REFEREE_H
#define REFEREE_H
#include "Player.h"
#include <iostream>
#include <string>

class Referee{
    public:
        Referee();
        ~Referee();
        
        Player * refGame(Player * player1, Player * player2);

};

#endif

