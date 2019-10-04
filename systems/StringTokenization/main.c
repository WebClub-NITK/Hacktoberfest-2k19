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
int len=strlen(name);
printf("Enter Delimiters \n");
char dem[256];
gets(dem);
int len2=strlen(dem);
char copy[len];
strcpy(copy,name);
int flag=0;
int d=0,b=0;
char outp[50][100];
for(int i=0;i<len;i++)
{
    flag=0;
    for(int j=0;j<len2;j++)
    {
        if(copy[i]==dem[j]) 
        {
           flag=1;
         }
         
         
    }
    if(flag==0){
        outp[d][b]=copy[i];
           b++;
    }
    if(flag==1) {
        d++;
        b=0;
    }
}
for(int i=0;i<=d;i++)
{
   printf("%s \n",outp[i]);
}

}