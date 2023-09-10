#ifndef BIGNUMCALC_H
#define BIGNUMCALC_H

#include <list>
#include <string>

class bigNumCalc {
public:
    std::list<int> buildBigNum(const std::string& numString);
    std::list<int> add(const std::list<int>& num1, const std::list<int>& num2);
    std::list<int> sub(const std::list<int>& num1, const std::list<int>& num2);
    std::list<int> mul(const std::list<int>& num1, int num2);

private:
    void removeLeadingZeros(std::list<int>& num);
};

#endif
