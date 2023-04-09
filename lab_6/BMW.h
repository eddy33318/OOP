#include "car.h"
#pragma once

class BMW : public car
{
    float getFuelConsumption();
    float getTopSpeed(weather w);
    float getFuelCapacity();
    const char *getName() const override { return "BMW"; }
};