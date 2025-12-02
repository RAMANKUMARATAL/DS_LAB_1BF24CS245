#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void createDoublyLinkedList() {
    int n, i, x;
    struct Node *temp, *newNode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = NULL;

    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &x);

        newNode = createNode(x);

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}

void insertLeftOfNode(int key, int value) {
    struct Node *current, *newNode, *prevNode;

    if (head == NULL) {
        printf("List is empty. Cannot insert.\n");
        return;
    }

    current = head;
    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Key %d not found. Cannot insert.\n", key);
        return;
    }

    newNode = createNode(value);


    if (current == head) {
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else {
        prevNode = current->prev;
        newNode->next = current;
        newNode->prev = prevNode;
        prevNode->next = newNode;
        current->prev = newNode;
    }

    printf("Inserted %d to the left of %d.\n", value, key);
}
void deleteByValue(int value) {
    struct Node *current;

    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    current = head;
    while (current != NULL && current->data != value) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Value %d not found. Nothing deleted.\n", value);
        return;
    }

    if (current->prev == NULL && current->next == NULL) {
        head = NULL;
    }
    else if (current->prev == NULL) {
        head = current->next;
        head->prev = NULL;
    }
    else if (current->next == NULL) {
        current->prev->next = NULL;
    }
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    free(current);
    printf("Node with value %d deleted.\n", value);
}

void displayList() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    printf("List (left to right): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, key, value;

    do {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create doubly linked list\n");
        printf("2. Insert a node to the left of a given value\n");
        printf("3. Delete a node by value\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createDoublyLinkedList();
                break;

            case 2:
                printf("Enter the key (value of node to the right): ");
                scanf("%d", &key);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertLeftOfNode(key, value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(value);
                break;

            case 4:
                displayList();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
