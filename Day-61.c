//Build a graph with n vertices and m edges using adjacency matrix representation.The graph may be directed or undirected.
#include <stdio.h>

int main() {
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Declare adjacency matrix
    int adj[n][n];

    // Initialize matrix with 0
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    int choice;
    printf("Enter 1 for Directed Graph, 2 for Undirected Graph: ");
    scanf("%d", &choice);

    printf("Enter edges (u v):\n");
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;

        // If undirected graph
        if(choice == 2) {
            adj[v][u] = 1;
        }
    }

    // Display adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
