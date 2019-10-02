#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

void main()
{
 clrscr();
  int stringlengthcheck = 0;       //string check check
  int spcharcheck = 0;             //special char check
  int digitcheck = 0;              //digit check
  int lowercheck = 0;              //lower char check
  int uppercheck = 0;              //upper char check
  int consalpha = 1;               //check for consequent alphabets
  int consdigi =1;                 //check for consequent digits
  int score = 0;                   //score

  char password[100];              //input string
  cout<<"Enter Password: ";
  gets(password);

  int l = strlen(password);         //length of string
  if(l>=7 && l<=32)
  {
   stringlengthcheck = 1;
  }

  char ch;
  int ascii;
  for( int i = 0; i<l; i++)
  {
   ch = password[i];
   ascii = ch;
   if(ascii>=65 && ascii<=90)
   {
    uppercheck=1;
   }
   else if( ascii>=97 && ascii<=122)
   {
    lowercheck =1;
   }
   else if(ascii>=48 && ascii<=57)
   {
    digitcheck =1;
   }
   else
   {
    spcharcheck = 1;
   }
  }

  int char1, char2, char3;
  for( i = 0; i<l-2; i++)
  {
   char1=password[i];
   char2=password[i+1];
   char3=password[i+2];

   if(((char1>=65 && char1<=90)||(char1>=97 && char1<=122))&&(char2 == char1+1 && char3 == char1+2))
   {
    consalpha = 0;
   }
   else if(((char1>=48 && char1<=57))&&(char2 == char1+1 && char3 == char1+2))
   {
    consdigi = 0;
   }
  }

   score = stringlengthcheck*2 + lowercheck+ uppercheck+ spcharcheck+ consalpha+consdigi + digitcheck;

   cout<<"Score: "<<score<<endl;
   cout<<endl<<endl;
   cout<<"Stringlengthtest: "<<stringlengthcheck<<endl;
   cout<<"Lower check: "<<lowercheck<<endl;
   cout<<"Upper Check: "<<uppercheck<<endl;
   cout<<"Special Check: "<<spcharcheck<<endl;
   cout<<"Conseq Alpha: "<<consalpha<<endl;
   cout<<"Conseq Digit: "<<consdigi<<endl;
   cout<<"Digit Check: "<<digitcheck<<endl;
   cout<<endl<<endl;
   if(stringlengthcheck==0)
   {
    cout<<"Does not match desired password length"<<endl;
   }
   if(digitcheck==0)
   {
    cout<<"Does not contain a digit"<<endl;
    }
   if(uppercheck==0)
   {
    cout<<"Does not contain Capital letter"<<endl;
   }
   if(lowercheck==0)
   {
    cout<<"Does not contain Small letters"<<endl;
   }
   if(spcharcheck==0)
   {
    cout<<"Does not contain special characters"<<endl;
   }
   if(consalpha==0)
   {
    cout<<"Consequtive Alphabets in password"<<endl;
   }
   if(consdigi==0)
   {
    cout<<"Consequtive Digits in password"<<endl;
   }
   getch();
  }

