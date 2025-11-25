#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};


struct Node* createNode(int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}


void push(struct Node **top, int val) {
    struct Node *newNode = createNode(val);
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed to stack.\n", val);
}


int pop(struct Node **top) {
    if (*top == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    }
    struct Node *temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}


void displayStack(struct Node *top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}


struct Node *front = NULL;
struct Node *rear = NULL;


void enqueue(int val) {
    struct Node *newNode = createNode(val);
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued.\n", val);
}


int dequeue() {
    if (front == NULL) {
        printf("Queue Underflow!\n");
        return -1;
    }
    struct Node *temp = front;
    int val = temp->data;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
    return val;
}


void displayQueue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node *temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}



int main() {
    struct Node *stackTop = NULL;
    int choice, val;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue (Queue)\n");
        printf("5. Dequeue (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            push(&stackTop, val);
            break;

        case 2:
            val = pop(&stackTop);
            if (val != -1) printf("Popped: %d\n", val);
            break;

        case 3:
            displayStack(stackTop);
            break;

        case 4:
            printf("Enter value: ");
            scanf("%d", &val);
            enqueue(val);
            break;

        case 5:
            val = dequeue();
            if (val != -1) printf("Dequeued: %d\n", val);
            break;

        case 6:
            displayQueue();
            break;

        case 7:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
