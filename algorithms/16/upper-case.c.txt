#include<stdio.h>
void main()
{ char s[20]
printf("Enter a string\n");
gets(s);
int i;
for(i=0;s[i]!='\0';i++)
{if(s[i]>=97 && s[i]<=122)
s[i]=s[i]-32;
}
printf("The new string is %s",s);
}