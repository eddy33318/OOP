#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
class Number

{
    int base;
    char *value;
    int size;
public:
    Number(const char *value, int base); // where base is between 2 and 16

    Number(int value);

    ~Number();

    // add operators and copy/move constructor
    friend Number operator-(Number a, Number b);

    friend Number operator+(Number a, Number b);

    Number &operator=(const Number &other);

    Number &operator=(const int &other);
    
    Number &operator=(char* other);

    Number &operator+=(const Number &other);

    char operator[](int index); 

    bool operator<(const Number &other);

    bool operator>(const Number &other);

    bool operator<=(const Number &other);

    bool operator>=(const Number &other);

    bool operator==(const Number &other);

    Number &operator--();

    Number &operator--(int);

    Number(const Number &other);

    Number(Number &&other);

    void SwitchBase(int newBase);

    void Print();

    int GetDigitsCount(); // returns the number of digits for the current number

    int GetBase(); // returns the current base
};
