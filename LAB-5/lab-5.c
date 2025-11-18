#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;


void createList(int n) {
    struct Node *newNode, *temp;
    int data;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}


void deleteFirst() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;
    free(temp);
    printf("First node deleted.\n");
}


void deleteLast() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL)
        head = NULL;
    else
        prev->next = NULL;

    free(temp);
    printf("Last node deleted.\n");
}


void deleteValue(int value) {
    struct Node *temp = head, *prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }

    if (prev == NULL)
        head = head->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Node with value %d deleted.\n", value);
}


void displayList() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    int n, choice, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    createList(n);

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Delete First Node\n");
        printf("2. Delete Last Node\n");
        printf("3. Delete Specific Node (by value)\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deleteFirst();
                break;
            case 2:
                deleteLast();
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteValue(value);
                break;
            case 4:
                displayList();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}
