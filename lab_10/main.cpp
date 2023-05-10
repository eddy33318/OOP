
#include <stdexcept>
#include <iostream>
template<class T>

class Array

{

private:

	T** List; // lista cu pointeri la obiecte de tipul T*

	int Capacity; // dimensiunea listei de pointeri

	int Size; // cate elemente sunt in lista

public:

	Array(); // Lista nu e alocata, Capacity si Size = 0

	~Array(); // destructor

	Array(int capacity); // Lista e alocata cu 'capacity' elemente

	Array(const Array<T> &otherArray); // constructor de copiere



	T& operator[] (int index); // arunca exceptie daca index este out of range



	 const Array<T>& operator+=(const T &newElem); // adauga un element de tipul T la sfarsitul listei si returneaza this
    
    const Array<T>& Insert(int index, const T &newElem); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    
    void print();
    
    int GetSize();
};
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
    List = nullptr;  
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
    if (index >= Size || index < 0)
    {
        throw OOB;
    }
    return *(List[index]);
}

template<class T>


const Array<T>& Array<T>::operator+=(const T& newElem)
{
    if (Size >= Capacity)
    {
        throw OutOfBounds();
    }
    List[Size] = new T(newElem);
    Size++;
    return *this;
}

template<class T>
const Array<T>& Array<T>::Insert(int index, const T& newElem)
{
    if (index < 0 || index >= Capacity)
    {
        throw OutOfBounds();
    }

    if (Size < index)
    {
        Size = index;
    }

    List[index] = new T(newElem);
    Size++;
    return *this;
}


template<class T>

void Array<T>::print()
 {
        printf("\n\n");
        for(int i = 0; i < Size; i++)
        {
            printf("%d ", *List[i]);
        }
 }

template<class T>

int Array<T>::GetSize()
{
    return Size;
}

int main()
{
    Array<int> myArray(10);
    myArray += 3;
    
    myArray.Insert(4, 28);
    printf("%d",myArray.GetSize());
    myArray.print();
    return 0;
}