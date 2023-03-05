#include "global.h"
#include <cstring>
int compName(student x, student y)
{
    if(strcmp(x.get_name(), y.get_name())>0)
    return 1;
    if(strcmp(x.get_name(), y.get_name())==0)
    return 0;
  //  if(strcmp(x.get_name(), y.get_name())<0)
    return -1;
}
int compGrade_mate(student x, student y)
{
  if(x.get_nota_mate() > y.get_nota_mate())
  return 1;
  if(x.get_nota_mate() == y.get_nota_mate())
  return 0;
  //if(x.get_nota_mate() < y.get_nota_mate())
  return -1;
}
int compGrade_istorie(student x, student y)
{
  if(x.get_nota_istorie() > y.get_nota_istorie())
  return 1;
  if(x.get_nota_istorie() == y.get_nota_istorie())
  return 0;
  //if(x.get_nota_istorie() < y.get_nota_istorie())
  return -1;
}
int compGrade_engleza(student x, student y)
{
  if(x.get_nota_engleza() > y.get_nota_engleza())
  return 1;
  if(x.get_nota_engleza() == y.get_nota_engleza())
  return 0;
  //if(x.get_nota_engleza() < y.get_nota_engleza())
  return -1;
}
int compAVG(student x, student y)
{
  if(x.nota_AVG() > y.nota_AVG())
  return 1;
  if(x.nota_AVG() == y.nota_AVG())
  return 0;
  //if(x.nota_AVG() < y.nota_AVG())
  return -1;
}