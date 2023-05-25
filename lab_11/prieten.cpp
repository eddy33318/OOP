#include "prieten.h"

prieten::prieten(string nume, string data_nastere, string adresa, string nr_telefon)
{
    this->SetNume(nume);
    this->data_nastere = data_nastere;
    this->adresa = adresa;
    this->nr_telefon = nr_telefon;
}

void prieten::SetNume(string nume)
{
    this -> GetNume() = nume;
}

string prieten::GetAdresa()
{
    return adresa;
}

string prieten::GetDataNastere()
{
    return data_nastere;
}

string prieten::GetNrTelefon()
{
    return nr_telefon;
}

string prieten::GetTip()
{
    return "prieten";
}

prieten::~prieten()
{
    // Add any necessary cleanup code here
    // Only include cleanup code if you have dynamically allocated resources
}
