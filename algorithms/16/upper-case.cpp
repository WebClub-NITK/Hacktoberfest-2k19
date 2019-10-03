#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout<<"Enter sentence: ";
    getline(cin,s);
    for(int i=0; i < s.length();i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i]-'a' + 'A';
        }
    }
    cout<<s<<endl;
}
