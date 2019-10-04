#include<stdio.h>
#include<string.h>
int main()
{
	char s[500];
	gets(s);
	int len,i;
	len=strlen(s);
	for(i=0;i<len;i++)
	{
	if(s[i]>=97 && s[i]<=122)
		s[i]=65+(s[i]-97);
	}
	printf("%s",s);
}
