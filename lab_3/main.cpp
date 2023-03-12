#include <iostream>
#include "Canvas.h"
using namespace std;
int main()
{
    Canvas C(10, 10);
    C.DrawCircle(5, 4, 4, '.');
    C.FillCircle(5, 4, 4, '.');
    C.Clear();
    C.DrawRect(4, 4, 8, 8, '!');
    C.FillRect(4, 4, 8, 8, '#');
    C.Clear();
    C.DrawLine(1, 1, 10, 10, 'x');
    C.SetPoint(5, 5, '@');
    C.Print();
    return 0;
}