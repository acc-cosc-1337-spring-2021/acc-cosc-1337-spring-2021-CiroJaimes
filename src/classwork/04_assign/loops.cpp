//cpp
#include "loops.h"
#include <iostream>

using namespace std;

int factorial(int num)
{
    int val = num;

    for(int i = 1; i < val; i++)
    {
        num *= i;
    }

    return num;
}