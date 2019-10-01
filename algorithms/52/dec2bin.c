#include <stdio.h>
 
oid main()
{
    long num, decimal_num, rem, base = 1, bin = 0;
    
    
    //to accept the decimal number
    
    printf("Enter a decimal integer \n");
    scanf("%ld", &num);
    decimal_num = num;
    
    
    //to convert decimal to binary
    while (num > 0)
    {
        rem = num % 2;
        bin = bin + rem * base;
        num = num / 2;
        base = base * 10;
    }
    printf("Input number is = %ld\n", decimal_num);
    printf("Its binary equivalent is = %ld\n", bin);
}
