#include <iostream>
#include "VWGolf5.h"
using namespace std;

float VWGolf5::getFuelCapacity()
{
    return 49.8f;
}

float VWGolf5::getFuelConsumption()
{
    return 8.0f;
}

float VWGolf5::getTopSpeed(weather w)
{
    int s;
    float x;
    s = rand() % 200;
    x = 220.5f;
    switch (w)
    {
    case weather::rainy:
        x -= 20;
        break;
    case weather::foggy:
        x -= 30;
        break;
    case weather::sunny:
        x += 5;
        break;
    case weather::snowy:
        x -= 65;
        break;
    default:
        break;
    }
    return x;
}