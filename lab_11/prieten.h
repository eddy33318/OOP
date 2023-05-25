#include "contact.h"
#pragma once

class prieten : public contact
{
    string data_nastere;
    string adresa;
    string nr_telefon;
    public:
    prieten(string nume, string data_nastere, string adresa, string nr_telefon);
    string GetAdresa();
    void SetNume(string nume);
    string GetDataNastere();
    string GetNrTelefon();
    string GetTip();
    ~prieten();
};