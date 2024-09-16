#include<stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head , int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next=NULL;

    if(*head==NULL){
        *head = newNode;
    }else {
        newNode->next = *head;
        *head = newNode;
    }  
}

void insertAtEnd(struct Node** head , int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if(*head==NULL){
        *head = newNode;
    }else if((*head)->next == NULL){
        (*head)->next=newNode;
    }else{
        struct Node* temp = *head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
    
}

void insertANode(struct Node** head , int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    struct Node* prev;
    struct Node* curr;
  
    if(*head==NULL){
        *head = newNode;
    }else if(data < (*head)->data){
        newNode->next= *head;
        *head = newNode;
    }else{
        prev=NULL;
        curr= *head;

        while(curr != NULL && data >= curr->data){ 
            prev=curr;
            curr=curr->next;
        }
        prev->next=newNode;
        newNode->next=curr;
    }
    
}

void insertAtPosition(struct Node** head , int data , int position){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    struct Node* prev = NULL;
    struct Node* curr = *head;

    if(*head == NULL || position == 1){
        *head = newNode;
    }
    // else if((*head)->next== NULL){
    //     (*head)->next=newNode;
    // }
    else{
        for(int i=1 ; i<=position-1 ; i++){
            prev=curr;
            curr=curr->next;
        }
        prev->next=newNode;
        newNode->next=curr;
    }
}

void deleteAtBeginning(struct Node** head){
    struct Node* temp = *head;
    if(*head == NULL){
        printf("Deletion NOt Possible as List is empty \n");
    }else if((*head)->next == NULL){
        temp->next = *head;
        *head = NULL;
        free(temp);
    }else{
        *head = (*head)->next;
        free(temp);
    }
}

void deleteAtEnd(struct Node** head){
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if(*head == NULL){
        printf("Deletion NOt Possible as List is empty \n");
    }else if((*head)->next == NULL){
        temp->next = *head;
        *head = NULL;
        free(temp);
    }else{
        while(temp->next != NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        free(temp);
    }
}

void deleteANode(struct Node** head , int data){
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if(*head == NULL){
        printf("Deletion Not Possible as List is empty \n");
    }else if((*head)->next == data){
        *head = (*head)->next;
        free(temp);
    }else{
        prev = NULL;
        temp = *head;
        while(temp!=NULL && data!= temp->data){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        free(temp);
    }
}

void deleteAtPosition(struct Node** head , int position){
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if(*head==NULL){
        printf("Deletion not possible as list is empty \n");
    }else if((*head)->next == NULL){
        *head = (*head)->next;
        free(temp);
    }else if(position == 1){
        *head=NULL;
        free(temp);
    }else{
        for(int i=1 ; i<=position-1 && temp!=NULL; i++){
            prev=temp;
            temp=temp->next;
        }

        if(temp==NULL){
            printf("Deletion not possible \n");
        }else{
            prev->next=temp->next;
            free(temp);
        }
    }
}

void display(struct Node* head){
    struct Node* temp = head;
    while(temp!= NULL){
        printf("%d \n" , temp->data);
        temp = temp->next;
    }
    printf("\n");
}
    

int main()
{
    struct Node* head = NULL;
    int data , choice , position;
    
    
    do{
        printf("\n1. Insert At Beginning \n");
        printf("2. Insert At End \n");
        printf("3. Insert A Node (ordered list) \n");
        printf("4. Insert A Node (in ordered list) \n");
        printf("5. Delete At Beginning \n");
        printf("6. Delete At End \n");
        printf("7. Delete A Node (ordered list) \n");
        printf("8. Delete A Node (in ordered list) \n");
        printf("9. Display \n");
        printf("10. Exit \n");
        printf("Enter choice : ");
        scanf("%d" , &choice);
    
        switch(choice)
        {
            case 1 :printf("Enter the value to be inserted : ");
                    scanf("%d" , &data);
                    insertAtBeginning(&head , data);
                    break;
            case 2 :printf("Enter the value to be inserted : ");
                    scanf("%d" , &data);
                    insertAtEnd(&head , data);
                    break;
            case 3 :printf("Enter the value to be inserted : ");
                    scanf("%d" , &data);
                    insertANode(&head , data);
                    break;
            case 4 :printf("Enter the value to be inserted : ");
                    scanf("%d" , &data);
                    printf("Enter position : ");
                    scanf("%d" , &position);
                    insertAtPosition(&head , data , position);
                    break;
            case 5 :deleteAtBeginning(&head);
                    break;
            case 6 :deleteAtEnd(&head);
                    break;
            case 7 :printf("Enter the value to be deleted : ");
                    scanf("%d" , &data);
                    deleteANode(&head , data);
                    break;
            case 8 :printf("Enter the position to be deleted : ");
                    scanf("%d" , &position);
                    deleteAtPosition(&head , position);
                    break;
            case 9 :display(head);
                    break;
            case 10 :printf("Exitted successfully");
                    exit(0);
                    break;
            default :break;
        }
    }while(choice!=0);
    return 0;
}