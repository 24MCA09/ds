//write a program to implement queue using on a singly linked list 
//enqueue
//dequeue
//traversal
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head;

//create



//insert at end
void insertEnd(int item){
    struct node *ptr;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL){
        printf("Memory Insufficient\n");
    }
    else{
        temp->data=item;
        temp->next=NULL;
        if(head==NULL){
            head=temp;
        }else{
            ptr=head;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next=temp;
        }
        printf("%d",item);
        printf(" Inserted\n");
    }
}
//traverse
void traverseList()
{
    struct node *temp;

   
    if(head == NULL)
    {
        printf("List is empty.");
        return;
    }
    
    temp = head;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;                 
    }printf("NULL\n");
}
//delete fromm the front
void deletefirst(){
struct node *ptr;
    if (head == NULL){
        printf("underflow\n");
    }
    else{
    ptr=head;
    head=head->next;
    printf("%d",ptr->data);
    printf(" Deleted\n");
    free(ptr);
       traverseList() ;
    }

}





//main function
void main(){
    int o,n,t=5,item,key,count;
    printf("Queue using Singly linkedlist\n");
    while(t>0){
        printf("\n1.enqueue\n2.Dequeue\n3.traversal\n4.Exit\n");	
        printf("Enter Option : ");
        scanf("%d",&o);
        switch(o){
            case 1: printf("Enter Element : ");
                scanf("%d",&item);
                insertEnd(item);
                break;
            case 2: 
            deletefirst();
            break;
                case 3:traverseList();
                break;
            case 4: 
            printf("Exiting...\n");
            t=-1;
                break;
                
            default: 
            printf("Enter a valid option\n");
            break;
        }
    }
}




