// C program to convert a number from base 10 to any base (2 <= base <= 16)

#include <stdio.h>

char digit_to_symbol(int);
void decimal_to_any_base(int, int);

// Driver code
int main(void)
{
    int n, b;
    // Get decimal number from user
    printf("Decimal number: ");
    scanf("%d", &n);
    // Get new base from user
    printf("To base: ");
    scanf("%d", &b);
    // Convert the decimal number to the new base
    decimal_to_any_base(n, b);
    printf("\n");
}

// Gets symbol of a number
char digit_to_symbol(int n)
{
    // Numbers between 0 and 9 keep the same symbol
    if (n >= 0 && n <= 9)
    {
        return n + '0';
    }
    // Numbers from 10 are converted to letters (A, B, C...)
    return n - 10 + 'A';
}

// Converts a number from base 10 to any base (2 <= base <= 16)
void decimal_to_any_base(int n, int b)
{
    int r = n % b;
    if (n == 0)
    {
        return;
    }
    decimal_to_any_base(n / b, b);
    printf("%c", digit_to_symbol(r));
}
