#include "circuit.h"
#include <cstring>
void circuit::SetLength(int length)
{
    this->length = length;
}

void circuit::SetWeather(weather w)
{
    srand(time(0));
    int x = rand() % 4;
    if (x == 0)
        w = weather::rainy;
    if (x == 1)
        w = weather::sunny;
    if (x == 2)
        w = weather::foggy;
    if (x == 3)
        w = weather::snowy;
    this->w = w;
}

weather circuit::GetWeather()
{
    return w;
}

void circuit::InitCarCount()
{
    carsNotFinish = new car *[15];
    cars = new car *[15];
    carCount = 0;
    carsThatDidNotFinish = 0;
}

void circuit::AddCar(car *carr)
{
    cars[carCount++] = carr;
}

void circuit::ShowFinalRanks()
{
    w = GetWeather();
    if (w == weather::foggy)
        std::cout << "\nThe weather is foggy today!\n";
    if (w == weather::rainy)
        std::cout << "\nThe weather is rainy today!\n";
    if (w == weather::snowy)
        std::cout << "\nThe weather is snowy today!\n";
    if (w == weather::sunny)
        std::cout << "\nThe weather is sunny today!\n";
    for (int i = 0; i < carCount; i++)
        if (CarDidFinish(cars[i]))
            printf("%s finished the race in: %f minutes\n", cars[i]->getName(), length / cars[i]->getTopSpeed(w) * 60);
}

void circuit::Race()
{
    car **temp;
    temp = new car *[15];
    for (int i = 0; i < carCount; i++)
    {
        if ((cars[i]->getFuelCapacity() / (length / 100 * cars[i]->getFuelConsumption())) < 1)
        {
            carsNotFinish[carsThatDidNotFinish++] = cars[i];
            i++;
        }
        {
            for (int j = i + 1; j < carCount; j++)
                if (cars[i]->getTopSpeed(w) < cars[j]->getTopSpeed(w))
                {
                    temp[1] = cars[i];
                    cars[i] = cars[j];
                    cars[j] = temp[1];
                }
        }
    }
    delete[] temp;
}

bool circuit::CarDidFinish(car *carr)
{
    if ((carr->getFuelCapacity() / (length / 100 * carr->getFuelConsumption())) >= 1)
        return 1;
    return 0;
}

void circuit::ShowWhoDidNotFinish()
{
    for (int i = 0; i < carCount; i++)
    {
        if (CarDidFinish(cars[i]) == false)
            std::cout << "This car did not finish the race: " << cars[i]->getName() << "\n";
    }
}