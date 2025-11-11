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

    if (n <= 0) {
        printf("Number of nodes must be greater than 0.\n");
        return;
    }

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


void insertAtBeginning(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}


void insertAtPosition(int data, int pos) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
      struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
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
    int n, choice, data, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    createList(n);

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(data, pos);
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
