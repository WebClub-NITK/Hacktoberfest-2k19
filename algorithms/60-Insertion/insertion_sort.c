#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int i,a[n],j,k,m;
  for(i=0;i<n;i++)
  cin>>a[i];

  for(i=1;i<n;i++)
  {
    k=a[i];
    j=i-1;
    while(j>=0 && a[j]>k)
    {
      a[j+1]=a[j];
      for(m=0;m<n;m++)
      cout<<a[m]<<" ";
      cout<<"\n";
      j--;
    }
    a[j+1]=k;
  }
  for(m=0;m<n;m++)
  cout<<a[m]<<" ";
}

