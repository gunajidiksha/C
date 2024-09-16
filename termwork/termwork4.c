#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;

    if (front == NULL && rear == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

int dequeue() {
    if (front == NULL && rear == NULL) {
        return -1;
    } else {
        int item = front->data;
        struct Node* temp = front;
        front = front->next;
       
        if (front == NULL) {
            rear = NULL;
        }
        free(temp);
        return item;
    }
}

void display()
{
    if (front == NULL && rear == NULL) {
        printf("Queue is empty\n");
        return;
    } else {
        struct Node* temp = front;
        printf("Queue elements are: ");
       
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice;
   
    while (choice != 4) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                    int value;
                    printf("Enter the value to enqueue: ");
                    scanf("%d", &value);
                    enqueue(value);
                    break;
            case 2:
                    int dequeuedItem = dequeue();
                    if (dequeuedItem == -1) {
                        printf("Queue is empty.\n Nothing to dequeue.\n");
                    } else {
                        printf("Dequeued item: %d\n", dequeuedItem);
                    }
                    break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Wrong Choice\n");
        }
    }
    return 0;
}