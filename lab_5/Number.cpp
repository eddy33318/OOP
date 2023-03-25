#include "Number.h"
using namespace std;
Number::Number(const char *value, int base)
{
  this->base = base;
  if (this->base < 2 || this->base > 16)
  {
    printf("Invalid base!");
    return;
  }

  this->value = new char[strlen(value) + 1];
  for (int i = 0; i < strlen(value); i++)
    this->value[i] = value[i];
  this->value[strlen(value)] = '\0';
}

Number::Number(int val)
{
  base = 10;
  if (val == 0)
  {
    size = 1;
    value = new char[2];
    value[0] = '0';
    value[1] = '\0';
  }
  else
  {
    // calculate the number of digits required to represent the integer in base 10
    int digits = 0;
    int temp = abs(val);
    while (temp != 0)
    {
      digits++;
      temp /= 10;
    }

    // allocate memory for value
    value = new char[digits + 1];

    // convert integer to string
    snprintf(value, digits + 1, "%d", val);

    // calculate size of value
    size = strlen(value);
  }
}

// copy constructor
Number::Number(const Number &other)
{
  base = other.base;
  size = other.size;
  value = new char[size + 1];
  strcpy(value, other.value);
}

// move constructor
Number::Number(Number &&other)
{
  base = other.base;
  size = other.size;
  value = other.value;
  other.value = nullptr;
}

Number::~Number()
{
  delete[] value;
}

void Number::SwitchBase(int newBase)
{

  int power = 1, digit = 0, decimal = 0, j = 0;
  char *result = new char[strlen(value) + 1];
  for (int i = strlen(value) - 1; i >= 0; i--)
  {

    if (value[i] >= '0' && value[i] <= '9')
      digit = value[i] - '0';
    else if (value[i] >= 'A' && value[i] <= 'F')
      digit = value[i] - 'A' + 10;
    // printf("\n%d", digit);
    decimal += digit * power;
    power *= base;
  }
  // printf("\n%d", decimal);
  base = 10;
  while (decimal > 0)
  {

    int digit = decimal % newBase;
    // printf("\n%d", digit);
    char c;
    if (digit < 10)
      c = digit + '0';
    else
      c = digit - 10 + 'A';
    result[j++] = c;
    decimal /= newBase;
  }
  result[j] = '\0';
  int i;
  for (i = 0; i < strlen(result); i++)
    value[i] = result[strlen(result) - i - 1];
  value[i] = '\0';
  delete[] result;
  base = newBase;
}
void Number::Print()
{
  printf("The value is: %s\n", value);
  printf("The base is: %d\n", base);
}

Number operator+(Number a, Number b)
{
  Number c("0", 10);
  int basee = 10, x, y;
  char str[100];
  if (a.base > b.base)
    basee = a.base;
  else if (b.base >= a.base)
    basee = b.base;

  a.SwitchBase(10);
  b.SwitchBase(10);
  x = stoi(a.value);
  y = stoi(b.value);
  x = x + y;
  sprintf(str, "%d", x);
  strcpy(c.value, str);
  c.SwitchBase(basee);
  return c;
}

Number &Number::operator+=(const Number &other)
{
  int basee = 10, x, y;
  char str[100];
  if (base > other.base)
    basee = base;
  else
    basee = other.base;
  x = stoi(value);
  y = stoi(other.value);
  x += y;
  sprintf(str, "%d", x);
  strcpy(value, str);
  this->SwitchBase(basee);
  return *this;
}

Number operator-(Number a, Number b)
{
  Number c("0", 10);
  int basee = 10, x, y;
  char str[100];
  if (a.base > b.base)
    basee = a.base;
  else
    basee = b.base;

  a.SwitchBase(10);
  b.SwitchBase(10);
  x = stoi(a.value);
  y = stoi(b.value);
  x -= y;
  if (x == y)
  {
    c.value[0] = '0';
    c.value[1] = '\0';
    return c;
  }
  else
  {
    sprintf(str, "%d", x);
    strcpy(c.value, str);
  }

  c.SwitchBase(basee);
  return c;
}

Number &Number::operator=(const Number &other)
{
  if (this == &other)
    return *this;

  delete[] value;

  base = other.base;
  value = new char[strlen(other.value) + 1];
  strcpy(value, other.value);

  return *this;
}

Number &Number::operator=(const int &other)
{
  int temp = other;
  int digits = 0;

  while (temp > 0)
  {
    digits++;
    temp /= 10;
  }
  temp = other;
  if (digits == 0)
  {
    value = new char[2];
    value[0] = '0';
    value[1] = '\0';
    base = 10;
    return *this;
  }

  value = new char[digits + 1];
  int i = digits - 1;

  while (temp > 0)
  {
    int digit = temp % 10;
    value[i--] = digit + '0';
    temp /= 10;
  }
  value[digits] = '\0';
  base = 10;
  return *this;
}

Number &Number::operator=(char *other)
{
  strcpy(value, other);
  return *this;
}

