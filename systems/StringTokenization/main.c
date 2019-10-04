#include <stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>
int main(){
    printf("Enter The String \n");
int length = 100;

char * name = malloc(length * sizeof(char));

int count = 0;

char c;



while((c = getchar()) != '\n'){

   if(count >= length)

      name = realloc(name, (length += 10) * sizeof(char));

   name[count++] = c;

}
char dem[20];
printf("Enter Delimiters \n");
gets(dem);
char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",name);
  pch = strtok (name,"dem");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, dem);
  }
}
