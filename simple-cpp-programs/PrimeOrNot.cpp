#include <iostream>
#include <cmath>

bool isPrime(int target);

int main()
{

    int number;
    std::cout << "Enter a Number to Check if its Prime Or Not > ";
    std::cin >> number;

    if (isPrime(number)) std::cout << "Prime" << std::endl;
    else std::cout << "Not Prime" << std::endl;
}

bool isPrime(int target)
{
    if (target <= 1) return false;
    if (target == 2) return true;
    if (target % 2 == 0) return false;
    for (size_t i = 3; i*i <= target; i+=2)
    {
        if (target % i == 0) return false;
    }
    return true;
}