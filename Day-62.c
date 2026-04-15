//Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.
#include <stdio.h>
#include <stdlib.h>

// Structure for adjacency list node
struct Node {
    int dest;
    struct Node* next;
};

// Structure for graph
struct Graph {
    int V;
    struct Node** adjLists;
};

// Create a new node
struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->adjLists = (struct Node**)malloc(V * sizeof(struct Node*));

    for (int i = 0; i < V; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (since undirected)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Print graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);

        while (temp) {
            printf("%d -> ", temp->dest);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main function
int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}
