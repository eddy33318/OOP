#include <iostream>
#include "BMW.h"
using namespace std;

float BMW::getFuelCapacity()
{
    return 56.8f;
}

float BMW::getFuelConsumption()
{
    return 10.5f;
}

float BMW::getTopSpeed(weather w)
{
    float x = 320.5f;
    switch (w)
    {
    case weather::rainy:
        x -= 75;
        break;
    case weather::foggy:
        x -= 25;
        break;
    case weather::sunny:
        x += 25;
        break;
    case weather::snowy:
        x -= 150;
        break;
    default:
        break;
    }
    return x;
}
