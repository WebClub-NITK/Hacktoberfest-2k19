#include <stdio.h>
int main()
{
        long int n;
		printf("Enter a Decimal number: ");
		scanf("%ld", &n);
		int arr[100] = {0};
		int i = 0;
		while(n)
			{
				arr[i++] = n%2;
				n /= 2;
			}
		printf("Binary number: ");
		for(i = i - 1; i >= 0; i--)
			{
				printf("%d",arr[i]);
			}
		printf("\n");
}
