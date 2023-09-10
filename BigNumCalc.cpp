#include "BigNumCalc.h"

std::list<int> BigNumCalc::buildBigNum(const std::string& numString) {
    std::list<int> result;
    bool leadingZeros = true;

    for (char c : numString) {
        if (std::isdigit(c)) {
            if (c != '0') {
                leadingZeros = false;
            }
            if (!leadingZeros) {
                result.push_back(c - '0');
            }
        }
    }

    if (result.empty()) {
        result.push_back(0);  // Ensure at least one digit for zero.
    }

    return result;
}

std::list<int> BigNumCalc::add(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> result;
    int carry = 0;
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();

    while (it1 != num1.rend() || it2 != num2.rend() || carry) {
        int sum = carry;
        if (it1 != num1.rend()) {
            sum += *it1;
            ++it1;
        }
        if (it2 != num2.rend()) {
            sum += *it2;
            ++it2;
        }

        carry = sum / 10;
        sum %= 10;
        result.push_front(sum);
    }

    removeLeadingZeros(result);
    return result;
}

std::list<int> BigNumCalc::sub(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> result;
    int borrow = 0;
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();

    while (it1 != num1.rend() || it2 != num2.rend()) {
        int x = borrow;
        if (it1 != num1.rend()) {
            x += *it1;
            ++it1;
        }
        if (it2 != num2.rend()) {
            x -= *it2;
            ++it2;
        }

        if (x < 0) {
            x += 10;
            borrow = -1;
        } else {
            borrow = 0;
        }

        result.push_front(x);
    }

    removeLeadingZeros(result);
    return result;
}

std::list<int> BigNumCalc::mul(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> result;

    if (num1.empty() || num2.empty()) {
        result.push_back(0);  // Product of empty lists is zero.
        return result;
    }

    int num2Digit = num2.back();
    std::list<int> num2Copy = num2; // Make a copy of num2
    num2Copy.pop_back();

    std::list<int> partialResult = mul(num1, num2Copy); // Use the copy for recursion
    for (int i = 0; i < num2Digit; ++i) {
        result = add(result, partialResult);
    }

    removeLeadingZeros(result);
    return result;
}


void BigNumCalc::removeLeadingZeros(std::list<int>& num) {
    while (!num.empty() && num.front() == 0) {
        num.pop_front();
    }
}
