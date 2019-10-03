#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

void main()
{
 clrscr();
 char string[100];
 cout<<"Enter String: ";
 gets(string);
 int l = strlen(string);
 for ( int i = 0; i<l; i++)
 {
  if(islower(string[i]))
  {
   string[i] = toupper(string[i]);
  }
 }
 cout<<endl;
 cout<<"Modified String: ";
 puts(string);
 getch();
}