#include<iostream>
#include<string.h>
using namespace std;
int main()
{
int i=0,j=0,k=0,count=0;
string str;
char temp[25];

cout<<"Enter a String :\n";
getline(cin,str);

int len=str.length();

for(i=0;i<len;i++)
{
if(str[i]==',')
{
  count++;
}
}

char ch[count][25];

for(i=0;i<=len;i++)
{
if(str[i]==',')
{
ch[j][k]='\0';
j++;
k=0;
}
else if(str[i]=='\0')
{
  ch[j][k]='\0';
}
else
{
  ch[j][k++]=str[i];
}
}

//for(i=0;i<=count;i++)
//cout<<ch[i]<<"\n";

for(i=0;i<=count;i++)
for(j=i+1;j<=count;j++)
{
  if(strcmp(ch[i],ch[j])>0)
  {
    strcpy(temp,ch[i]);
    strcpy(ch[i],ch[j]);
    strcpy(ch[j],temp);
  }
}

cout<<"Output :\n";

for(i=0;i<=count;i++)
cout<<ch[i]<<",";
cout<<"\b";


return 0;
}
