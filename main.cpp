#include <iostream>
using namespace std;
#include "NumberList.cpp"

int main()
{
    NumberList list;
    list.Init();
    list.Add(2);
    list.Add(1);
    list.Add(10);
    list.Sort();
    list.Print();
    return 0;
}