#include <stdio.h>
#include <stdlib.h>

struct node{
    int SSN;
    char Name[50];
    char Department[50];
    char Designation[50];
    float Salary;
    long PhoneNumber;
    struct node* next;
    struct node* prev;
};

struct node* head=NULL;

void insertEnd();
void display();
void countNodes();
void deleteEnd();
void insertFront();
void deleteFront();
void dequeueFront();
void dequeueEnd();

void insertEnd()
{
    struct node* p;
    p=(struct node*)malloc(sizeof(struct node));
    if(p==NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter SSN: ");
    scanf("%d", &p->SSN);
    printf("Enter Name: ");
    scanf("%s", p->Name);
    printf("Enter Department: ");
    scanf("%s", p->Department);
    printf("Enter Designation: ");
    scanf("%s", p->Designation);
    printf("Enter Salary: ");
    scanf("%f", &p->Salary);
    printf("Enter Phone Number: ");
    scanf("%ld",&p->PhoneNumber);

    p->next=NULL;

    if(head==NULL)
    {
        p->prev=NULL;
        head=p;
    }
    else
    {
        struct node* temp;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=p;
        p->prev=temp;
    }
    printf("Employee added at the end successfully.\n");

}

void display()
{
    if (head == NULL)
    {
        printf("DLL is empty.\n");
        return;
    }

    struct node* temp;
    temp = head;
    printf("\nEmployee DLL:\n");

    while (temp != NULL)
    {
        printf("SSN: %d, Name: %s, Department: %s, Designation: %s, Salary: %.2f, Phone: %ld\n",
               temp->SSN, temp->Name, temp->Department, temp->Designation, temp->Salary, temp->PhoneNumber);
        temp = temp->next;
    }
}

void countNodes()
{
    int count = 0;
    struct node* temp;
    temp = head;

    while (temp != NULL)
    {
        count=count+1;
        temp = temp->next;
    }

    printf("Number of nodes in DLL: %d\n", count);
}

void deleteEnd()
{
    if(head==NULL)
    {
        printf("DLL is empty\n");
        return;
    }
    struct node* temp=head;
    struct node* prev=NULL;

    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }

    if(prev==NULL)
    {
        free(temp);
        head=NULL;
    }
    else
    {
        prev->next=NULL;
        free(temp);
    }

    printf("Employee deleted from the end successfully.\n");
}

void insertFront()
{
    struct node* p = (struct node*)malloc(sizeof(struct node));
    if (p == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter SSN: ");
    scanf("%d", &p->SSN);
    printf("Enter Name: ");
    scanf("%s", p->Name);
    printf("Enter Department: ");
    scanf("%s", p->Department);
    printf("Enter Designation: ");
    scanf("%s", p->Designation);
    printf("Enter Salary: ");
    scanf("%f", &p->Salary);
    printf("Enter Phone Number: ");
    scanf("%ld", &p->PhoneNumber);

     p->prev = NULL;

    if (head == NULL)
    {
        p->next = NULL;
        head = p;
    }
    else
    {
        p->next = head;
        head->prev = p;
        head = p;
    }
    printf("Employee added at the front successfully.\n");

}

void deleteFront()
{
    if(head==NULL)
    {
        printf("Doubly ended queue is empty.\n");
        return;
    }
    struct node* temp;
    temp=head;

    if(temp->next==NULL)
    {
        free(temp);
        head=NULL;
    }
    else
    {
        head=temp->next;
        head->prev=NULL;
        free(temp);
    }
    printf("Employee dequeued from the front successfully.\n");

}

void dequeueFront()
{
    if(head==NULL)
    {
        printf("Doubly ended queue is empty.\n");
        return;
    }
    struct node* temp;
    temp=head;

    if(temp->next==NULL)
    {
        free(temp);
        head=NULL;
    }
    else
    {
        head=temp->next;
        head->prev=NULL;
        free(temp);
    }
    printf("Employee dequeued from the front successfully.\n");
}

void dequeueEnd()
{
    if(head==NULL)
    {
        printf("Doubly ended queue is empty.\n");
        return;
    }
    struct node* temp=head;
    struct node* prev=NULL;

    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }

    if(prev==NULL)
    {
        free(temp);
        head=NULL;
    }
    else
    {
        prev->next=NULL;
        free(temp);
    }

    printf("Employee deleted from the end successfully.\n");

}

int main()
{
    int choice;

    do{
        printf("\nMenu\n");
        printf("1.Create DLL by end insertion\n");
        printf("2.Display DLL and count nodes\n");
        printf("3.Insert at end\n");
        printf("4.Delete at end\n");
        printf("5.Insert at front\n");
        printf("6.Delete at front\n");
        printf("7.Demonstrate DLL as a Doubly ended queue at front end \n");
        printf("8.Demonstrate DLL as a Doubly ended queue at rear end\n");
        printf("9.Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:insertEnd();
                   break;
            case 2:display();
                   countNodes();
                   break;
            case 3:insertEnd();
                   break;
            case 4:deleteEnd();
                   break;
            case 5:insertFront();
                   break;
            case 6:deleteFront();
                   break;
            case 7:dequeueEnd();
                   break;
            case 8:dequeueFront();
                   break;
            case 9:printf("Exiting Program\n");
                   break;

            default:printf("Invalid choice\n");
        }
    }
    while(choice!=9);
    return 0;
}