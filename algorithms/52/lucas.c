#include <stdio.h>

int lucasNumber(int n){
	if(n == 0) //base case
		return 2;
	else if(n == 1) //other base case
		return 1;
	else
		return lucasNumber(n-1)+lucasNumber(n-2); //recursive call
}

int main(){
	printf("Insert a positive integer n:\n");
	int n;
	while(1){
		scanf("%d", &n);
		if(n < 0)
			printf("Not a positive integer\n");
		else
			break;
	}
	printf("%d\n", lucasNumber(n));
	return 0;
}