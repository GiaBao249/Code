#include <iostream>
using namespace std;

int smallestEvenMultiple(int n)
{
    if (n % 2 != 0)
    {
        n *= 2;
        if (n % 2 == 0)
            return n;
    }
    return n;
}