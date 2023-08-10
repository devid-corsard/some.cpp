#include "factorial.h"

// Function to calculate the factorial of a number
unsigned long long int factorial(unsigned int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

