#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head;
//create node 
void CreateNode(int n){
    struct node *newnode,*temp;
    int data,i;
    
    head=(struct node *)malloc(sizeof(struct node));
    temp=head;
    printf("enter data of first node :");
    scanf("%d",&data);
    
    head->data=data;
    head->next=NULL;
    
    for(i=2;i<=n;i++){
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter data of node %d :",i);
        scanf("%d",&data);
        
        newnode->data=data;
        newnode->next=NULL;
        
        temp->next=newnode;
        temp=newnode;
    }
    
}





//traversal
void Traverse(){
    struct node *ptr;
    if(head == NULL){
        printf("List is Empty");
    }
    else{
        ptr=head;
        while (ptr!=NULL){
        printf("%d -> ",ptr->data);
        ptr=ptr->next;
        }
        printf("NULL");
    }
    }
    
    
    
    void insertFirst(int item){
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        if(temp == NULL){
        printf("memory Insufficient");
        }
        else{
            temp->data=item;
            if(head==NULL){
                temp->next=NULL;
                head=temp;
            }
            else{
                temp->next=head;
                head=temp;
            }
            
        }
        printf("%d",item);
        printf(" Node Inserted at the front\n");
        }
    
    
    void insertEnd(int item){
        struct node *ptr;
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        
        if(temp==NULL){
            printf("Insufficient space\n");
        }
        else{
            temp->data=item;
            temp->next=NULL;
        if(head==NULL){
            head=temp;
        }
        else{
            ptr=head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=temp;
            }
                printf("%d",item);
                printf(" Node Inserted at the end\n");
        }
    }
    
    void insert_at_p_pos(int key,int item){
        struct node *ptr;
        struct node *temp=(struct node *)malloc((sizeof(struct node)));
        
        if(temp == NULL){
        printf("memory Insufficient");
        }
        else{
            temp->data=item;
            if(head==NULL){
                temp->next=NULL;
                head=temp;
                printf("node inserted as head");
            }
            else{
                ptr=head;
                while(ptr!=NULL){
                    if(ptr->data==key){
                        temp->next=ptr->next;
                        ptr->next=temp;
                    }
                    ptr=ptr->next;
                }
            }
        }
    }
    int search(int item){
    struct node *ptr = head;
    int count=1;
    while(ptr != NULL){
        if(ptr->data == item){
            return count;
        }else{
            ptr =ptr->next;
            count++;
        }
    }return count;
}

//main function
void main(){
    int o,n,t=5,item,key,count;
    while(t>0){
        printf("\n1. Create Singly Linked List\n2. Insert Node at Front\n3. Insert Node at End\n4. Insert Node at a Position\n5. Traverse the Nodes\n6. Search a Node\n7. Exit\n");	
        printf("Enter Option : ");
        scanf("%d",&o);
        switch(o){
            case 1: printf("Enter Limit : ");
                    scanf("%d", &n);
                CreateNode(n);
                break;
                
            case 2: printf("Enter Element : ");
                scanf("%d",&item);
                insertFirst(item);
                break;
            
            case 3: printf("Enter Element : ");
                scanf("%d",&item);
                insertEnd(item);
                break;
                
            case 4: printf("Enter Element to Insert : ");
                scanf("%d",&item);
                printf("Enter Key Element : ");
                scanf("%d",&key);
                insert_at_p_pos(key,item);
                break;
                
            case 5: Traverse();
                break;
            
            case 6: printf("Enter Element : ");
                scanf("%d",&item);
                count = search(item);
                if(count!=0){
                    printf("\nElement Found at position %d",count);
                    printf("\n");
                }else{
                    printf("Element is not in list\n");
                }
                break;
                
            case 7: 
            printf("Exiting...");
            t=-1;
                break;
                
            default: 
            printf("Enter a valid option\n");
            break;
        }
    }
}
    
    
    
    
    
    
    