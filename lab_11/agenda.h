#include <iostream>
#include "contact.h"
#include <vector>
#pragma once

class agenda
{
    vector<contact*> v;
    public:
    contact* Cauta(string nume);
    vector<contact*> GetPrieteni();
    void Sterge(string nume);
    void Adauga(contact* c);
};