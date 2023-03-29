#include "car.h"
#pragma once

class RangeRover : public car
{
    float getFuelConsumption();
    float getTopSpeed(weather w);
    float getFuelCapacity();
    const char *getName() const override { return "RangeRover"; }
};