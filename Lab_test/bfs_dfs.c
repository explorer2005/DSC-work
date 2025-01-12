#include <stdio.h>
#include <stdlib.h>
#define MAX 20

// Adjacency List Node Structure
struct Node {
    int vertex;
    struct Node* next;
};

// Graph Structure
struct Graph {
    struct Node* adjList[MAX];
    int visited[MAX];
    int numVertices;
};

// Function to create a new adjacency list node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the graph
void initializeGraph(struct Graph* graph, int numVertices) {
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;

    // Since the graph is undirected, add the reverse edge
    newNode = createNode(u);
    newNode->next = graph->adjList[v];
    graph->adjList[v] = newNode;
}

// Function to perform DFS
void DFS(struct Graph* graph, int vertex) {
    printf("%d ", vertex + 1); // Display vertex
    graph->visited[vertex] = 1;

    struct Node* temp = graph->adjList[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!graph->visited[adjVertex]) {
            DFS(graph, adjVertex);
        }
        temp = temp->next;
    }
}

// Function to perform BFS
void BFS(struct Graph* graph, int startVertex) {
    int queue[MAX];
    int front = -1, rear = -1;

    // Enqueue start vertex
    queue[++rear] = startVertex;
    graph->visited[startVertex] = 1;

    printf("BFS Traversal: ");
    while (front != rear) {
        int currentVertex = queue[++front]; // Dequeue vertex
        printf("%d ", currentVertex + 1);

        struct Node* temp = graph->adjList[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex]) {
                queue[++rear] = adjVertex;
                graph->visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// Main function
int main() {
    struct Graph graph;
    int choice, numVertices, numEdges, u, v, startVertex;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Graph\n");
        printf("2. DFS\n");
        printf("3. BFS\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of vertices: ");
                scanf("%d", &numVertices);
                initializeGraph(&graph, numVertices);

                printf("Enter the number of edges: ");
                scanf("%d", &numEdges);

                printf("Enter the edges (u v):\n");
                for (int i = 0; i < numEdges; i++) {
                    scanf("%d %d", &u, &v);
                    addEdge(&graph, u - 1, v - 1);
                }
                printf("Graph created successfully.\n");
                break;

            case 2:
                for (int i = 0; i < graph.numVertices; i++) {
                    graph.visited[i] = 0;
                }
                printf("Enter the starting vertex for DFS: ");
                scanf("%d", &startVertex);
                printf("DFS Traversal: ");
                DFS(&graph, startVertex - 1);
                printf("\n");
                break;

            case 3:
                for (int i = 0; i < graph.numVertices; i++) {
                    graph.visited[i] = 0;
                }
                printf("Enter the starting vertex for BFS: ");
                scanf("%d", &startVertex);
                BFS(&graph, startVertex - 1);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
