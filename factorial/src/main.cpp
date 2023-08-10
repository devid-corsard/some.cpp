#include <iostream>
#include "factorial.h"

int main() {
    unsigned int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    unsigned long long int result = factorial(num);
    std::cout << "Factorial of " << num << " is: " << result << std::endl;

    return 0;
}

