#include "car.h"
#pragma once

class circuit
{
    int length;
    weather w;
    car **cars;
    car **carsNotFinish;
    float speed;
    int carCount;
    int carsThatDidNotFinish;

public:
    void InitCarCount();
    void SetLength(int length);
    void SetWeather(weather w);
    weather GetWeather();
    void AddCar(car *car);
    void Race();
    void ShowFinalRanks();
    bool CarDidFinish(car *carr);
    void ShowWhoDidNotFinish();
};