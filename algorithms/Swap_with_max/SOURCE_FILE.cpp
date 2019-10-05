#include<stdio.h>

int ind,N;

//MAIN FUNCTION
int main()
{   int i=0;
    long int arr[100];
	printf("ENTER THE NUMBER OF ELEMENTS IN THE ARRAY:");
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%ld",&arr[i]);
	}
	printf("ENTER THE INDEX TO SWAP WITH THE MAXIMUM:");
	scanf("%d",&ind);

	Swap(arr,ind);
	return 0;
}

//MAXIMUM FUNCTION
long int maximum(long int arr[])
{ 
	long int max=0;
	for(int i=0;i<N;i++)
	{
		if(max<arr[i])
		max=arr[i];
	}	
 	return max;
}

//SWAP FUNCTION
int Swap(long int arr[],int ind)
{
	long int l;
	l=maximum(arr);
	arr[ind]=arr[ind]+l;
	l=arr[ind]-l;
	arr[ind]=arr[ind]-l;
        int j=0;

	//DISPLAYING THE ARRAY
	for(j=0;j<N;j++)
	{
		printf("%ld ",arr[j]);
	}
	return 0;
}
