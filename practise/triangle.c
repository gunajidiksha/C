#include<stdio.h>

int main()
{
    int a , b , c;
    printf("Enter a : ");
    scanf("%d" , &a);
    printf("Enter b : ");
    scanf("%d" , &b);
    printf("Enter c : ");
    scanf("%d" , &c);

    // if((a>10) && (b>10) && (c>10)){
    //     printf("Out Of Range");
    // }
    // else {
        if(((a+b)>c) && ((b+c)>a) && ((c+a)>b))
        {
            if(a==b && b==c && a==c)
            {
                printf("The triangle formed is Equilateral triangle ");
            }
            else if(a!=b && b!=c && a!=c)
            {
                printf("The triangle formed is Scalene triangle");
            }
            else 
            {
                printf("The triangle formed is Isoceles triangle");
            }
        }
        else
        {
            
            printf("Not a Triangle");
        }
        return 0;
    }
    
// }