#include<iostream>
#include<string.h>
using namespace std;
int main()
{

int i,keylen,j=0;
char en,dec,ch;
string text,key,deci,enci;

cout<<"Enter the key used for encryption : \n";
cin>>key;

cin.ignore();

cout<<"Enter the text for encryption : \n";
getline(cin,text);

for(i=0;text[i]!='\0';i++)
{
if(isalpha(text[i]))
{
text[j]=text[i];
j++;
}
}
text[j]='\0';

text.erase(j);

keylen=key.length();

for(i=0;text[i]!='\0';i++)
{

if(isupper(text[i]))
{
ch=text[i]%65;
en=((ch+(toupper(key[i%keylen])%65))%26)+65;
text[i]=en;
}

if(islower(text[i]))
{
ch=text[i]%97;
en=((ch+(tolower(key[i%keylen])%97))%26)+97;
text[i]=en;
}

}

cout<<"Encrypted Text : "<<text<<"\n";

for(i=0;text[i]!='\0';i++)
{
if(isupper(text[i]))
{
ch=text[i]%65;
dec=((26+(ch-(toupper(key[i%keylen]))%65))%26)+65;
text[i]=dec;
}

if(islower(text[i]))
{
ch=text[i]%97;
dec=((26+(ch-(tolower(key[i%keylen]))%97))%26)+97;
text[i]=dec;
}

}

cout<<"Decrypted Text : "<<text<<"\n";

return 0;
}



