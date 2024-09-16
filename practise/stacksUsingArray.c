#include<stdio.h>
#include<stdlib.h>

int top = -1 , stack[100];

void push(int x ){
    if(top==-1){
        top++;
        stack[top]=x;
    }
    else{
        top++;
        stack[top]=x;
    }
}

void pop()
{
    if(top==-1){
        printf("Stack Underflow\n");
    }else{
        int item = top;
        stack[top--];
    }
}

void peek(){
    if(top== -1){
        printf("Stack underflow \n");
    }else{
        printf("Top Element is : %d\n" , stack[top]);
    }
}

void display()
{
    if(top==-1){
        printf("Stack underflow\n");
    }else{
        for(int i=top; i>=0 ; i--){
            printf("%d  " , stack[i]);
        }
    }
    printf("\n");
}

int main()
{
    int choice ,n , item;
    while(1){
        printf("\n1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");

        printf("Enter choice : ");
        scanf("%d" , &choice);

        switch(choice){
            case 1: printf("Enter value to be inserted : ");
                    scanf("%d" , &item);
                    push(item);
                    break;
            case 2: pop();
                    break;
            case 3: peek();
                    break;
            case 4: display();
                    break;
            case 5: printf("Program exitted successfully\n");
                    exit(0);
                    break;
            default:printf("Invalid choice\n");
                    break;
        }
    }
    return 0;
}