#include <stdio.h>
#define max(a,b) ((a)>(b))?(a):(b)

// input array
int arr[100];

// Returns the maximum subarray sum
int max_subarray_sum(int n)
{
    // cur is the running sum of numbers
    // ans contains the final answer
    int cur = 0 , ans = 0;
    for(int i = 0; i < n; i++)
    {
        // Add the next element to the running sum
        // If cur becomes negative, make it 0
        cur = max(0, cur + arr[i]);
        ans = max(ans, cur);
    }
    return ans;
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
    printf("Maximum subarray sum is: %d\n", max_subarray_sum(n));

    return 0;
}