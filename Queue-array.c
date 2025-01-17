#include<stdio.h>
int front=-1,rear=-1,size=5;

void enqueue(int *queue){
    int item;
    if(rear==size-1){
        printf("overflow");
    }
    else{
        printf("enter item:");
        scanf("%d",&item);
        
        if(front ==-1 &&rear == -1){
            front=rear=0;
        }
        else{
            rear=rear+1;
        }
        queue[rear]=item;
    }
    printf("inserted");
    printf("\n");
}


void dequeue(int *queue){
    if(front ==-1 && rear==-1){
        printf("underflow");
    }
    else{
        if(front==rear){
            front=rear=-1;
        }
        else{
            front=front+1;
        }
        printf("value deleted\n");
    }
    printf("\n");
}


void display(int *queue){
    int i;
    if(rear==-1){
        printf("Queue empty");
    }

    else{
        for(i=front;i<=rear;i++){
            printf("%d \t",queue[i]);
        }
    }
        printf("\n");
}




void main()
{
int queue[20],ch;
do
{
printf("Queue Operations\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
printf("choose an operation:\n");
scanf("%d",&ch);
switch(ch)
{
case 1:enqueue(queue);
break;
case 2:dequeue(queue);
break;
case 3:display(queue);
break;
case 4:printf("exit\n");
break;
default:printf("enter correct value\n");
break;
}
}while(ch!=4);
}




