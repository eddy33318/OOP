#include "weather.h"
#include <iostream>
#include <time.h>
#pragma once

class car
{
public:
    virtual float getFuelConsumption() = 0;
    virtual float getFuelCapacity() = 0;
    virtual float getTopSpeed(weather w) = 0;
    virtual const char *getName() const { return "car"; }
};
