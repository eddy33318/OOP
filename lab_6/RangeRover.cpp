#include <iostream>
#include "RangeRover.h"
using namespace std;

float RangeRover::getFuelCapacity()
{
    return 90.8f;
}

float RangeRover::getFuelConsumption()
{
    return 13.5f;
}

float RangeRover::getTopSpeed(weather w)
{
    int s;
    s = rand() % 100;
    float x;
    x = 420.5f;
    switch (w)
    {
    case weather::rainy:
        x -= 5;
        break;
    case weather::foggy:
        x -= 20;
        break;
    case weather::sunny:
        x += s;
        break;
    case weather::snowy:
        x -= 10;
        break;
    default:
        break;
    }
    return x;
}