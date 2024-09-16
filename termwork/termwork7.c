// 7
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct Node {
    int data;                        
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with a given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }else{
        return;
    }
    return root;
}

// Function to search for a node in the BST
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function for in-order traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function for pre-order traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function for post-order traversal
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, item;
    struct Node* result;

    do {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert a node\n");
        printf("2. Search for a node\n");
        printf("3. In-order traversal\n");
        printf("4. Pre-order traversal\n");
        printf("5. Post-order traversal\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:      
                printf("Enter the number to insert: ");
                scanf("%d", &item);
                root = insert(root, item);
                break;

            case 2:    
                printf("Enter the number to search: ");
                scanf("%d", &item);
                result = search(root, item);
                if (result != NULL) {
                    printf("Node with number %d found.\n", item);
                } else {
                    printf("Node with number %d not found.\n", item);
                }
                break;

            case 3:    
                printf("In-order traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4:           
                printf("Pre-order traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 5:          
                printf("Post-order traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 0:              
                printf("Exiting the program.\n");
                break;

            default:     
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    return 0;
}
