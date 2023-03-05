#include "student.h"

void student::set_name(const char *name) 
 { 
     strcpy(this -> name, name); 
 } 
void student::set_nota_mate(float nota_mate)
{
    if(nota_mate < 1 || nota_mate > 10)return;
  this -> nota_mate = nota_mate;
}
void student::set_nota_istorie(float nota_istorie)
{
    if(nota_istorie < 1 || nota_istorie > 10)return;
    this -> nota_istorie = nota_istorie;
}
void student::set_nota_engleza(float nota_engleza)
{
    if(nota_engleza < 1 || nota_engleza > 10)return;
    this -> nota_engleza = nota_engleza;
}
char* student::get_name()
{  
    char *c;
    c = name;
    return c;
}
float student::get_nota_engleza()
{
    return nota_engleza;
}
float student::get_nota_istorie()
{
    return nota_istorie;
}
float student::get_nota_mate()
{
    return nota_mate;
}
float student::nota_AVG()
{
  float s = 0;
  s += (nota_engleza + nota_istorie + nota_mate)/3;
  return s;
}
student::student()
{
    nota_mate = 0;
    nota_istorie = 0;
    nota_istorie = 0;
}