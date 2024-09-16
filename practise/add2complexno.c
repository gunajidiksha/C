#include<stdio.h>

struct Complex{
    int real;
    int img;
};

int main()
{
    struct Complex x1 , x2 , result;

    printf("Enter Complex Number 1 \n");
    printf("Enter real part : ");
    scanf("%d" , &x1.real);
    printf("Enter img part : ");
    scanf("%d" , &x1.img);

    printf("\nEnter Complex Number 2 \n");
    printf("Enter real part : ");
    scanf("%d" , &x2.real);
    printf("Enter img part : ");
    scanf("%d" , &x2.img);

    result.real = x1.real+x2.real;
    result.img = x1.img+x2.img;

    printf("\nSum of 2 complex numbers are : %di+%d ", result.real , result.img);
}