#include<stdio.h>
#include<string.h>

int main()
{
int n;
scanf("%d",&n);
int arr[n];
arr[0]=1;
arr[1]=1;
for(int i=2;i<=n;i++)
{
arr[i]=arr[i-1]+arr[i-2];
}
printf("%d",arr[n]);
return 0;
}	
