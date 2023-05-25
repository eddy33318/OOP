#include "agenda.h"
#include "prieten.h"
#include "cunoscut.h"
#include "coleg.h"

int main()
{
    prieten p("andrei", "21.07.2003", "acasa", "0721371298");
    cout << p.GetNume();
    return 0;
}