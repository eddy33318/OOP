#include "sort.h"
#include <stdarg.h>
#include <iostream>
using namespace std;

Sort::Sort(int numberOfElements, int minValue, int maxValue)
{
    this->numberOfElements = numberOfElements;

    srand(time(NULL));

    vector = new int[numberOfElements];

    for (int i = 0; i < numberOfElements; i++)
        vector[i] = minValue + rand() % (maxValue - minValue + 1);
}

Sort::Sort(std::initializer_list<int> values)
{
    numberOfElements = values.size();
    vector = new int[numberOfElements];
    int i = 0;
    for (auto value : values)
    {
        vector[i++] = value;
    }
}

Sort::Sort(int *vector, int numberOfElements)
{
    this->numberOfElements = numberOfElements;
    this->vector = new int[numberOfElements]; 
    for (int i = 0; i < numberOfElements; i++)
        this->vector[i] = vector[i];
}

Sort::Sort(const char *string)
{
    char *temp;
    int count = 0;
    for(int k = 0; k < strlen(string); k++)
    if(string[k] == ',')count++;
    vector = new int[count+1];
    char *str = new char;
    strcpy(str, string);
    int i = 0;
    temp = strtok(str, ",");
    while (temp)
    {
        vector[i++] = stoi(temp);
        temp = strtok(NULL, ",");
    }
    numberOfElements = i;   
}

Sort::Sort(int numberOfElements, ...)
{
    va_list list;
    va_start(list, numberOfElements);
    vector = new int[numberOfElements];
    for (int i = 0; i < numberOfElements; i++)
        vector[i] = va_arg(list, int);
    va_end(list);
    this->numberOfElements = numberOfElements;
}
void Sort::Print()
{
    for (int i = 0; i < numberOfElements; i++)
        printf("%d ", vector[i]);
    printf("\n");
}

void Sort::InsertSort(bool ascendent)
{
    for (int i = 1; i < numberOfElements; i++)
    {
        int key = vector[i];
        int j = i - 1;
        while (j >= 0 && ((vector[j] > key && ascendent) || (vector[j] < key && !ascendent)))
        {
            vector[j + 1] = vector[j];
            j = j - 1;
        }
        vector[j + 1] = key;
    }
}

void Sort::BubbleSort(bool ascendent)
{
    for (int i = 0; i < numberOfElements - 1; i++)
    {
        for (int j = 0; j < numberOfElements - i - 1; j++)
        {
            if ((vector[j] > vector[j + 1] && ascendent) || (vector[j] < vector[j + 1] && !ascendent))
            {
                swap(vector[j], vector[j + 1]);
            }
        }
    }
}

void Sort::QuickSort(bool ascendent)
{
    QuickSortHelper(vector, 0, numberOfElements - 1, ascendent);
}

void Sort::QuickSortHelper(int *arr, int low, int high, bool ascendent)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if ((arr[j] < pivot && ascendent) || (arr[j] > pivot && !ascendent))
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);

        QuickSortHelper(arr, low, i, ascendent);
        QuickSortHelper(arr, i + 2, high, ascendent);
    }
}

int  Sort::GetElementsCount()
{
    return numberOfElements;
}

int Sort::GetElementFromIndex(int index)
{
    return vector[index];
}

Sort::~Sort()
{
    delete[] vector;
}