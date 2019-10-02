#include <stdio.h>

int main()
{
    printf ("Enter number of elements : ");
    long n; //stores size of array
    scanf ("%ld",&n);
    long array [n];
    int max = 0;
    printf("Enter array elements : ");
    for(long i=0; i<n; i++) {
        scanf("%ld",&array[i]); //input for array[]
        if (array[i] > max) max = array[i];
    }
    long count[max+1];
    for (int i=0; i<max+1; i++) count[i]=0;
    for(long i=0; i<n; i++) count[array[i]]++; //updating count[] array to hold repetitions of array[] elements
    printf ("Enter value of k : ");
    long k;
    scanf("%ld",&k);
    long i = max+1;
    while (k>0 && i>0) k -= count[--i];
    long answer = i;
    printf("The kth largest element is : %ld\n",answer);
}