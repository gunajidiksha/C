#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert(struct Node** head, int value) {
    struct Node *prev, *curr;
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));

    if (newnode == NULL) {
        printf("Malloc failure");
        exit(1);
    }
    newnode->data = value;
    newnode->next = NULL;

    if (*head == NULL)
        *head = newnode;
    else if (value < (*head)->data) {
        newnode->next = *head;
        *head = newnode;
    } else {
        prev = *head;
        curr = (*head)->next;
        while (curr && value > curr->data) {
            prev = prev->next;
            curr = curr->next;
        }
        newnode->next = curr;
        prev->next = newnode;
    }
    return *head;
}

int search(struct Node* head, int item) {
    struct Node* temp = head;
    if (head == NULL) {
        printf("Warehouse is empty");
        return 0;
    }

    while (temp && (item > temp->data)) {
        temp = temp->next;
    }

    if (temp == NULL)
        return 0;

    if (item == temp->data)
        return 1;
    else
        return 0;
}

void disp(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) {
        printf("Warehouse is empty");
        return;
    }
    printf("The warehouse items are: ");
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, item;
    while (1) {
        printf("\n1: Add item ");
        printf("\n2: Display Warehouse");
        printf("\n3: Search item ");
        printf("\n4: exit");
        printf("\nEnter your option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter item to add to warehouse: ");
                scanf("%d", &item);
                insert(&head, item);
                break;
            case 2:
                disp(head);
                break;
            case 3:
                printf("Enter the item to search: ");
                scanf("%d", &item);
                if (search(head, item))
                    printf("Item %d is present in the warehouse\n", item);
                else
                    printf("Item %d is NOT present in the warehouse\n", item);
                break;
            case 4:
                exit(0);
                break;
            default:
                break;
        }
    }
    return 0;
}
