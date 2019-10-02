 #include<stdio.h> 
int maxSubArraySum(int a[], int size) 
{ 
	int max_so_far = -2147483648, max_ending_here = 0, 
	start =0, end = 0, s=0; 

	for (int i=0; i< size; i++ ) 
	{ 
		max_ending_here += a[i]; 

		if (max_so_far < max_ending_here) 
		{ 
			max_so_far = max_ending_here; 
			start = s; 
			end = i; 
		} 

		if (max_ending_here < 0) 
		{ 
			max_ending_here = 0; 
			s = i + 1; 
		} 
	} 
	
	return max_so_far;
} 


int main() 
{ 
	int n;
	printf("Enter number of elements\n");
	scanf("%d", &n);
	printf("Enter elements\n");
	int a[n];

	for(int i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	int max_sum = maxSubArraySum(a, n); 

	printf("%d\n",max_sum);
	return 0; 
} 
