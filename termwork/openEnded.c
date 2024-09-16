#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* findMiddleNode(struct Node* head) {
    struct Node *ptr1 = head;
    struct Node *ptr2 = head;

    if (head != NULL) {
        while (ptr2 != NULL && ptr2->next != NULL) {
            ptr2 = ptr2->next->next;
            ptr1 = ptr1->next;
        }
        return ptr1;
    }
    return NULL;
}

void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Insert element\n");
        printf("2. Find Middle Node\n");
        printf("3. Print Linked List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                printf("Element %d inserted at the beginning.\n", data);
                break;

            case 2:
                if (head != NULL) {
                    struct Node* middleNode = findMiddleNode(head);
                    printf("Middle Node: %d\n", middleNode->data);
                } else {
                    printf("The list is empty.\n");
                }
                break;

            case 3:
                printf("Linked List: ");
                printList(head);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
