#include <iostream>
#include "Nissan.h"
using namespace std;

float Nissan::getFuelCapacity()
{
    return 58.8f;
}

float Nissan::getFuelConsumption()
{
    return 8.2f;
}

float Nissan::getTopSpeed(weather w)
{
    int s;
    s = rand() % 150;
    float x;
    x = 270.5f;
    switch (w)
    {
    case weather::rainy:
        x -= 15;
        break;
    case weather::foggy:
        x -= 30;
        break;
    case weather::sunny:
        x += 10;
        break;
    case weather::snowy:
        x -= 70;
        break;
    default:
        break;
    }
    return x;}
