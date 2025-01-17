#include <stdio.h>
#include <stdlib.h>

// Node structure for circular linked list
struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head;

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
    head->next = head;  // Circular link
    head->prev = head;

    temp = head;

    for (i = 2; i <= n; i++) {
        newNode = (struct node *)malloc(sizeof(struct node));

        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;

        // Update links for circular structure
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
    } while (temp != head); // Stop when we circle back to the head
    printf("(circular)\n");
}

// Delete from the beginning
void deleteFirst() {
    struct node *temp;

    if (head == NULL) {
        printf("Underflow\n");
        return;
    }

    if (head->next == head) {
        printf("%d Deleted from the Front\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    head->prev->next = head->next;
    head->next->prev = head->prev;
    head = head->next;

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

    if (head->next == head) {
        printf("%d Deleted from the End\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head->prev;

    temp->prev->next = head;
    head->prev = temp->prev;

    printf("%d Deleted from the End\n", temp->data);
    free(temp);
    traverseList();
}

// Delete a node with a specific key
void delete_p_node(int key) {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    do {
        if (temp->data == key) {
            if (temp == head && temp->next == head) {
                // Single node in the list
                printf("%d deleted from the list\n", temp->data);
                free(head);
                head = NULL;
                return;
            }

            if (temp == head) {
                // Deleting the head node
                deleteFirst();
                return;
            }

            if (temp->next == head) {
                // Deleting the last node
                deleteLast();
                return;
            }

            // Deleting a node in the middle
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            printf("%d deleted from the list\n", temp->data);
            free(temp);
            traverseList();
            return;
        }

        temp = temp->next;
    } while (temp != head);

    printf("Node with key %d does not exist\n", key);
}

// Main function
void main() {
    int o, n, key, t = 6;
    while (t > 0) {
        printf("\n1. Create Circular Linked List\n2. Delete Node at Front\n3. Delete Node at End\n4. Delete Node at a Position\n5. Traverse the Nodes\n6. Exit\n");
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
