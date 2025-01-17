//to implement the following operations on a singly linked list 
//delete from the begining
//delete from the end
//delete from the particular location
//traversal
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head;


//create node
void create(int n){
    struct node *newNode, *temp;
        int data, i;
        
    head = (struct node *)malloc(sizeof(struct node));   
             
        printf("Enter the data of 1st node : ");
        scanf("%d", &data);
        
        head->data = data;
        head->next = NULL;
        
        temp = head;
        for(i=2; i<=n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        
        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;  

        temp->next = newNode;
        temp = temp->next;   
    }
}

//traverse
void traverseList()
{
    struct node *temp;

   
    if(head == NULL)
    {
        printf("\nList is empty\n");
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
    printf(" Deleted from the Front\n");
    free(ptr);
    }
   traverseList() ;
}


//delete fromm the front
void deletelast(){
struct node *ptr,*temp;
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
temp=ptr;
ptr=ptr->next;
}
printf("%d",ptr->data);
printf(" Deleted from the End\n");
temp->next=NULL;
free(ptr);
   traverseList() ;
 }   
}


//delete particular node
void delete_p_node(int key) {
    int count=1;
    struct node *ptr, *temp;
    if (head == NULL) {
        printf("Linked List is Empty\n");
        return;
    }
    while (head != NULL && head->data == key) {
        temp = head;
        head = head->next;
        free(temp);
    }

    temp = head;
    ptr = head->next;
    
    while (ptr != NULL) {

        if (ptr->data == key) { 
        printf("%d",key);
        printf(" is deleted from position ");
        printf("%d \n",count+1);
            temp->next = ptr->next;
            free(ptr); 
            ptr = temp->next; 
               traverseList() ;
        } else {
            temp = ptr;
            ptr = ptr->next; 
            count++;
        }
    }
    if (temp == head && head != NULL && head->data != key) {

        printf("Node with key does not exist\n");
    }
 }



void main(){
    int o,n,item,key,s,t=6;
    while(t>0){
        printf("\n1. Create Singly Linked List\n2. Delete Node at Front\n3. Delete Node at End\n4. Delete Node at a Position\n5. Traverse the Nodes\n6. Exit\n");	
        printf("Enter Option : ");
        scanf("%d",&o);
                printf("\n");
        switch(o){
            case 1: printf("Enter Limit : ");
                    scanf("%d", &n);
                create(n);
                break;
                
            case 2:
                deletefirst(item);
                break;
            
            case 3:
                deletelast();
                break;
                
            case 4:
                printf("Enter Key Element to be deleted: ");
                scanf("%d",&key);
                delete_p_node(key);
                break;
                
            case 5: traverseList();
                break;
                break;
            case 6:
            printf("Exiting....\n");
                t=-5;
                break;
            default: 
            printf("Enter a Valid Choice\n");
            break;
        }
    }
}
