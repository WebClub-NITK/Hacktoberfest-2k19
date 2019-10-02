#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
using namespace std;
int main()
{
int i,count=8,flag1=1,flag2=1,flag3=1,flag4=1,countlower=0,countupper=0,countdigit=0,cu=0,cl=0,cd=0;
string password;
cout<<"Enter your Password :\n";
cin>>password;

for(i=0;password[i]!='\0';i++)
{

//if(flag1)
if(isupper(password[i]))
{
flag1=0;
countdigit=0;
countupper++;
countlower=0;
if(countupper==3)
        cu=1;
}

if(islower(password[i]))
{
flag2=0;
countdigit=0;
countupper=0;
countlower++;
if(countlower==3)
        cl=1;
}

if(isdigit(password[i]))
{
flag3=0;
countdigit++;
countupper=0;
countlower=0;
if(countdigit==3)
        cd=1;
}

if(!(isalnum(password[i])))
flag4=0;

}

if(!(password.length()>=7 && password.length()<=32))
{
 cout<<"Password length must be between 7 to 32 characters.\n";
 count-=2;
}

if(flag1!=0)
{
cout<<"Password should contain uppercase letter.\n";
count-=1;
}

if(flag2!=0)
{
  cout<<"Password should contain lowercase letter.\n";
  count-=1;
}

if(flag3!=0)
{
  cout<<"Password should contain number.\n";
  count-=1;
}

if(flag4!=0)
{
 cout<<"Password should contain special character.\n";
 count-=1;
}

if(cu || cd || cl)
{
cout<<"Remove consecutive set of numbers/alphabets.\n";
count-=2;
}

cout<<"Password Strength is : "<<count<<"\n";

return 0;
}
