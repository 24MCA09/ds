//write a program to implemeet stack using on a singly linked list creation
//push
//pop
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
        printf(" Inserted at the end\n");
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
void deletelast(){
struct node *ptr,*ptr1;
if (head == NULL){
        printf("underflow\n");
    }
else if(head->next == NULL){
head=NULL;
free(head);
}    
 else{
 ptr=head;
 while(ptr->next!=NULL){
ptr1=ptr;
ptr=ptr->next;
}
printf("%d",ptr->data);
printf(" Deleted from the End\n");
ptr1->next=NULL;
free(ptr);
   //traverseList() ;
 }   
}





//main function
void main(){
    int o,n,t=5,item,key,count;
    printf("Stack using Singly linkedlist\n");
    while(t>0){
        printf("\n1.push into the stack\n2.pop from the stack\n3.traversal\n4.Exit\n");	
        printf("Enter Option : ");
        scanf("%d",&o);
        switch(o){
            case 1: printf("Enter Element : ");
                scanf("%d",&item);
                insertEnd(item);
                break;
            case 2: 
            deletelast();
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




