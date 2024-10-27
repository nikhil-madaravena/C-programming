#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int stackIndex = -1;

void addEdge(int u, int v) {
    adj[u][v] = 1;
}

void topologicalSortUtil(int v, int numVertices) {
    visited[v] = 1;
    for (int i = 0; i < numVertices; i++) {
        if (adj[v][i] && !visited[i]) {
            topologicalSortUtil(i, numVertices);
        }
    }
    stack[++stackIndex] = v;
}

void topologicalSort(int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, numVertices);
        }
    }

    while (stackIndex >= 0) {
        printf("%d ", stack[stackIndex--]);
    }
    printf("\n");
}

int main() {
    int numVertices = 6;

    addEdge(5, 2);
    addEdge(5, 0);
    addEdge(4, 0);
    addEdge(4, 1);
    addEdge(2, 3);
    addEdge(3, 1);

    printf("Topological Sort: ");
    topologicalSort(numVertices);

    return 0;
}
