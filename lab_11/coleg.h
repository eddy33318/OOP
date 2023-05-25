#include "contact.h"
#pragma once

class coleg : public contact
{
    string serviciu;
    string adresa;
    string nr_telefon;

public:
    coleg(string nume, string serviciu, string adresa, string nr_telefon)
    {
        this->serviciu = serviciu;
        this->adresa = adresa;
        this->nr_telefon = nr_telefon;
        this->GetNume() = nume;
    }
    string GetServiciu()
    {
        return serviciu;
    }
    string GetNrTelefon()
    {
        return nr_telefon;
    }
    string GetAdresa()
    {
        return adresa;
    }
    string GetTip()
    {
        return "coleg";
    }
};