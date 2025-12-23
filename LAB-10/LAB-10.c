#include <stdio.h>

#define MAX 100

int hashTable[MAX];
int m;

void insert(int key) {
    int index = key % m;
    int start = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % m;
        if (index == start) {
            printf("Hash table is full\n");
            return;
        }
    }

    hashTable[index] = key;
}

void display() {
    int i;
    for (i = 0; i < m; i++) {
        if (hashTable[i] != -1)
            printf("HT[%d] = %d\n", i, hashTable[i]);
        else
            printf("HT[%d] = Empty\n", i);
    }
}

int main() {
    int n, key, i;

    printf("Enter size of hash table: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++)
        hashTable[i] = -1;

    printf("Enter number of employee records: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter 4-digit key: ");
        scanf("%d", &key);
        insert(key);
    }

    printf("\nHash Table Contents:\n");
    display();

    return 0;
}
