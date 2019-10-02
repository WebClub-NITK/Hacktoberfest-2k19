#include<iostream.h>
#include<conio.h>
#include<math.h>

void main()
{
 clrscr();
 long deci;
 cout<<"Enter Decimal Number: ";
 cin>>deci;
 int temp = deci;
 int counter = 0;
 long bin = 0;
 int temp1 = 0;
 while(temp!=0)
 {
  temp1 = temp%2;
  bin = bin + temp1*pow(10,counter);
  temp = temp/2;
  counter++;
 }
 cout<<"Binary = "<<bin;
 getch();
}
