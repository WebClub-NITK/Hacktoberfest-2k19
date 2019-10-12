#include<stdio.h>
//MAXIMUM FUNCTION

int N;
int maximum(long long arr[])
{ long long max=arr[0];
	int p;
 for(int i=1;i<N;i++)
 
  if(max<arr[i])
  {
  	p=i;
  	max=arr[i];
 }	
 
 return p;
}
//SWAP FUNCTION
void swap(long long arr[],int ind)
{

  int l=maximum(arr);
  
	arr[ind-1]=arr[l]+ arr[ind-1];
	arr[l]=arr[ind-1]-arr[l];
	arr[ind-1]=arr[ind-1]-arr[l];


}

//MAIN FUNCTION

int main()
{  
  int i=0,ind;
  char c;
	do
	  {
	printf("ENTER THE NUMBER OF ELEMENTS IN THE ARRAY:");
	scanf("%d",&N);

    printf("\nENTER VALUES IN THE ARRAY:"); 
	long long arr[N];
	
	for(i=0;i<N;i++)
	{
		scanf("%Ld",&arr[i]);
	}
	
	printf("ENTER THE INDEX TO SWAP WITH THE MAXIMUM:");
	scanf("%d",&ind);

	swap(arr,ind);
	
	//DISPLAYING THE ARRAY
	printf("\nThe swapped array is:\n");
	for(i=0;i<N;i++)
	{
		printf("%Ld ",arr[i]);
	}

    //RUNNING PROGRAM AS MANY TIMES AS USER WANTS
	printf("\n \n Do you want to run the program again?(y/Y)\n\n");
	scanf(" %c",&c);
	  }while(c=='y'||c=='Y');

    return 0;   
      
}
