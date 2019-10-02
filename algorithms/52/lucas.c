#include <stdio.h>

int lucasNumber(int n){
	if(n == 0)
		return 2;
	else if(n == 1)
		return 1;
	else
		return lucasNumber(n-1)+lucasNumber(n-2);
}

int main(){
	printf("Insert a positive integer n:\n");
	int n;
	scanf("%d", &n);
	printf("%d\n", lucasNumber(n));
	return 0;
}