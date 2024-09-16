#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *previous;
    struct Node *next;
};

void insertNode(struct Node **head, int position, int newData)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->previous = NULL;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *current = *head;
    int count = 1;

    while (count < position - 1 && current->next != NULL)
    {
        current = current->next;
        count++;
    }

    newNode->next = current->next;
    newNode->previous = current;
    if (current->next != NULL)
    {
        current->next->previous = newNode;
    }
    current->next = newNode;
}

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

    if (current->previous != NULL) {
        current->previous->next = current->next;
    } else {
        *head = current->next;
    }

    if (current->next != NULL) {
        current->next->previous = current->previous;
    }

    free(current);
}

void traverseForward(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void traverseBackward(struct Node *tail)
{
    while (tail != NULL)
    {
        printf("%d ", tail->data);
        tail = tail->previous;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    int choice, position, newData;

    do
    {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert Node\n");
        printf("2. Traverse Forward\n");
        printf("3. Traverse Backward\n");
        printf("4. Delete Node \n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter position and data for insertion: ");
            scanf("%d %d", &position, &newData);
            insertNode(&head, position, newData);
            break;
        }
        case 2:
        {
            printf("Doubly Linked List (Forward): ");
            traverseForward(head);
            break;
        }
        case 3:
        {
            struct Node *tail = head;
            while (tail != NULL && tail->next != NULL)
            {
                tail = tail->next;
            }
            printf("Doubly Linked List (Backward): ");
            traverseBackward(tail);
            break;
        }
        case 4:
        {
            printf("Enter position for deletion: ");
            scanf("%d", &position);
            deleteAtPosition(&head, position);
            break;
        }
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}