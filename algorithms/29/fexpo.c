#include<stdio.h>
#include<math.h>
int main()
{
        int a,b,m,result,pw;
        printf("Enter values of a,b,m in the expression (a^b)%m \n");
        scanf("%d %d %d",&a ,&b ,&m);
        pw=pow(a,b);
        result=pw%m;
        printf("Result=%d",result);
	return 0;
}

