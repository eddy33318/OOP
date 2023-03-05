#include <iostream>
#include <cstring>
using namespace std;
#include "student.h"
#include "global.h"
char s1[11];
char s2[11];
char s3[11];
int main()
{
    student andrei;
    student edi;
    student ion;
    strcpy(s1, "Andrei");
    strcpy(s2, "Edi");
    strcpy(s3, "Ion");
    andrei.set_name(s1);
    edi.set_name(s2);
    ion.set_name(s3);
    cout << edi.get_name() << "\n";
    cout << andrei.get_name() << "\n";
    ion.set_nota_engleza(1.0);
    ion.set_nota_istorie(11.2);
    ion.set_nota_mate(0);
    andrei.set_nota_engleza(7.3);
    andrei.set_nota_istorie(8.5);
    andrei.set_nota_mate(9.7);
    edi.set_nota_engleza(10);
    edi.set_nota_istorie(5.3);
    edi.set_nota_mate(9.8);
    cout << edi.nota_AVG() <<"\n";
    cout << andrei.nota_AVG() <<"\n";
    cout << ion.nota_AVG() << "\n";
    if(compAVG(edi, andrei) == 1)cout << "Edi are media mai mare\n";
    else if(compAVG(edi, andrei) == 0)cout << "Medii egale\n";
    else
    cout << "Andrei are media mai mare\n";
    if(compGrade_mate(edi, andrei) == 1)cout << "Edi are nota la mate mai mare\n";
    else if(compGrade_mate(edi,andrei) == 0)cout << "Medii egale\n";
    else
    cout << "Andrei are nota la mate mai mare\n";
    if(compGrade_engleza(edi, andrei) == 1)cout << "Edi are nota la engleza mai mare\n";
    else if(compGrade_engleza(edi,andrei) == 0)cout << "Medii egale\n";
    else
    cout << "Andrei are nota la engleza mai mare\n";
    if(compGrade_istorie(edi, andrei) == 1)cout << "Edi are nota la istorie mai mare\n";
   else if(compGrade_istorie(edi,andrei) == 0)cout << "Medii egale\n";
    else
    cout << "Andrei are nota la istorie mai mare\n";
    return 0;
}