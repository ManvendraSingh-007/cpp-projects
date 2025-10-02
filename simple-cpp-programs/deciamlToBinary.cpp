#include <iostream>
#include <cmath>
#include <vector>


void decimalToBinary(int decimal)
{

    if (decimal == 0) {
        std::cout << 0;
        return;
    }
    std::vector<int> bin_digit;

    for(size_t i{}; decimal > 0; decimal >>= 1, i++) {
        bin_digit.push_back(decimal & 1);
    }

    for(size_t i{bin_digit.size()}; i > 0; i--) {
        std::cout << bin_digit[i-1];
    }
}


int main()
{   

    int decimal;
    std::cout << "Enter Decimal Representation : ";
    std::cin >> decimal;

    if (decimal < 0) {
        std::cout << "Invalid Input ";
        return 1;
    }


    decimalToBinary(decimal);
}