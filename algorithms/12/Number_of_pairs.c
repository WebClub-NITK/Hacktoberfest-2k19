#include<stdio.h>
int Number_of_pairs(int *a,int n,int x)
{
      int i,j,count=0;
        for(i=0;i<n;++i)
        for(j=i+1;j<n;++j)
                if(a[i]+a[j]==x)
                        ++count;
        return count;
}
int main()
{
 int n;
 scanf("%d",&n);
 int i,x,a[n];
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 scanf("%d",&x);
 printf("%d", Number_of_pairs(a,n,x));
}
