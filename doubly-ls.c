#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head;

// Create nodes for a doubly linked list
void CreateNode(int n) {
    struct node *newnode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));
    temp = head;
    printf("Enter data of first node: ");
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;
    head->prev = NULL;

    for (i = 2; i <= n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data of node %d: ", i);
        scanf("%d", &data);

        newnode->data = data;
        newnode->next = NULL;
        newnode->prev = temp;

        temp->next = newnode;
        temp = newnode;
    }
}

// Traverse nodes in a doubly linked list
void Traverse() {
    struct node *ptr;
    if (head == NULL) {
        printf("List is Empty\n");
    } else {
        ptr = head;
        while (ptr != NULL) {
            printf("%d <-> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

// Insert node at the beginning
void insertFirst(int item) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory Insufficient\n");
    } else {
        temp->data = item;
        temp->prev = NULL;
        temp->next = head;
        if (head != NULL) {
            head->prev = temp;
        }
        head = temp;
        printf("%d Node Inserted at the front\n", item);
    }
}

// Insert node at the end
void insertEnd(int item) {
    struct node *ptr, *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory Insufficient\n");
    } else {
        temp->data = item;
        temp->next = NULL;
        if (head == NULL) {
            temp->prev = NULL;
            head = temp;
        } else {
            ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->prev = ptr;
        }
        printf("%d Node Inserted at the end\n", item);
    }
}

// Insert node after a specific key
void insert_at_p_pos(int key, int item) {
    struct node *ptr, *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory Insufficient\n");
    } else {
        temp->data = item;
        ptr = head;
        while (ptr != NULL) {
            if (ptr->data == key) {
                temp->next = ptr->next;
                temp->prev = ptr;
                if (ptr->next != NULL) {
                    ptr->next->prev = temp;
                }
                ptr->next = temp;
                printf("Node Inserted after %d\n", key);
                return;
            }
            ptr = ptr->next;
        }
        printf("Key not found\n");
    }
}

// Search for an element in the list
int search(int item) {
    struct node *ptr = head;
    int count = 1;
    while (ptr != NULL) {
        if (ptr->data == item) {
            return count;
        }
        ptr = ptr->next;
        count++;
    }
    return 0;
}

// Main function
void main() {
    int o, n, t = 5, item, key, count;
    while (t > 0) {
        printf("\n1. Create Doubly Linked List\n2. Insert Node at Front\n3. Insert Node at End\n4. Insert Node at a Position\n5. Traverse the Nodes\n6. Search a Node\n7. Exit\n");
        printf("Enter Option: ");
        scanf("%d", &o);
        switch (o) {
            case 1:
                printf("Enter Limit: ");
                scanf("%d", &n);
                CreateNode(n);
                break;

            case 2:
                printf("Enter Element: ");
                scanf("%d", &item);
                insertFirst(item);
                break;

            case 3:
                printf("Enter Element: ");
                scanf("%d", &item);
                insertEnd(item);
                break;

            case 4:
                printf("Enter Element to Insert: ");
                scanf("%d", &item);
                printf("Enter Key Element: ");
                scanf("%d", &key);
                insert_at_p_pos(key, item);
                break;

            case 5:
                Traverse();
                break;

            case 6:
                printf("Enter Element: ");
                scanf("%d", &item);
                count = search(item);
                if (count != 0) {
                    printf("\nElement Found at position %d\n", count);
                } else {
                    printf("Element is not in the list\n");
                }
                break;

            case 7:
                printf("Exiting...\n");
                t = -1;
                break;

            default:
                printf("Enter a valid option\n");
                break;
        }
    }
}
