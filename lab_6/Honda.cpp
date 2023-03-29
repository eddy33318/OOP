#include <iostream>
#include "Honda.h"
using namespace std;

float Honda::getFuelCapacity()
{
    return 72.8f;
}

float Honda::getFuelConsumption()
{
    return 8.5f;
}

float Honda::getTopSpeed(weather w)
{
        int s;
    s = rand() % 120; 
    float x;
    x = 225.5f;
    switch (w)
    {
    case weather::rainy:
        x -= 15;
        break;
    case weather::foggy:
        x -= 30;
        break;
    case weather::sunny:
        x += s;
        break;
    case weather::snowy:
        x -= 70;
        break;
    default:
        break;
    }
    return x;
}