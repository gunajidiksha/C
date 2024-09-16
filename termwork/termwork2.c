#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct Student {
    char name[50];
    int cetRank;
    char branch[20];
};

void readData(struct Student s[],int n);
void printData(struct Student s[],int n);
void segregate(struct Student s[],int n,char target[]);

int main(){
    int n;
    printf("Enter a number of student : ");
    scanf("%d",&n);
    struct Student s[n];
    readData(s,n);
    printData(s,n);
    segregate(s,n,"cse");
    segregate(s,n,"ec");
    segregate(s,n,"ee");
    segregate(s,n,"mech");
    segregate(s,n,"civil");
}

void readData(struct Student s[],int n){
    printf("Enter the data of Students \n");
    for(int i =0;i<n;i++){
        printf("Enter the name of student %d  : ",i+1);
        scanf("%s",s[i].name);
        printf("Enter the cet rank of student %d : ",i+1);
        scanf("%d",&s[i].cetRank);
        printf("Enter the branch of the student %d : ",i+1);
        scanf("%s",s[i].branch);
    }
}

void printData(struct Student s[],int n){
    printf("\n---------------------Student's Details-----------------------------------------------\n");
    printf("sl.no\t\t\tName\t\t\tCetRank\t\t\tBranch\n");
    for(int i =0;i<n;i++){
        printf("%d\t\t\t%s\t\t\t%d\t\t\t%s\n",i+1,s[i].name,s[i].cetRank,s[i].branch);
    }
}

void segregate(struct Student s[],int n,char target[20]){
    printf("\n---------------------details of %s students------------------------------------------\n",target);
    printf("sl.no\t\t\tname\t\t\tCetRank\n");
    for(int i =0 ;i<n;i++){
        if(strcasecmp(s[i].branch,target)==0){
            printf("%d\t\t\t\%s\t\t\t\%d\n",i+1,s[i].name,s[i].cetRank);
        }
    }
}