#include<stdio.h>
#include<string.h>

int main()
{
long long int n;
scanf("%lld",&n);
long long int arr[n];
arr[0]=1;
arr[1]=1;
for(long long int i=2;i<=n;i++)
{
arr[i]=arr[i-1]+arr[i-2];
}
printf("%lld",arr[n]);
//this will cover larger range than int 
return 0;
}	
