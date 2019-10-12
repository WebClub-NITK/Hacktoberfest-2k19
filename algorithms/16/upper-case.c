#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  char* str = argv[1];
  int i = 0;

  while (str[i] != '\0')
  {
    if (isalpha(str[i]) && islower(str[i]))
    {
      printf("%c", toupper(str[i]));
    }
    else
    {
      printf("%c", str[i]);
    }
    i++;
  }
  printf("\n");
}
