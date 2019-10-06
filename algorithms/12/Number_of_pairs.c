#include<stdio.h>
int Number_of_pairs(int *a,int n,int x)
{
    int leftCursor = 0;
    int rightCursor = n-1;
    int pairs = 0;

    while(leftCursor < rightCursor) {
        const int leftNumber = a[leftCursor];
        const int rightNumber = a[rightCursor];
        const int localSum = leftNumber + rightNumber;
        if(localSum == x) {
            pairs++;
            leftCursor++;
            rightCursor--;
        } else if(localSum > x) {
            rightCursor--;
        } else {
            leftCursor++;
        }
    }

    return pairs;
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
