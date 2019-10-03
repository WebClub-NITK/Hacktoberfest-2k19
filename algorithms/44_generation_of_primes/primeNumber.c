/*
 *Sieve of Eratosthenes
 */
#include <stdio.h>
#include <stdbool.h>
#define N 1000000
int main()
{
    long int l,h;
    printf("low = ");
    scanf("%ld",&l);
    printf("high = ");
    scanf("%ld",&h);
    bool prime[N] = {false};
    prime[0] = true;
    prime[1] = true;
    long long int i = 2;
    while(i*i<= N-1)
    {
        long long int j = i*i;
        while(j < N)
        {
            prime[j]=true;
            j += i;
        }
    do{
        i++;
    }
    while(prime[i]);
    }
    do
    {
        if(!prime[l])
        {
            printf("%ld",l);
            l++;
            break;
        }
        l++;
    }while(1);
    for(; l <= h; l++)
    {
        if(prime[l]==false)
        {
            printf(", %ld ", l);
        }
    }
    printf("\n");
}

