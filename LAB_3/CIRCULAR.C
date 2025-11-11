#include <stdio.h>
#define MAX 3

int queue[MAX];
int front = -1, rear = -1;

void insert(int item)
{

    if ((rear + 1) % MAX == front)
    {
        printf("Queue Overflow! Cannot insert more elements.\n");
        return;
    }


    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = item;
    printf("%d inserted into the queue.\n", item);
}

void deleteItem()
{

    if (front == -1)
    {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);


    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    int choice, item;

    while (1)
    {
        printf("\n======================== Queue Operations =======================\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &item);
            insert(item);
            break;

        case 2:
            deleteItem();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}

