#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct node **head, int data) {
    struct node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


void sortList(struct node *head) {
    struct node *i, *j;
    int temp;

    for (i = head; i != NULL && i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}


struct node* reverseList(struct node *head) {
    struct node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}


struct node* concat(struct node *head1, struct node *head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct node *temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

int main() {
    struct node *head1 = NULL, *head2 = NULL;
    int choice, value;

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Sort List 1 (FOR loop only)\n");
        printf("6. Reverse List 1\n");
        printf("7. Concatenate List 1 and List 2\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertEnd(&head1, value);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertEnd(&head2, value);
            break;

        case 3:
            printf("List 1: ");
            display(head1);
            break;

        case 4:
            printf("List 2: ");
            display(head2);
            break;

        case 5:
            sortList(head1);
            printf("List 1 sorted.\n");
            break;

        case 6:
            head1 = reverseList(head1);
            printf("List 1 reversed.\n");
            break;

        case 7:
            head1 = concat(head1, head2);
            printf("Lists concatenated — Now List 1: ");
            display(head1);
            break;

        case 8:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
