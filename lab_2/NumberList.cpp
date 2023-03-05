#include "NumberList.h"
#include <iostream>
void NumberList::Init()
{
   count = 0;
}
bool NumberList::Add(int x)
{
    if(count >= 10)
        return false;
    numbers[++count] = x;
    return true;
}
void NumberList::Sort()
{
    for(int i = 0; i <= count; i++)
    for(int j = i + 1;  j <= count; j++)
        if(numbers[i] > numbers[j])
        {
            int c = 0;
            c = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = c;
        }
}
void NumberList::Print()
{
    for(int i = 0; i < count; i++)
      printf("%d ", numbers[i]);
}