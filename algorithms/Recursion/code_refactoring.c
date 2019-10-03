// C program to convert a number from base 10 to base 2

#include <stdio.h>

void decimal_to_binary(int);

// Driver code
int main(void)
{
    int n;
    scanf("%d", &n);
    decimal_to_binary(n);
}

// Converts a number from base 10 to base 2
void decimal_to_binary(int n)
{
    int r = n % 2;
    if (n == 0)
    {
        return;
    }
    decimal_to_binary(n / 2);
    printf("%d", r);
}
