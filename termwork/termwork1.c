#include <stdio.h>
#include <stdlib.h>

void read_array(int *pa, int size);
void display_array(int *pa, int size);
int *max_element(int *pa, int size);
void reverse_array(int *pa, int size);
void search(int *pa, int size, int key);

void read_array(int *pa, int size){
    for(int i=0;i<size;i++){
        scanf("%d",pa+i); // &pa[i] is same as pa+i
    }
    printf("\n");
}

void display_array(int *pa,int size){
    for(int i=0;i<size;i++){
        printf("%d ",*(pa+i)); // as &pa[i] is as same as pa+i so when we write *(&pa[i]) means it gives value of pa[i] 
    }
    printf("\n\n");
}

int *max_element(int *pa, int size){
    int l=0,max=*pa;
    for(int i=0;i<size;i++){
        if(max<=*(pa+i)){
            l=i;
        }
    }
    return (pa+l);
}

void reverse_array(int *pa,int size){
    for(int i=size-1;i>=0;i--){
        printf("%d ",*(pa+i));
    }
    printf("\n\n");
}

void search(int *pa, int size, int key){
    int i;
    for(i=0;i<size;i++){
        if(key == *(pa+i))
            printf("%d\n",(pa+i));
    }
    printf("\n");
}

int main()
{
    int option,n;
    int *a, k=0;
    printf("Enter size of array: ");
    scanf("%d",&n);
    a= (int*)calloc(n,sizeof(int));
    do{
        printf("Menu operations\n");
        printf("Press 1: Read array\n");
        printf("Press 2: Display array using pointers\n");
        printf("Press 3: Find max element of array using pointers\n");
        printf("Press 4: Reverse the Array using pointers\n");
        printf("Press 5: Search the element in an array by returning address to the called function\n");
        printf("Press 6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&option);
        switch(option){
            case 1: printf("Enter the elements of array:\n");
                    read_array(a, n);
                    break;
            case 2: printf("Given array is: ");
                    display_array(a,n);
                    break;
            case 3: printf("Max element= %d",*max_element(a,n));
                    printf("\n\n");
                    break;
            case 4: printf("The reversed array is given below: \n");
                    reverse_array(a,n);
                    break;
            case 5: printf("Enter element to be searched: ");
                    scanf("%d",&k);
                    printf("The required element '%d' occurs at following addresses: ",k);
                    search(a,n,k);
                    break;
            case 6: printf("Exitting program!\n");
                    break;
            default: printf("Invalid choice!!\n");
        }
    }while(option!=6);
    return 0;
}