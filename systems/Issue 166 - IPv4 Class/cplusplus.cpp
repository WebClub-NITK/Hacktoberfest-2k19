#include<bits/stdc++.h>
using namespace std;
bool validate(string str)
{
    int dotcount=0;
    for(int i=0;i<str.length();++i)
    {
        if((!isdigit(str[i]))&&(str[i]!='.'))
        {
            return false;
        }
        if(str[i]=='.')
        {
            dotcount++;
        }
    }

    regex b("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");

    if (dotcount != 3 || !regex_match(str,b))
    {
        return false;
    }
    return true;
}
int decimate(string str)
{
    int n=stoi(str.substr(0,str.find('.')));
    return n;
}
char checkClass(int n)
{
    if((n>=1)&&(n<127))
    {
        return 'A';
    }
    else if((n>=128)&&(n<192))
    {
        return 'B';
    }
    else if((n>=192)&&(n<224))
    {
        return 'C';
    }
    else if((n>=224)&&(n<240))
    {
        return 'D';
    }
    else if((n>=240)&&(n<256))
    {
        return 'E';
    }
}
int main()
{
    string ipv4;
    cout << "\nEnter the IPv4 address:";
    cin>>ipv4;
    
    if(validate(ipv4))
    {
        //Proper IPv4 Address
        cout << "\nThis is a class " << checkClass(decimate(ipv4)) << " IPv4 address.";
        int fc=decimate(ipv4);
    }
    else
    {
        cout<<"\nThis is an invalid IPv4 Address.";
    }
    
}