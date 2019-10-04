#include<stdio.h>

void main()
{ int n;
int b[50];
printf("Enter the number");
scanf("%d",&n);
int num;
num=n;
while(n>0)
{ b[i]=num%2;
num=num/2;
i++;
}
int j;
for(j=i-1;j>=0;j--)
printf("%d",b[i]);
}