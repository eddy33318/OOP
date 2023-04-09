#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

float operator""_Kelvin(unsigned long long x)
{
    return x - 273.15;
}

float operator""_Fahrenheit(unsigned long long x)
{
    return (x - 32)/1.8;
}

int main()
{
   float x, y;
   x = 300_Kelvin;
   y = 120_Fahrenheit;
   cout << x << " " << y;
    return 0;
}