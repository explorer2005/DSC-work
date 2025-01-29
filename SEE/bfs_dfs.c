#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct node {
    int vertex;
    struct node * next;
};

struct graph {
    struct node * adjList[MAX];
    int visited[MAX];
    int numVertices;
};

struct node * create(int vertex) {
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void initializeGraph(struct graph *g, int numVertices) {
    g->numVertices = numVertices;
    for(int i = 0; i < numVertices; i++) {
        g->visited[i] = 0;
        g->adjList[i] = NULL;
    }
}

void addEdge(struct graph *g, int u, int v) {
    struct node * newNode = create(v);
    newNode->next = g->adjList[u];
    g->adjList[u] = newNode;

    newNode = create(u);
    newNode->next = g->adjList[v];
    g->adjList[v] = newNode;
}

void DFS(struct graph *g, int vertex) {
    printf("%d ", vertex + 1);
    g->visited[vertex] = 1;
    struct node *temp = g->adjList[vertex];
    while(temp != NULL) {
        int adjVertex = temp->vertex;
        if(g->visited[adjVertex] == 0) {
            DFS(g, adjVertex);
        }
        temp = temp->next;
    }
}

void BFS(struct graph *g, int startVertex) {
    int queue[MAX];
    int front = 0;
    int rear = 0;  // Changed initialization
    
    for(int i = 0; i < g->numVertices; i++) {
        g->visited[i] = 0;
    }
    
    queue[rear] = startVertex;
    g->visited[startVertex] = 1;
    
    while(front <= rear) {
        int currentVertex = queue[front];
        front++;
        printf("%d ", currentVertex + 1);
        
        struct node *temp = g->adjList[currentVertex];
        while(temp != NULL) {
            int adjVertex = temp->vertex;
            if(g->visited[adjVertex] == 0) {
                rear++;
                queue[rear] = adjVertex;
                g->visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    struct graph g;
    int t = 1;
    
    // Initialize graph with numVertices as 0
    g.numVertices = 0;
    for(int i = 0; i < MAX; i++) {
        g.adjList[i] = NULL;
        g.visited[i] = 0;
    }
    
    while(t) {
        printf("\nEnter the correct option\n1.Create Graph\n2.DFS\n3.BFS\n4.Exit\n");
        int k;
        scanf("%d", &k);
        
        switch(k) {
            case 1:
                printf("Enter the number of vertices\n");
                int numVertices;
                scanf("%d", &numVertices);
                if(numVertices <= 0 || numVertices > MAX) {
                    printf("Invalid number of vertices!\n");
                    break;
                }
                initializeGraph(&g, numVertices);
                printf("Enter the number of edges to be added\n");
                int n;
                scanf("%d", &n);
                for(int i = 0; i < n; i++) {
                    printf("Enter u v\n");
                    int u, v;
                    scanf("%d%d", &u, &v);
                    if(u >= 1 && u <= numVertices && v >= 1 && v <= numVertices) {
                        addEdge(&g, u-1, v-1);
                    } else {
                        printf("Invalid vertices, edge ignored\n");
                        i--;
                    }
                }
                printf("Graph created successfully with %d vertices\n", g.numVertices);
                break;
                
            case 2:
                if(g.numVertices == 0) {
                    printf("Please create a graph first!\n");
                    break;
                }
                for(int i = 0; i < g.numVertices; i++) {
                    g.visited[i] = 0;
                }
                printf("Enter the vertex from which DFS is to be started (1 to %d)\n", g.numVertices);
                int vertex;
                scanf("%d", &vertex);
                if(vertex < 1 || vertex > g.numVertices) {
                    printf("Invalid vertex!\n");
                    break;
                }
                DFS(&g, vertex-1);
                printf("\n");
                break;
                
            case 3:
                if(g.numVertices == 0) {
                    printf("Please create a graph first!\n");
                    break;
                }
                printf("Enter the vertex from which BFS is to be started (1 to %d)\n", g.numVertices);
                int startVertex;
                scanf("%d", &startVertex);
                if(startVertex < 1 || startVertex > g.numVertices) {
                    printf("Invalid vertex!\n");
                    break;
                }
                BFS(&g, startVertex-1);
                break;
                
            case 4:
                t = 0;
                break;
                
            default:
                printf("Invalid option! Please select 1-4\n");
                break;
        }
    }
    return 0;
}