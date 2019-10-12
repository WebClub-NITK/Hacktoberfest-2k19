#include<stdio.h>
#include<math.h>
int main()
{
  int a,b,m,k,result;
  printf("Enter a,b,m respectively\n");
  scanf("%d%d%d",&a,&b,&m);
  result=(pow(a,b));
  k=result%m;
  printf("%d",k);
  return 0;
}
