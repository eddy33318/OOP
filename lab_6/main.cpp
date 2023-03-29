#include "car.h"
#include "circuit.h"
#include "BMW.h"
#include "Nissan.h"
#include "VWGolf5.h"
#include "Honda.h"
#include "RangeRover.h"
#include "Ferrari.h"
using namespace std;

int main()
{
    circuit c;
    weather w;
    c.SetLength(600);
    c.SetWeather(w); //weather e ales random, mi s-a parut mai corect asa
    c.InitCarCount();
    c.AddCar(new Honda());
    c.AddCar(new Ferrari());
    c.AddCar(new Nissan());
    c.AddCar(new BMW());
    c.Race();
    c.ShowFinalRanks();
    c.ShowWhoDidNotFinish();


    return 0;
}