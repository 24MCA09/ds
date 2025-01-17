#include <stdio.h>
#include <stdlib.h>

// Node structure for circular linked list
struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

// Create nodes for a circular linked list
void create(int n) {
    struct node *newNode, *temp;
    int data, i;

    if (n <= 0) {
        printf("Invalid size for the list\n");
        return;
    }

    head = (struct node *)malloc(sizeof(struct node));

    printf("Enter the data of 1st node: ");
    scanf("%d", &data);

    head->data = data;
    head->next = head;
    head->prev = head;

    temp = head;

    for (i = 2; i <= n; i++) {
        newNode = (struct node *)malloc(sizeof(struct node));

        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;

        newNode->next = head;
        newNode->prev = temp;

        temp->next = newNode;
        head->prev = newNode;

        temp = newNode;
    }
}

// Traverse the circular linked list
void traverseList() {
    struct node *temp;

    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    temp = head;
    printf("List elements: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(circular)\n");
}

// Insert at the beginning
void insertAtBeginning(int data) {
    struct node *newNode, *last;

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        head->prev = newNode;
        last->next = newNode;

        head = newNode;
    }
    printf("%d inserted at the beginning\n", data);
    traverseList();
}

// Insert at the end
void insertAtEnd(int data) {
    struct node *newNode, *last;

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;
    }
    printf("%d inserted at the end\n", data);
    traverseList();
}

// Insert at a specific position
void insertAtPosition(int data, int position) {
    struct node *newNode, *temp;
    int i;

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;

    if (position == 1) {
        insertAtBeginning(data);
        return;
    }

    temp = head;

    for (i = 1; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    if (i != position - 1) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;

    printf("%d inserted at position %d\n", data, position);
    traverseList();
}

// Main function
void main() {
    int choice, n, data, position;

    while (1) {
        printf("\n1. Create Circular Linked List\n2. Insert at Beginning\n3. Insert at End\n4. Insert at a Position\n5. Traverse the List\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                create(n);
                break;

            case 2:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;

            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;

            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;

            case 5:
                traverseList();
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
