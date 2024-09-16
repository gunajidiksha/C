#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int a , b;
    printf("Enter a: ");
    scanf("%d" , &a);
    printf("Enter b: ");
    scanf("%d" , &b);

    //using binary XOR
    a = a^b;
    b = a^b;
    a = a^b;
    printf("After swapping we get : %d and %d ", a , b);


    // Using addition and subtraction
    // a = a+b;
    // b = a-b;
    // a = a-b;
    // printf("After swapping we get : %d and %d ", a , b);
}



