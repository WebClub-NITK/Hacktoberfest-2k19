#include<stdio.h>
//MAXIMUM FUNCTION
int main()
{
    int N,i,m;
	printf("ENTER THE NUMBER OF ELEMENTS IN THE ARRAY:");
	scanf("%d",&N);
	int arr[N];
	for(i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
  }
  int max=arr[0];
  for(i=1;i<N;i++)
  {
     if(max<arr[i])
      max=arr[i];
  }
	int ind;
	printf("ENTER THE INDEX TO SWAP WITH THE MAXIMUM:");
	scanf("%d",&ind);
  for(i=0;i<N;i++)
    {
      if(arr[i]==max)
      m=i;
    }
    arr[m]=arr[ind];
    arr[ind]=max;
	int j=0;
	//DISPLAYING THE ARRAY
	for(j=0;j<N;j++)
	{
		printf("%d ",arr[j]);
	}
	return 0;
}