bool Number::operator<(const Number &other)
{
  if (base < other.base)
    return true;
  if (base > other.base)
    return false;

  int len = strlen(value);
  int otherlen = strlen(other.value);

  char *tempValue = new char[len + 1];
  char *otherTempValue = new char[otherlen + 1];
  strcpy(tempValue, value);
  strcpy(otherTempValue, other.value);
  if (len != otherlen)
  {
    delete[] tempValue;
    delete[] otherTempValue;
    return len < otherlen;
  }

  for (int i = 0; i < len; i++)
    if (tempValue[i] < otherTempValue[i])
    {
      delete[] tempValue;
      delete[] otherTempValue;
      return true;
    }
  delete[] tempValue;
  delete[] otherTempValue;
  return false;
}

bool Number::operator>(const Number &other)
{
  if (base > other.base)
    return true;
  if (base < other.base)
    return false;

  int len = strlen(value);
  int otherlen = strlen(other.value);

  char *tempValue = new char[len + 1];
  char *otherTempValue = new char[otherlen + 1];
  strcpy(tempValue, value);
  strcpy(otherTempValue, other.value);
  if (len != otherlen)
  {
    delete[] tempValue;
    delete[] otherTempValue;
    return len < otherlen;
  }

  for (int i = 0; i < len; i++)
    if (tempValue[i] > otherTempValue[i])
    {
      delete[] tempValue;
      delete[] otherTempValue;
      return true;
    }
  delete[] tempValue;
  delete[] otherTempValue;
  return false;
}

bool Number::operator>=(const Number &other)
{

  int len = strlen(value);
  int otherlen = strlen(other.value);

  char *tempValue = new char[len + 1];
  char *otherTempValue = new char[otherlen + 1];
  strcpy(tempValue, value);
  strcpy(otherTempValue, other.value);

  if (base > other.base)
    return true;
  if (base == other.base)
  {
    if (len != otherlen)
    {
      delete[] tempValue;
      delete[] otherTempValue;
      return len < otherlen;
    }
    for (int i = 0; i < len; i++)
    {
      if (tempValue[i] > otherTempValue[i])
      {
        delete[] tempValue;
        delete[] otherTempValue;
        return true;
      }

      if (tempValue[i] < otherTempValue[i])
      {
        delete[] tempValue;
        delete[] otherTempValue;
        return false;
      }
    }
    delete[] tempValue;
    delete[] otherTempValue;
    return true;
  }
  return false;
}

bool Number::operator<=(const Number &other)
{

  int len = strlen(value);
  int otherlen = strlen(other.value);

  char *tempValue = new char[len + 1];
  char *otherTempValue = new char[otherlen + 1];
  strcpy(tempValue, value);
  strcpy(otherTempValue, other.value);

  if (base < other.base)
    return true;
  if (base == other.base)
  {
    if (len != otherlen)
    {
      delete[] tempValue;
      delete[] otherTempValue;
      return len < otherlen;
    }
    for (int i = 0; i < len; i++)
    {
      printf("%d %d ", tempValue[i], otherTempValue[i]);
      if (tempValue[i] < otherTempValue[i])
      {
        delete[] tempValue;
        delete[] otherTempValue;
        return true;
      }

      if (tempValue[i] > otherTempValue[i])
      {
        delete[] tempValue;
        delete[] otherTempValue;
        return false;
      }
    }
    delete[] tempValue;
    delete[] otherTempValue;
    return true;
  }
  delete[] tempValue;
  delete[] otherTempValue;
  return false;
}

bool Number::operator==(const Number &other)
{
  int len = strlen(value);
  int otherlen = strlen(other.value);

  if (base != other.base)
    return false;

  char *tempValue = new char[len + 1];
  char *otherTempValue = new char[otherlen + 1];

  if (len != otherlen)
  {
    delete[] tempValue;
    delete[] otherTempValue;
    return false;
  }

  for (int i = 0; i < len; i++)
    if (tempValue[i] != otherTempValue[i])
    {
      delete[] tempValue;
      delete[] otherTempValue;
      return false;
    }

  delete[] tempValue;
  delete[] otherTempValue;

  return true;
}

Number &Number::operator--(int)
{
  char *str = new char[strlen(value) + 1];
  char *tempValue = new char[strlen(value) + 1];
  strcpy(tempValue, value);
  int x = atoi(tempValue);
  x /= 10;
  sprintf(str, "%d", x);
  strcpy(value, str);
  delete[] str;
  return *this;
}

Number &Number::operator--()
{
  char *str = new char[strlen(value) + 1];
  char *tempValue = new char[strlen(value) + 1];
  strcpy(tempValue, value);
  int x = atoi(tempValue);
  int divisor = 1;
  int len = strlen(tempValue);
  while (len - 1)
  {
    divisor *= 10;
    len--;
  }
  x = x % divisor;
  sprintf(str, "%d", x);
  strcpy(value, str);
  delete[] str;
  return *this;
}

char Number::operator[](int index)
{
  return value[index];
}

int Number::GetBase()
{
  return base;
}

int Number::GetDigitsCount()
{
  return strlen(value);
}