#include <iostream>
#include "Math.h"
#include <cstdarg>
#include <cstring>
using namespace std;
char s1[10];
char s2[10];
int main()
{
    strcpy(s1, "andrei");
    strcpy(s2, "cosmin");
    printf("%s", Math::Add("cosmin", "andrei" ));
    delete[] Math::Add("cosmin", "andrei" );
    
    return 0;
}