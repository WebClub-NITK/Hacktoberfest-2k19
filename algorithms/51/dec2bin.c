#include <stdio.h>
int main (void){

    int number;

    int i=0,j=0;

    int binary[100];

    //INPUT.
    scanf("%d",&number);

    //assigning binary.
    while (number>0){
        binary[i]=number%2;
        number=number/2;
        i=i+1;
    }
    //printing binary from reverse.
    for (j=i-1;j>=0;j--){
        printf("%d",binary[j]);

    }return 0;
}
