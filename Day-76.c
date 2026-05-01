//Using DFS or BFS, count number of connected components.
#include <stdio.h>

#define MAX 100

int visited[MAX];

// DFS function
void dfs(int graph[MAX][MAX], int n, int node) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(graph, n, i);
        }
    }
}

int countComponents(int graph[MAX][MAX], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(graph, n, i);
            count++;  // one full component found
        }
    }

    return count;
}

int main() {
    int n;
    int graph[MAX][MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int components = countComponents(graph, n);
    printf("Number of connected components: %d\n", components);

    return 0;
}
