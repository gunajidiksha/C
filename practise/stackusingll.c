#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* stack_top = NULL;

void push(int element) {
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data = element;
    if (p == NULL) {
        printf("Memory allocation not possible\n");
        return;
    }
    p->next = stack_top;
    stack_top = p;
}

void pop() {
    struct Node* temp = stack_top;

    if (temp == NULL) {
        printf("Stack is Empty\n");
        return;
    } else {
        printf("The popped element is %d\n", temp->data);
        stack_top = stack_top->next;
        free(temp);
    }
}

void displayStack() {
    struct Node* p = stack_top;
    if (p == NULL) {
        printf("Stack is Empty\n");
    } else {
        printf("STACK contents are: \n");
        while (p != NULL) {
            printf("%d\n", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

int main() {
    int choice , data;
    do{
        printf("\n1. Push Element : \n");
        printf("2. Pop Element : \n");
        printf("3. Display Element : \n");
        printf("4. Exit : \n");
        printf("Enter choice : ");
        scanf("%d" , &choice);
        switch(choice)
        {
            case 1 :printf("Enter element to insert : ");
                    scanf("%d" , &data);
                    push(data);
                    break;
            case 2 :pop();
                    break;
            case 3 :displayStack();
                    break;
            default:break;
        }
    }while(choice!=4);
    return 0;
}
