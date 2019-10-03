#include<stdio.h>
#include<math.h>
int main()
{

long num,i=0,k;
unsigned long bin[50]={0};

printf("Enter the number to convert it into binary : ");
scanf("%ld",&num);
while(num>0)
{
bin[i]=num-(num/2)*2;
num=num/2;
i++;
}
printf("Binary representation of the number is : \n");
for(k=i-1;k>=0;k--)
printf("%lu ",bin[k]);

return 0;
}

