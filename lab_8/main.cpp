#include <iostream>
using namespace std;
void print()
{
    printf("#######");
}
template <typename T, typename P>
struct Map
{
    struct Element
    {
        P value;
        T key;
        int index;
        Element &operator=(P value)
        {
            this->value = value;
            return *this;
        }
    };

    Element *data;
    int size;

    Element &operator[](T key)
    {
        for (int i = 0; i < size; i++)
        {
            if (key == data[i].key)
            {
                return data[i];
            }
        }
        Element *copy = new Element[size + 1];
        for (int i = 0; i < size; i++)
        {
            copy[i].key = data[i].key;
            copy[i].value = data[i].value;
            copy[i].index = data[i].index;
        }
        delete[] data;
        data = new Element[size + 1];
        for (int i = 0; i < size; i++)
        {
            data[i].key = copy[i].key;
            data[i].value = copy[i].value;
            data[i].index = copy[i].index;
        }
        size++;
        data[size - 1].key = key;
        data[size - 1].index = size - 1;
        delete[] copy;
        return data[size - 1];
        
    }

    Map()
    {
        data = new Element[100];
        size = 0;
    }

    ~Map()
    {
        delete[] data;
    }

    struct iterator
    {
        Element *ptr;

        iterator(Element *ptr)
        {
            this->ptr = ptr;
        }

        bool operator!=(iterator i)
        {
            return ptr != i.ptr;
        }

        void operator++()
        {
            ++ptr;
        }

        Element& operator*()
        {
            return *ptr;
        }
    };

    iterator begin()
    {
        return iterator(&data[0]);
    }

    iterator end()
    {
        return iterator(&data[size]);
    }

    void set(T newKey, T key)
    {
        for (int i = 0; i < size; i++)
        {
            if (key == data[i].key)
            {
                data[i].key = newKey;
            }
        }
    }
    // bool Get(const T& key, const P& value)
    // {
    //     for(int i = 0; i < size; i++)
    //     {
    //         if(key == data[i].key)
    //         {
    //             data[i].value = key;
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    int count()
    {
        return size;
    }
    void clear()
    {
        size = 0;
        delete[] data;
    }
bool Delete(const T& key)
{
    for (int i = 0; i < size; i++)
    {
        if (key == data[i].key)
        {
            for (int j = i; j < size - 1; j++)
            {
                data[j].index = data[j + 1].index;
                data[j].key = data[j + 1].key;
                data[j].value = data[j + 1].value;
            }
            size--;
            return true;
        }
    }
    return false;
}

    bool Includes(const Map<T,P>& map)
{
    for (int i = 0; i < size; i++)
    {
        bool found = false;
        for (int j = 0; j < map.size; j++)
        {
            if (data[i].key == map.data[j].key)
            {
                if(data[i].value == map.data[j].value)
                {
                    found = true;
                break;
                }
                
            }
        }
        if (!found)
        {
            return false;  // The current map does not include a key from the given map.
        }
    }
    return true;  // All keys in the current map are also present in the given map.
}
};

int main()
{
     Map<int, const char *> m;

    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    // for (auto [value, key, index] : m)
    // {
    //     printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    // }

    m[20] = "result";
    m.set(15, 20);
//     m.clear();
//     // m.Get(15, "C++");

//   // printf("\n%d\n", m.count());

    m.Delete(30);
    for (auto [value, key, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    Map<int, const char *> n;
     n[10] = "C++";
    //n[50] = "test";
    n[15] = "result";
    for (auto [value, key, index] : n)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    if(n.Includes(m) == 1) printf("The maps are equal");
    else cout<< "NO";
    return 0;
}
