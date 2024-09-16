#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head , int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    // newNode->next = NULL;

    struct Node* temp = *head;

    if(*head==NULL){
        newNode->next = newNode;  
        *head = newNode;
    }else{
        while(temp->next != *head){
            temp=temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

void insertAtEnd(struct Node** head , int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next=NULL;

    struct Node* temp= *head;

    if(*head == NULL){
        newNode->next = newNode;
        *head=newNode;
    }else{
        while(temp->next != *head){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next = *head;
    } 
        
}

void insertAtPosition(struct Node** head , int data , int position){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
     newNode->data = data;
     newNode->next =NULL;

     struct Node* temp=*head;

     if(*head==NULL){
            newNode->next = newNode;
            newNode = *head; 
     }
     else if(position==1){
        while(temp->next!=*head){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next = *head;
        *head=newNode;
     }else{
        for(int i=1 ; i<position-1 && temp->next!=*head ; i++){
            temp = temp->next;     
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}

void deleteAtBeginning(struct Node** head){
    struct Node* temp= (*head)->next;
    struct Node* before= *head;
    
    if(*head==NULL){
        printf("Deletion not possible as list is empty\n");
    }
    else if((*head)->next==NULL){
        int x=(*head)->data;
        *head = NULL;
        free(*head);
    }
    else{
        while(temp!=*head){
            before=temp;
            temp=temp->next;
        }
        *head = (*head)->next;
        before->next=*head;
        free(temp);
    }                                                    
}

void deleteAtEnd(struct Node** head){
    struct Node* before=NULL;
    struct Node* curr= *head;

    if(*head==NULL){
        printf("Deletion not possible as list is empty\n");
    }else {
        while(curr->next!=*head){
            before=curr;
            curr=curr->next;
        }
        before->next =*head;
        free(curr);
    }
}

void deleteAtPosition(struct Node* head , int position){
    struct Node* temp = head;
    struct Node* before = NULL;

    if(head==NULL){
        printf("Deletion is not possible as list is empty\n");
    }else{
        for(int i=1 ; i<=position-1 ; i++){
            before=temp;
            temp=temp->next;
        }
        before->next=temp->next;
        free(temp);
    }
}

void display(struct Node* head){
    struct Node* temp = head;

    while(temp->next!= head){
        printf("%d\n" , temp->data);
        temp=temp->next;
    }
    printf("%d\n" , temp->data);
    printf("\n");
}

int main()
{
    struct Node* head =NULL;
    int position , choice , data;

    do{
        printf("\n1.Insert at beginning\n");
        printf("2.Insert at end\n");
        printf("3.Insert at a specified position\n");
        printf("4.Delete at beginning\n");
        printf("5.Delete at end\n");
        printf("6.Delete at a specified position\n");
        printf("7.Display \n");
        printf("8.Exit\n");
        printf("Enter choice : ");
        scanf("%d" , &choice);

        switch(choice)
        {
            case 1: printf("Enter data to be inserted : ");
                    scanf("%d" , &data);
                    insertAtBeginning(&head , data);
                    break;
            case 2: printf("Enter data to be inserted : ");
                    scanf("%d" , &data);
                    insertAtEnd(&head , data);
                    break;
            case 3: printf("Enter data to be inserted : ");
                    scanf("%d" , &data);
                    printf("Enter position to be inserted : ");
                    scanf("%d" , &position);
                    insertAtPosition(&head , data , position);
                    break;
            case 4: deleteAtBeginning(&head);
                    break;
            case 5: deleteAtEnd(&head);
                    break;
            case 6: printf("Enter position to be deleted : ");
                    scanf("%d" , &position);
                    deleteAtPosition(head , position);
                    break;
            case 7: display(head);
                    break;
            default: break;
        }
    }while(choice!=8);
    printf("Sucessfully Exited\n");
    return 0;
}