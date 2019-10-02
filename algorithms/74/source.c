#include <stdio.h>
#define loop(i,a,b) for(int i=a;i<b;i++)

// the input array to be sorted
int arr[10000];
// the array used to store the temporary results in the function
int temp[10000];


//the function to merge the two arrays
void merge(int a[],int l[],int r[],int leftlen,int rightlen)
{
    int i=0,j=0,k=0;
    while((i<leftlen) && (j<rightlen))
    {
        if(l[i]<r[j])
        {
            a[k]=l[i];
            i++;
        }
        else
        {
            a[k]=r[j];
            j++;        
        }
        k++;
    }
    while(i<leftlen)
    {
        a[k]=l[i];i++;k++;
    }
    while(j<rightlen)
    {
        a[k]=r[j];j++;k++;
    }
}


//the function to perform the divide and conquer technique
void mergersort(int a[],int len)
{
    if(len/2)
    {
        int leftlen=len/2;
        int rightlen=len-leftlen;
        int l[leftlen];int r[rightlen];

        loop(i,0,leftlen)l[i]=a[i];
        loop(i,0,rightlen)r[i]=a[i+leftlen];

        mergersort(l,leftlen);
        mergersort(r,rightlen);
        merge(a,l,r,leftlen,rightlen);
    }
}

int main()
{
	int n;
	printf("Enter the number of elements in the array:\n");
	scanf("%d", &n);
	printf("Enter the array elements:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	mergersort(arr,n);
	printf("The array after sorting is:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}