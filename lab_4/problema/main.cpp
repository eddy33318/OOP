#include "sort.h"
using namespace std;

int v[7] = {2, 5, 6, 2, 12, 98};

int main()
{
  Sort a({2, 3, 1, 4, 5});
  a.QuickSort(true);
  printf("%d \n", a.GetElementFromIndex(0));
  printf("%d \n", a.GetElementsCount());
  a.Print();

  Sort b(5, 1, 7, 2, 3, 1);
  b.BubbleSort(false);
  printf("\n%d \n", b.GetElementFromIndex(4));
  printf("%d \n", b.GetElementsCount());
  b.Print();

  Sort c(v, 6);
  c.InsertSort(true);
  printf("\n%d \n", c.GetElementFromIndex(3));
  printf("%d \n", c.GetElementsCount());
  c.Print();

  Sort d(8, 1, 99);
  d.InsertSort(false);
  printf("\n%d \n", d.GetElementFromIndex(5));
  printf("%d \n", d.GetElementsCount());
  d.Print();

  Sort e("21,34,76,23,113,39,1,20,67,1");
  e.QuickSort(false);
  printf("\n%d \n", e.GetElementFromIndex(5));
  printf("%d \n", e.GetElementsCount());
  e.Print();
  return 0;
} 