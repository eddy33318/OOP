#include <iostream>
#include "Ferrari.h"
using namespace std;

float Ferrari::getFuelCapacity()
{
    return 70.8f;
}

float Ferrari::getFuelConsumption()
{
    return 18.5f;
}

float Ferrari::getTopSpeed(weather w)
{
    float x;
    x = 420.5f;
    switch (w)
    {
    case weather::rainy:
        x -= 85;
        break;
    case weather::foggy:
        x -= 40;
        break;
    case weather::sunny:
        x += 30;
        break;
    case weather::snowy:
        x -= 200;
        break;
    default:
        break;
    }
    return x;
}
