#include "Referee.h"
#include "Player.h"
#include <iostream>
#include <string> 

Referee::Referee(){

}

Player* refGame(Player* player1, Player* player2){
    switch(player1->move){
        case 'R':
            if (player2->move='R'){
                return NULL;;
            }
            if (player2->move='P'){
                return player2;
            }
            if (player2->move='S'){
                return player1;
            }
        case 'P':
            if (player2->move='P'){
                return NULL;;
            }
            if (player2->move='S'){
                return player2;
            }
            if (player2->move='R'){
                return player1;
            }
        case 'S':
            if (player2->move='P'){
                return NULL;;
            }
            if (player2->move='R'){
                return player2;
            }
            if (player2->move='S'){
                return player1;
            }
    }
    return 0;
}

Referee::~Referee(){}

