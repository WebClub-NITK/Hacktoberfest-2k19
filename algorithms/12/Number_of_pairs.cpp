#include <bits/stdc++.h>
using namespace std;
int getPairsCount(int arr[], int n, int sum) 
{ 
    unordered_map<int, int> m; 
  

    for (int i=0; i<n; i++) 
        m[arr[i]]++; 
  
    int t = 0; 
  
 
    for (int i=0; i<n; i++) 
    { 
        t += m[sum-arr[i]]; 
  

        if (sum-arr[i] == arr[i]) 
            t--; 
    } 
  
    return t/2; 
}
int main()
{
 int n;
 scanf("%d",&n);
 int i,x,a[n];
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 scanf("%d",&x);
 printf("%d", getPairsCount(a,n,x));
}
