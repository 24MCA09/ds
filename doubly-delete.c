#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head;

// Create nodes for a doubly linked list
void create(int n) {
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    printf("Enter the data of 1st node: ");
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;
    head->prev = NULL;

    temp = head;

    for (i = 2; i <= n; i++) {
        newNode = (struct node *)malloc(sizeof(struct node));

        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = temp;

        temp->next = newNode;
        temp = temp->next;
    }
}

// Traverse the doubly linked list
void traverseList() {
    struct node *temp;

    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Delete from the beginning
void deleteFirst() {
    struct node *temp;

    if (head == NULL) {
        printf("Underflow\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    printf("%d Deleted from the Front\n", temp->data);
    free(temp);
    traverseList();
}

// Delete from the end
void deleteLast() {
    struct node *temp;

    if (head == NULL) {
        printf("Underflow\n");
        return;
    }

    temp = head;

    // If only one node exists
    if (head->next == NULL) {
        printf("%d Deleted from the End\n", temp->data);
        free(head);
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("%d Deleted from the End\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
    traverseList();
}

// Delete a node with a specific key
void delete_p_node(int key) {
    struct node *ptr, *temp;
    int found = 0;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    // Handle deletion at the head
    while (head != NULL && head->data == key) {
        temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        printf("%d deleted from the list\n", temp->data);
        free(temp);
        found = 1;
    }

    temp = head;
    if (temp == NULL) {
        // If all nodes are deleted, exit the function
        return;
    }

    ptr = temp->next;

    // Handle deletion in the middle or end
    while (ptr != NULL) {
        if (ptr->data == key) {
            if (ptr->next != NULL) {
                ptr->next->prev = temp;
            }
            temp->next = ptr->next;
            printf("%d deleted from the list\n", ptr->data);
            free(ptr);
            ptr = temp->next;
            found = 1;
        } else {
            temp = ptr;
            ptr = ptr->next;
        }
    }

    if (!found) {
        printf("Node with key %d does not exist\n", key);
    }
}


void main() {
    int o, n, item, key, t = 6;
    while (t > 0) {
        printf("\n1. Create Doubly Linked List\n2. Delete Node at Front\n3. Delete Node at End\n4. Delete Node at a Position\n5. Traverse the Nodes\n6. Exit\n");
        printf("Enter Option: ");
        scanf("%d", &o);
        printf("\n");
        switch (o) {
            case 1:
                printf("Enter Limit: ");
                scanf("%d", &n);
                create(n);
                break;

            case 2:
                deleteFirst();
                break;

            case 3:
                deleteLast();
                break;

            case 4:
                printf("Enter Key Element to be deleted: ");
                scanf("%d", &key);
                delete_p_node(key);
                break;

            case 5:
                traverseList();
                break;

            case 6:
                printf("Exiting....\n");
                t = -5;
                break;

            default:
                printf("Enter a Valid Choice\n");
                break;
        }
    }
}
