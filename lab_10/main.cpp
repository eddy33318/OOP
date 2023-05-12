
#include <stdexcept>
#include <iostream>

template <class ArrayT>

class ArrayIterator
{
private:
    ArrayT **ptr;

public:
    ArrayIterator(ArrayT **vecPtr) : ptr(vecPtr) {}

    ArrayIterator &operator++()
    {
        ++ptr;
        return *this;
    }

    ArrayIterator &operator--()
    {
        --ptr;
        return *this;
    }

    bool operator==(const ArrayIterator &otherIter) const
    {
        return (ptr == otherIter.ptr);
    }

    bool operator!=(const ArrayIterator &otherIter) const
    {
        return !(*this == otherIter);
    }

    ArrayT &operator*()
    {
        return **ptr;
    }
};

template <class T>
class Array
{
private:
    T **List; // lista cu pointeri la obiecte de tipul T*

    int Capacity; // dimensiunea listei de pointeri

    int Size; // cate elemente sunt in lista

public:
    Array(); // Lista nu e alocata, Capacity si Size = 0

    ~Array(); // destructor

    Array(int capacity); // Lista e alocata cu 'capacity' elemente

    Array(const Array<T> &otherArray); // constructor de copiere

    T &operator[](int index); // arunca exceptie daca index este out of range

    const Array<T> &operator+=(const T &newElem); // adauga un element de tipul T la sfarsitul listei si returneaza this

    const Array<T> &Insert(int index, const T &newElem); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie

    const Array<T> &Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie

    const Array<T> &Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

    bool operator=(const Array<T> &otherArray);

    void Sort(); // sorteaza folosind comparatia intre elementele din T

    int BinarySearch(const T& elem); // cauta un element folosind binary search in Array

    int Find(const T& elem); // cauta un element in Array

    void print();

    int GetSize();

    ArrayIterator<T> begin();

    ArrayIterator<T> end();
};
class OutOfBounds : public std::exception
{
    virtual const char *what() const throw()
    {
        return "Index out of bounds!";
    }
};

template <class T>
Array<T>::Array()
{
    Size = 0;
    Capacity = 0;
    List = nullptr;
}

template <class T>
Array<T>::~Array()
{
    delete[] List;
}

template <class T>
Array<T>::Array(int capacity)
{
    Size = 0;
    Capacity = capacity;
    List = new T *[Capacity]; // Allocate memory for an array of pointers to T
    for (int i = 0; i < Capacity; ++i)
        List[i] = new T;
}

template <class T>
Array<T>::Array(const Array<T> &otherArray)
{
    Size = otherArray.Size;
    Capacity = otherArray.Capacity;
    List = new T *[Capacity]; // Allocate memory for an array of pointers to T

    for (int i = 0; i < Size; i++)
    {
        List[i] = new T(*(otherArray.List[i])); // Perform deep copy of each element
    }
}

template <class T>
T &Array<T>::operator[](int index)
{
    OutOfBounds OOB;
    if (index >= Size || index < 0)
    {
        throw OOB;
    }
    return *(List[index]);
}

template <class T>

const Array<T> &Array<T>::operator+=(const T &newElem)
{
    if (Size >= Capacity)
    {
        throw OutOfBounds();
    }
    List[Size] = new T(newElem);
    Size++;
    return *this;
}

template <class T>

bool Array<T>::operator=(const Array<T> &otherArray)
{
    if (otherArray.Size == 0)
        throw "Error! Empty List!";

    if (otherArray.Capacity != Capacity)
        throw "Error! Different capacities!";
    Size = otherArray.Size;
    for (int i = 0; i < otherArray.Size; i++)
        List[i] = otherArray.List[i];
    return true;
}
template <class T>
const Array<T> &Array<T>::Insert(int index, const T &newElem)
{
    if (index < 0 || index >= Capacity)
    {
        throw OutOfBounds();
    }

    if (Size >= Capacity)
    {
        throw OutOfBounds();
    }

    List[index] = new T(newElem);
    if (Size < index)
        Size = index + 1;
    return *this;
}

template <class T>

const Array<T> &Array<T>::Insert(int index, const Array<T> otherArray)
{
    int i;
    if (index < 0 || index >= Capacity || Size >= Capacity)
    {
        throw OutOfBounds();
    }
    if (Size < otherArray.Size)
    {
        for (i = otherArray.Size - Size; i < otherArray.Size + index; i++)
            List[i] = new T;
    }
    Size = otherArray.Size + index;
    for (i = index; i < otherArray.Size + index; i++)
        List[i] = otherArray.List[i - index];
    return *this;
}

template <class T>
const Array<T> &Array<T>::Delete(int index)
{
    if (index < 0 || index >= Capacity)
    {
        throw OutOfBounds();
    }

    if (Size >= Capacity)
    {
        throw OutOfBounds();
    }

    for (int i = index; i < Size - 1; i++)
    {
        List[i] = List[i + 1];
    }
    Size--;
    return *this;
}

template <class T>
 void Array<T>::Sort()
 {
    int i, j;
    for(i = 0; i < Size; i++)
    {
        for(j = i + 1; j < Size; j++)
        {
            if(*List[i] > *List[j])
            {
                T* aux;
                aux = List[i];
                List[i] = List[j];
                List[j] = aux;
            }
        }
    }
 }


template <class T>

void Array<T>::print()
{
    printf("\n\n");
    for (int i = 0; i < Size; i++)
    {
        printf("%d ", *List[i]);
    }
}

template <class T>
int Array<T>::Find(const T& elem)
{
    for(int i = 0; i < Size; i++)
    if(*List[i] == elem) return i;
    throw "Could not find element!";
}
template <class T>
int Array<T>:: BinarySearch(const T& elem)
{
    int l = 0;
int r = Size - 1;
while (l <= r)
{
    int m = l + (r - l) / 2;
    if (*List[m] == elem)
        return m; // Element found at index m.
    else if (*List[m] < elem)
        l = m + 1;
    else
        r = m - 1;
}
return -1; // Element not found.
}

template <class T>

int Array<T>::GetSize()
{
    return Size;
}

template <class T>

ArrayIterator<T> Array<T>::begin()
{
    return ArrayIterator<T>(List);
}

template <class T>

ArrayIterator<T> Array<T>::end()
{
    return ArrayIterator<T>(List + Size);
}

int main()
{
    Array<int> myArray(10);
    myArray += 3;
    myArray.Insert(7, 99);
    myArray.Insert(3, 8);
    myArray.Insert(4, 1);
    Array<int> myArray2(myArray);
    myArray.Delete(4);
    myArray.Insert(4, 1);
    printf("%d", myArray.GetSize());
    myArray.print();
    myArray2 += 100;
    myArray2 += 11111111;
    // myArray2 = myArray;
    myArray.Insert(2, myArray2);
    myArray2.print();
    myArray.Sort();
    printf("\n\n%d", myArray.Find(99));
    printf("\n\n%d", myArray.BinarySearch(99));
    myArray.print();
    return 0;
}