#include "Truckloads.h"

    Truckloads::Truckloads(){
        memo.assign(100,0);
    }

    int Truckloads::numTrucks(int numCrates, int loadSize) {
        if (numCrates<=loadSize) {
            return 1;
        }
        if (memo[numCrates]!=0){
            return memo[numCrates];
        }
        else {
            int leftPile=numCrates / 2;
            int rightPile=numCrates-leftPile;
            memo[numCrates]=numTrucks(leftPile, loadSize)+numTrucks(rightPile, loadSize);
            return numTrucks(leftPile, loadSize)+numTrucks(rightPile, loadSize);
        }
    }

    Truckloads::~Truckloads(){}