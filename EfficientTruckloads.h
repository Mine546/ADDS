#ifndef EFFICIENTTRUCKLOADS_H
#define EFFICIENTTRUCKLOADS_H
#include <iostream>
#include <string>
#include <vector>

class EfficientTruckloads {
    private:
        std::vector<int> memo;
    public:
        EfficientTruckloads();
        int numTrucks(int numCrates, int loadSize);
        ~EfficientTruckloads();
};

#endif
