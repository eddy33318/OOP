#pragma once
#include <cstring>
class student
{
    char name[101];
    float nota_mate;
    float nota_istorie;
    float nota_engleza;
    public:
    void set_name(const char *name);
    void set_nota_mate(float nota_mate);
    void set_nota_istorie(float nota_istorie);
    void set_nota_engleza(float nota_engleza);
    char* get_name();
    float get_nota_mate();
    float get_nota_istorie();
    float get_nota_engleza();
    float nota_AVG();
    student();
};