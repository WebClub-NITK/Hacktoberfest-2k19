#include<stdio.h>
void main() 
{
	int i,j,num=3,temp,arr[10][10];
	printf("Enter the size of n*n matrix(n<10):");
	scanf("%d",&num);
	printf("enter the elements of the array");
	for(i=0;i<num;++i)
	for(j=0;j<num;++j)
	scanf("%d",&arr[i]);
	

	for(j=0;arr[0][j]!=1;++j)
		arr[0][j]=0;
		temp=j+1;
		
		for(i=1;i<num;++i)
		{
			for(j=0;j<temp;++j)
			arr[i][j]=0;
		
		arr[i][temp]=1;
		++temp;
	}
	for(i=0;i<num;++i)
	{
	printf("\n");
	for(j=0;j<num;++j)
	printf("%d\t",arr[i][j]);
	}
	
}
