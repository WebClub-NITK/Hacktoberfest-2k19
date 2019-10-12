//program for insertion sorting
#include<iostream>
using namespace std;
int main()
{
int n,t,val;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
    cin>>arr[i];
for(int i=1;i<n;i++)//n-1 iterations
{
    val=arr[i];
    t=i-1;
    while(t>=0 && val<arr[t])//repeat the process till the first element is tested to place the current i value in correct location
    {
     arr[t+1]=arr[t];
     t--;
    }
    arr[t+1]=val;
}
for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
return 0;
}
