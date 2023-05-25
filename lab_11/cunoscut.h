#include "contact.h"
#pragma once

class cunoscut : public contact
{
    string nr_telefon;
    public:
    cunoscut(string nume, string nr_telefon)
    {
        this -> nr_telefon =  nr_telefon;
        this -> GetNume() = nume;
    }
    string GetNrTelefon();
    string GetTip();
};