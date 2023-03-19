#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <initializer_list>
#include <stdarg.h>
class Sort
{
    int *vector;
    char *string;
    int numberOfElements;

public:
    
    Sort(int numberOfElements, int minValue, int maxValue);
    
    Sort(std::initializer_list<int> list);

    Sort(int *vector, int numberOfElements);

    Sort(const char *string);

    Sort(int numberOfElements, ...);

    void QuickSortHelper(int* arr, int low, int high, bool ascendent);

    void InsertSort(bool ascendent=false);

    void QuickSort(bool ascendent=false);

    void BubbleSort(bool ascendent=false);

    void Print();

    int  GetElementsCount();

    int  GetElementFromIndex(int index);
    ~Sort();
};