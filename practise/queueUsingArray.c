#include<stdio.h>
#define MAX_SIZE 100

int front , rear , Queue[MAX_SIZE];

void enqueue(int item){
    if(rear == MAX_SIZE-1){
        printf("Queue is full\n");
    }else{
        rear = rear+1;
        Queue[rear] = item;
    }
}

void dequeue(){
    if( front == -1){
        printf("Queue is Empty\n");
    }else{
        int item = Queue[front];
        front = front+1;
        printf("Popped element is : %d\n",item);
    }
}

void peek(){
    if(front==-1 && rear==-1){
        printf("Queue is Empty\n");
    }else{
        printf("Peek value from Front : %d\n" , Queue[front]);
        printf("Peek value from Rear : %d\n" , Queue[rear]);
    }
}

void isEmpty(){
    if(front==-1){
        printf("Queue is empty\n");
    }else{
        printf("Queue is not empty\n");
    }
}

void isFull(){
    if(rear==MAX_SIZE-1){
        printf("Queue is full\n");
    }else{
        printf("Queue is not full\n");
    }
}

void display(){
    if(front==-1 && rear==-1){
        printf("Queue is Empty\n");
    }else{
        for(int i=front; i<=rear; i++){
            printf("%d ",Queue[i]);
        }
        printf("\n");
    }
}
    

int main(){
    int choice,item;

    while(1){
        printf("\n1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.IsEmpty\n");
        printf("5.IsFull\n");
        printf("6.Display\n");
        printf("7.Exit\n");

        printf("Enter choice : ");
        scanf("%d" , &choice);

        switch(choice){
            case 1: printf("Enter value to insert : ");
                    scanf("%d" , &item);
                    enqueue(item);
                    break;
            case 2: dequeue();
                    break;
            case 3: peek();
                    break;
            case 4: isEmpty();
                    break;
            case 5: isFull();
                    break;
            case 6: display();
                    break;
            case 7: printf("Exitted successfully\n");
                    break;
            default:break;
        }
    }
}
