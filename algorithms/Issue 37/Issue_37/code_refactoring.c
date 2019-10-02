// Program
#include <stdio.h>
void c(int);
int main(void){
int n;
scanf("%d",&n);
c(n);}
void c(int n){
int r=n%2;
if(n==0) return; c(n/2);
printf("%d", r);}
// End of program