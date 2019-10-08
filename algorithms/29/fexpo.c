#include<stdio.h>
int func(int p, unsigned int q, int k) 
{ 
    int r = 1;    
    p = p % k;    
    while (q > 0) 
    { 
        if (q & 1) 
            r = (r*p) % k;
        q = q/2;  
        p = (p*p) % k;   
    } 
    return r; 
} 
 
int main() 
{ 
   int x,y,p;
   printf("enter value of a,b and m : \n");
   scanf("%u%u%u",&x,&y,&p;
   printf("value is %u", func(x, y, p)); 
   return 0; 
} 
