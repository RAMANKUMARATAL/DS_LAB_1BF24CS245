#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int n;


void DFS(int v) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }


    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }


    DFS(0);


    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            printf("Graph is NOT Connected\n");
            return 0;
        }
    }

    printf("Graph is Connected\n");
    return 0;
}
