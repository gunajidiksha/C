#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the start of the list
struct Node* addToStart(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Function to insert a new node at the end of the list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Function to display the content of the list
void displayList(struct Node* head) {
    struct Node* temp= head;
    printf("Forward List : ");
    while (temp->next != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d" ,temp->data);

    printf("\nBackward List : ");
    while(temp!=NULL){
        printf("%d " , temp->data);
        temp=temp->prev;
    }
    printf("\n");
}

// Function to search for a data item in both directions
void searchInBothDirections(struct Node* head, int key) {
    struct Node* current = head;

    // Forward search
    printf("Forward Search: ");
    while (current != NULL) {
        if (current->data == key) {
            printf("Found %d\n", key);
        }
        current = current->next;
    }

    // Backward search
    current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    printf("Backward Search: ");
    while (current != NULL) {
        if (current->data == key) {
            printf("Found %d\n", key);
            return;
        }
        current = current->prev;
    }
    printf("Not Found %d \n", key);
}

// Function to sort the list elements using Bubble Sort
void sortList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Nothing to sort.\n");
    }

    struct Node *i, *j;
    int temp;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                // Swap data if out of order
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted successfully.\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, data;

    do {
        printf("\n1. Add to the start\n");
        printf("2. Insert at the end\n");
        printf("3. Display list\n");
        printf("4. Search in both directions\n");
        printf("5. Sort the list\n");
        printf("6. Exit\n");

        printf("Enter choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to add to the start: ");
                scanf("%d", &data);
                head = addToStart(head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Enter data to search: ");
                scanf("%d", &data);
                searchInBothDirections(head, data);
                break;
            case 5 : 
                sortList(head);
                displayList(head);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);
    return 0;
}