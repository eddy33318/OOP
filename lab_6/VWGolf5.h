#include "car.h"
#pragma once

class VWGolf5 : public car
{
    float getFuelConsumption();
    float getTopSpeed(weather w);
    float getFuelCapacity();
    const char *getName() const override { return "VWGolf5"; }
};