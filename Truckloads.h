#ifndef TRUCKLOADS_H
#define TRUCKLOADS_H
#include <iostream>
#include <string>
#include <vector>

class Truckloads {
    private:
        std::vector<int> memo;
    public:
        Truckloads();
        int numTrucks(int numCrates, int loadSize);
        ~Truckloads();
};

#endif
