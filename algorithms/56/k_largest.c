#include <stdio.h>

int main()
{
    printf("Please enter the array size:\n");
    int size;
    scanf("%d",&size);
    int arr[size];
    int max=0;
    for(int i=0;i<size;i++)     //creating the array
    {scanf("%d",&arr[i]);
        if(arr[i]>max)max=arr[i];
    }
    int newarr[max+1];
    for(int i=0;i<size;i++)
    {
        newarr[arr[i]]+=1;
    }
    printf("Enter k\n");
    int k=0;
    scanf("%d",&k);
    int temp=k;
    int i=0;
    while(temp>0)
    {temp=temp-newarr[i];
        i++;
    }
    int answer=i;
    printf("The kth largest element in given array is : %d\n",answer);
}//done in linear time