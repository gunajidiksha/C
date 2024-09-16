#include<stdio.h>
#include<stdlib.h>
 
struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

void insertAtBeginning(struct Node** head , int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;

    if(*head == NULL){
        *head = newNode;
    }else{
        newNode->next = *head;
        (*head)->prev = newNode;
        *head=newNode;  
    }
}

void insertAtEnd(struct Node** head , int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->prev = NULL;
    newNode->next = NULL;

    struct Node* temp=*head;
    if(*head==NULL){
        *head = newNode;
    }else if((*head)->next == NULL){
        (*head)->next = newNode;
        newNode->prev=*head;
    }else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev=temp;
    }
}

void insertAtPosition(struct Node** head , int data , int position){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;

    struct Node* before = NULL;
    struct Node* curr = *head;

    if(*head==NULL){
        *head = newNode;
    }else if((*head)->next == NULL){
        (*head)->next = newNode;
        newNode->prev=*head;
    }else{
        for(int i=1; i<=position-1 && curr!=NULL ; i++){
            before=curr;
            curr=curr->next;
        }
        before->next=newNode;
        newNode->next=curr;
    }
}

void deleteAtBeginning(struct Node** head){
    struct Node* temp=*head;

    if(*head==NULL){
        printf("Deletion Not possible as list is empty\n");
    }else if((*head)->next==NULL){
        temp->next = *head;
        *head=NULL;
        free(temp);
    }else{
        *head = (*head)->next;
        (*head)->prev=NULL;
        free(temp);
    }
}

void deleteAtEnd(struct Node** head){
    struct Node* temp = *head;
    struct Node* before = NULL;

    if(*head == NULL){
        printf("Deletion not possible\n");
    }

    while(temp->next != NULL){
        before = temp;
        temp=temp->next;
    }
    before->next=NULL;
    free(temp);

}

void deleteAtPosition(struct Node** head , int position){
    struct Node* curr = *head;
    struct Node* before = NULL;

    if(position==1 && *head == NULL){
        
        printf("Deletion not possible\n");
    }else if(position==1 && *head != NULL){
        *head = (*head)->next;
        free(curr);
    }else{
        for(int i=1 ; i<=position-1 && curr!=NULL ; i++){
            before=curr;
            curr=curr->next;
        }
        before->next = curr->next;
        free(curr);
    }   
}

void search(struct Node* head , int key){
    struct Node* temp = head;

    while(temp !=NULL){
        if(temp->data == key){
            printf("%d found sucessfully in the list\n" , key);
        }
        temp = temp->next;
    }
    printf("%d is not found in the list \n" , key);
}

void display(struct Node* head){
    struct Node* temp = head;
    while(temp!= NULL){
        printf("%d\n" , temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse(struct Node* head){
    struct Node* temp = head;

    while(temp->next != NULL){
        temp=temp->next;
    }

    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->prev;
    }
}

int main()
{
    struct Node* head=NULL;
    int data , position , choice ,key;

    
    do{
        printf("\n1.Insert at beginning \n");
        printf("2.Insert at end \n");
        printf("3.Insert at specific position \n");
        printf("4.Delete at beginning \n");
        printf("5.Delete at end \n");
        printf("6.Delete at specific position \n");
        printf("7.Searching \n");
        printf("8.Display \n");
        printf("9.Reverse\n");
        printf("10.Exit\n");
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
                    printf("Enter the position : ");
                    scanf("%d" , &position);
                    insertAtPosition(&head , data , position);
                    break;
            case 4: deleteAtBeginning(&head);
                    break;
            case 5: deleteAtEnd(&head);
                    break;
            case 6: printf("Enter the position : ");
                    scanf("%d" , &position);
                    deleteAtPosition(&head , position);
                    break;
            case 7: printf("Enter element to be searched : ");
                    scanf("%d" , &key);
                    search(head , key);
                    break;
            case 8: display(head);
                    break;
            case 9: reverse(head);
                    break;
            default:break;
        }
    }while(choice!= 10);
    printf("Sucessfully Exited! \n");

    return 0;
}