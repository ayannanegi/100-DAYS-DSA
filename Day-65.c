//Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];   // Adjacency matrix
bool visited[MAX];
int V; // number of vertices

// DFS function
bool dfs(int v, int parent) {
    visited[v] = true;

    for (int i = 0; i < V; i++) {
        if (graph[v][i]) {  // if edge exists
            if (!visited[i]) {
                if (dfs(i, v))
                    return true;
            }
            else if (i != parent) {
                return true; // cycle found
            }
        }
    }
    return false;
}

// Function to check cycle
bool hasCycle() {
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return true;
        }
    }
    return false;
}

// Main function
int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    // Initialize matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // undirected
    }

    if (hasCycle())
        printf("Graph contains cycle\n");
    else
        printf("Graph does not contain cycle\n");

    return 0;
}
