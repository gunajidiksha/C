#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* left;
    struct Node* right;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;

    if (rear == NULL && front == NULL) { 
        front = rear = newNode;
    } else {
        rear->next = newNode; 
        rear = newNode;
    }
}

int dequeue() {
    if (rear == NULL && front == NULL) {
        printf("Queue is Empty\n");
        return -1; 
    } else {
        int x = front->data;
        struct Node* temp = front;
        front = front->next;

        if (front == NULL) 
            rear = NULL;

        free(temp);
        return x;
    }
}

void displayQueue() {
    if (rear == NULL && front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void bfs(struct Node* root){
    struct Node* temp;
    while(front != rear){
        printf("%d ",temp->data);
        if(temp->left != NULL){
            enqueue(temp->left);
        }
        if(temp->right != NULL){
            enqueue(temp->right);
        }
        printf("\n");
    }
}

int main() {
    int choice, data;

    do {
        printf("\n1. Enqueue Element\n");
        printf("2. Dequeue Element\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("5. bfs\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 5: bfs(data);
                    break;
            default:
                break;
        }

    } while (choice != 8);

    return 0;
}
