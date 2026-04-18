//Problem: Detect cycle in directed graph using DFS and recursion stack.  
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (directed)
void addEdge(int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = adj[src];
    adj[src] = newNode;
}

// DFS function to detect cycle
bool dfsCycle(int v, bool visited[], bool recStack[]) {
    visited[v] = true;
    recStack[v] = true;

    struct Node* temp = adj[v];
    while (temp != NULL) {
        int neighbor = temp->vertex;

        if (!visited[neighbor]) {
            if (dfsCycle(neighbor, visited, recStack))
                return true;
        }
        else if (recStack[neighbor]) {
            return true; // cycle found
        }

        temp = temp->next;
    }

    recStack[v] = false; // remove from recursion stack
    return false;
}

// Main function to check cycle
bool isCyclic(int V) {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfsCycle(i, visited, recStack))
                return true;
        }
    }
    return false;
}

// Driver code
int main() {
    int V = 4;

    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 1); // creates cycle

    if (isCyclic(V))
        printf("Cycle detected\n");
    else
        printf("No cycle\n");

    return 0;
}
