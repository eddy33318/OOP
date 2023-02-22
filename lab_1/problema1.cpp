#include <iostream>
#include <cstring>
using namespace std;

int stringToInt(char s[])
{
    int number = 0;
  for(int i = 0 ; i < strlen(s); i++)
   number = (s[i] - '0') + number * 10;
   return number;
}
int main()
{
    char str[10];
    int n, sum = 0;
    FILE *file = fopen("in.txt", "r");
   while(!feof(file))
   {
        fscanf(file, "%s", str);
        n = stringToInt(str);
        sum += n;
   }
  cout << sum;
    return 0;
}