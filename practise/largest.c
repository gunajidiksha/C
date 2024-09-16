#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at a specific position in the doubly linked list
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    int currentPosition = 1;

    while (currentPosition < position - 1 && current->next != NULL) {
        current = current->next;
        currentPosition++;
    }

    if (position == 1) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    } else {
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
}

// Function to delete a node at a specific position in the doubly linked list
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }

    struct Node* current = *head;
    int currentPosition = 1;

    while (currentPosition < position && current != NULL) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Invalid position for deletion.\n");
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
}

// Function to traverse the doubly linked list in forward direction
void traverseForward(struct Node* head) {
    printf("Forward traversal: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to traverse the doubly linked list in backward direction using bubble sort
void traverseBackwardBubbleSort(struct Node* head) {
    int swapped;
    struct Node* last = NULL;

    // Bubble sort to traverse backward
    do {
        swapped = 0;
        struct Node* current = head;

        while (current->next != last) {
            if (current->data > current->next->data) {
                // Swap data
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);

    printf("Backward traversal (using bubble sort): ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the doubly linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct Node* head = NULL;
    int size, data, position, choice;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Get array elements from the user
    printf("Enter the array elements:\n");
    for (int i = 0; i < size; ++i) {
        scanf("%d", &data);
        insertAtPosition(&head, data, i + 1);
    }

    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at specific position\n");
        printf("2. Delete at specific position\n");
        printf("3. Traverse in forward direction\n");
        printf("4. Traverse in backward direction (using bubble sort)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 2:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 3:
                traverseForward(head);
                break;
            case 4:
                traverseBackwardBubbleSort(head);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

        if (choice == 5) {
            break;
        }
    }

    // Free the memory allocated for the doubly linked list
    freeList(head);

    return 0;
}


