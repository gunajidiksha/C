#include<stdio.h>

void enqueue(int item)
{

}

void dequeue()
{

}

void display()
{

}

int main()
{
    int choice , item;
    while(1)
    {
        printf("\n1. Enqueue\n");    
        printf("2. Dequeue\n");    
        printf("3. Display\n");    
        printf("4. Exit\n");    
        printf("Enter choice : ");
        scanf("%d" , &choice);   

        switch(choice)
        {
            case 1: printf("Enter item to be inserted : ");
                    scanf("%d" , &item);
                    enqueue(item);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: printf("Program exitted successfully\n");
                    exit(0);
                    break;
            default:printf("Invalid choice\n");
                    break;
        } 
    }
    return 0;
}