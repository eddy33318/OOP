
#include "Array.h"
#include <stdexcept>
#include <iostream>
class OutOfBounds : public std::exception
{
    virtual const char* what() const throw()
    {
        return "Index out of bounds!";
    }
};

template<class T>
Array<T>::Array()
{
    Size = 0;
    Capacity = 0;
    List = nullptr;  // Initialize the pointer to nullptr
}

template<class T>
Array<T>::~Array()
{
    delete[] List;
}

template<class T>
Array<T>::Array(int capacity)
{
    Size = 0;
    Capacity = capacity;
    List = new T*[Capacity];  // Allocate memory for an array of pointers to T
}

template<class T>
Array<T>::Array(const Array<T> &otherArray)
{
    Size = otherArray.Size;
    Capacity = otherArray.Capacity;
    List = new T*[Capacity];  // Allocate memory for an array of pointers to T

    for (int i = 0; i < Size; i++)
    {
        List[i] = new T(*(otherArray.List[i]));  // Perform deep copy of each element
    }
}

template<class T>
T& Array<T>::operator[](int index)
{
    OutOfBounds OOB;
    if (index >= Size)
    {
        throw OOB;
    }
    return *(List[index]);
}

template<class T>

const Array<T>& Array<T>::operator+=(const T &newElem)
{
    List[Size++] = newElem;
}