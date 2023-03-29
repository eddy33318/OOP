#include "car.h"
#pragma once

class Honda : public car
{
    float getFuelConsumption();
    float getTopSpeed(weather w);
    float getFuelCapacity();
    const char *getName() const override { return "Honda"; }
};