#include<stdio.h>
#define MAX 100
 int front , rear , Queue[MAX];

 void enqueue(int item){
    if((rear+1)%MAX==front){
        printf("Queue is Full\n");
    }else if(rear == -1 && front == -1){
        rear=front=0;
        Queue[rear]=item;
    }else{
        rear=(rear+1)%MAX;
        Queue[rear]=item;
    }
 }

 void dequeue(){
    if(front==-1){

        printf("Queue is Empty\n");
    }
    else if(front == rear){
        front = rear = -1;
    }
    else{
        int item = Queue[front];
        front=(front+1)%MAX;
    }
 }

 void peek(){
    if(front==-1){
        printf("Queue is Empty\n");
    }else{
        printf("Peek from front is : %d " , Queue[front]);
        printf("Peek from rear is : %d " , Queue[rear]);
    }
 }

void isEmpty(){
    if(front == -1){
        printf("Queue is Empty\n");
    }else{
        printf("queue is not empty\n");
    }
}

void isFull(){
    if(rear==(rear+1)%MAX){
        printf("Queue is Full\n");
    }else{
        printf("Queue is not full\n");
    }
}

 void display(){
    if(front==-1){
        printf("Queue is Empty\n");
    }else{
        int i=front;
        if (front<rear)
        {
            while(i!=rear){
                printf("%d ",Queue[i]);
                i=(i+1)%MAX;
            }
            printf("%d ",Queue[i]);
        }
    }
 }

int main(){
    int choice ,item;
    while(1){
        printf("\n1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.IsEmpty\n");
        printf("5.IsFull\n");
        printf("6.Display\n");
        printf("7.Exit\n");

        printf("Enter choice: ");
        scanf("%d" , &choice);

        switch(choice){
            case 1: printf("Enter value to insert: ");
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