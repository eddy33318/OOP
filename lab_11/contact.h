#include <string>
#pragma once
using namespace std;

class contact
{
    private:
    string nume;
    public:
    string GetNume()
    {
        return nume;
    }
    virtual string GetTip() = 0;
};