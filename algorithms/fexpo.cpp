#include<iostream.h>
void main() {
		int x,y,m;
		cout<<"enter the numbers to be evaluated as (x^y)%m : "
			cin>>x>>y>>m;
		cout<<(power(x,y)%m);
				}
int power(int x, unsigned int y) 
{ 
    int res = 1;     // Initialize result 
   
    while (y > 0) 
    { 
         
        if (y & 1) 
            res = res*x; 
   
         
        y = y>>1;
	x = x*x; 
    } 
    return res; 
}