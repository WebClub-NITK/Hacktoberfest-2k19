#include<stdio.h>
#include<string.h>
void main()
{
	char string[500];
	printf("Enter a string in lower case to be converted to upper case:\n");
	gets(string);
	printf("The string in upper case is: %s \n",strupr(string));
}

