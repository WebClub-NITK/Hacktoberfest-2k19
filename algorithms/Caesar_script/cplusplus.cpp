#include <bits/stdc++.h>
using namespace std;
string encrypter(string x,int z)
{
    for(int i=0;i<x.length();++i)
    {
        if(isalpha(x[i]))
        {
            x[i] += z;
            //If sum goes more than the bound.
            if((isupper(x[i])&&x[i]>90)||(islower(x[i])&&x[i]>122))
            {
                x[i]=(char)(x[i]-26);
            }
        }
    }
    return x;
}

string decrypter(string x,int z)
{
    for(int i=0;i<x.length();++i)
    {
        if(isalpha(x[i]))
        {
            x[i]-=z;
            //If goes out of range.
            if ((isupper(x[i]) && x[i] < 65) || (islower(x[i]) && x[i] < 97))
            {
                x[i]=(char)(x[i]+26);
            }
        }
    }
    return x;
}
void bforce(string x)
{
    for(int i=1;i<=26;++i)
    {
        cout<<"\nBF Attempt: Shift= "<<i<<" : "<<decrypter(x,i);
    }
}
int main()
{
    int c;
    cout<<"\nEnter:\n\t1 for Encryption\n\t2 for Decryption\n\t3 for Brute Force Decryption\n-";
    cin>>c;
    cin.ignore(256, '\n');
    int shift;
    string expr,ans;
    switch(c)
    {
        case 1: 
            cout << "\nEncryption Mode. Enter your string: ";
            getline(cin, expr);
            cout<<"\nEncryption Mode. Enter shift key:";
            cin>>shift;
            ans=encrypter(expr,shift);
            cout<<"\nEncryption result is "<<ans;
            break;
        case 2:
            cout << "\nDecryption Mode. Enter your encoded string: ";
            getline(cin, expr);
            cout << "\nDecryption Mode. Enter shift key:";
            cin >> shift;
            ans = decrypter(expr, shift);
            cout << "\nDecryption result is " << ans;
            break;
        case 3:
            cout << "\nBrute Force (BF) Mode. Enter your encoded string: ";
            getline(cin, expr);
            bforce(expr);
            break;
        case 4: break;
        default: cerr<<"\nERROR";
    }
}