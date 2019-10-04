#include <stdio.h>

int main() {
  char ch;
  printf("\n\nEnter a character:");
  scanf("%c", &ch);
  if ( ch >= 97 && ch <= 122 ) {
    ch -=  32;
  }
  printf("\n%c\n\n", ch);
}
