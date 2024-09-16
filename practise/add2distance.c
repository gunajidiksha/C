#include<stdio.h>

struct Add{
    float inch;
    int feet;
};

void main()
{
    struct Add x1 , x2 , result ;

    // input of 1st distance in feet and inch
    printf("Enter 1st distance (in inch): ");
    scanf("%f",&x1.inch);
    printf("Enter 1st distance (in feet): ");
    scanf("%d",&x1.feet);

    // input of 2nd distance in feet and inch
    printf("\nEnter 2nd distance (in inch): ");
    scanf("%f",&x2.inch);
    printf("Enter 2nd distance (in feet): ");
    scanf("%d",&x2.feet);

    // adding of 2 results
    result.inch = x1.inch+x2.inch;
    result.feet = x1.feet+x2.feet;

    // convert inches to feet if greater than 12
    while(result.inch>=12.0){
        result.inch = result.inch-12.0;
        ++result.feet;
    }

    printf("Sum of 2 distances are : %d'  %.1f'' ", result.feet , result.inch);
}

