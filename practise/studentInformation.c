// Store information of a student
#include<stdio.h>

struct Student{
    int rollno;
    char name[20];
    float percentage;
};

int main()
{
    int n;
    printf("Enter number of students : ");
    scanf("%d" , &n);

    struct Student x[n];

    for(int i=0 ; i<n ; i++){
        printf("\nFor student %d\n" , i+1);
        printf("Enter roll no : ");
        scanf("%d" , &x[i].rollno);
        printf("Enter name : ");
        scanf("%s" , &x[i].name);
        printf("Enter marks : "); 
        scanf("%f" , &x[i].percentage);
    }

    printf("\n The details of students are : \n\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("Roll No\t\t\t|\t\t\tName\t\t\t|\t\t\tPercentage\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");
    for(int i=0 ; i<n ; i++){
         printf("%d\t\t\t|\t\t\t%s\t\t\t|\t\t\t%f\n",x[i].rollno , x[i].name, x[i].percentage);
    }
    printf("-------------------------------------------------------------------------------------------------------------\n");
}