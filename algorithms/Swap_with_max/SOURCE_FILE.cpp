#include<stdio.h>
//MAXIMUM FUNCTION
void maximum(int arr)
{ int max;
 for(int i=0;i<ind;i++)
 {
  if(max<arr[i])
  max=arr[i];
 }	
 return max;
}
//SWAP FUNCTION
void swap(int arr[],int ind)
{
	int l=maximum(arr);
	int temp;
	temp=arr[l];
	arr[l]=arr[ind];
	arr[ind]=temp;
}

//MAIN FUNCTION
int main()
{   int N;
	printf("ENTER THE NUMBER OF ELEMENTS IN THE ARRAY:");
	scanf("%d",&N);
	int i=0;
	int arr[N];
	for(i=0;i<N;i++)
	{
		scanf("%d",arr+i);
	}
	int ind;
	printf("ENTER THE INDEX TO SWAP WITH THE MAXIMUM:");
	scanf("%d",&ind);
	swap(arr,ind);
	int j=0;
	//DISPLAYING THE ARRAY
	for(j=0;j<N;j++)
	{
		printf("%d ",arr[i]);
	}
	
	
}
