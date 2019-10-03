#include<iostream>
using namespace std;

void dec2bin(int x)
{
    int binary[32];//4 bytes - 32 bits in binary
    int i=0;
    while(x!=0)
    {
        binary[i]=x%2;//stores remainder at the particular location
        x=x/2;
        i++;
    }
    cout<<"\nBinary : ";
    for(int k=i-1;k>=0;k--)
        cout<<binary[k];
}

int main()
{
    int x;
    cout<<"Enter an element : ";
    cin>>x;
    dec2bin(x);
    return 0;
}
