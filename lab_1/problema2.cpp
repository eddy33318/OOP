#include <iostream>
#include <cstring>
using namespace std;
char s[1001], t[100][1001];
int i;
int main()
{
  char *c;
  cin.getline(s, 100);
  int maxx = 0;
  c = strtok(s, " ");
  while(c)
  {
    strcpy(t[++i], c);
     c = strtok(0, " ");
  }
  for(int j = 0; j <= i; j++) 
  {
    for(int k = j + 1; k <= i; k++)
      if(strlen(t[j]) < strlen(t[k]))swap(t[j], t[k]);
      else if(strlen(t[j]) == strlen(t[k]))
        if(strcmp(t[j], t[k]) > 0)swap(t[k], t[j]);   
  }
  for(int j = 0; j <= i; j++)
  cout << t[j] << "\n";
}