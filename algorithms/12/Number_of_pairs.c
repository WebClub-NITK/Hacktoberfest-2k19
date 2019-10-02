#include<stdio.h>
int Number_of_pairs(int *a,int n,int x)
{
 /*
   Write your code here
   Here *a is the pointer to the array,n is its number of elementsand x is the corrosponding sum.
 */
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
