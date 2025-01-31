#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct node{
    int vertex;
    struct node *next;
};
struct graph{
    struct node *adjList[MAX];
    int visited[MAX];
    int numVertices;
};
struct node *createNode(int vertex){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->vertex=vertex;
    newNode->next=NULL;
    return newNode;
}
void initializeGraph(struct graph *g, int numVertices){
    g->numVertices=numVertices;
    for(int i=0;i<numVertices;i++){
        g->visited[i]=0;
        g->adjList[i]=NULL;
    }
}
void addEdge(struct graph *g,int u,int v){
    struct node * newNode=createNode(v);
    newNode->next=g->adjList[u];
    g->adjList[u]=newNode;

    newNode=createNode(u);
    newNode->next=g->adjList[v];
    g->adjList[v]=newNode;
}
void DFS(struct graph *g, int vertex){
    printf("%d ",vertex+1);
    g->visited[vertex]=1;
    struct node * temp=g->adjList[vertex];
    while(temp!=NULL){
        int adjVertex=temp->vertex;
        if(!g->visited[adjVertex]){
            DFS(g,adjVertex);
        }
        temp=temp->next;
    }
}
void BFS(struct graph *g, int startVertex){
    int queue[MAX];
    int front=0;
    int rear=0;
    for(int i=0;i<g->numVertices;i++){
        g->visited[i]=0;
    }
    queue[rear]=startVertex;
    g->visited[startVertex]=1;
    while(front<=rear){
        int currentVertex=queue[front];
        front++;
        printf("%d ",currentVertex+1);
        struct node *temp=g->adjList[currentVertex];
        while(temp!=NULL){
            int adjVertex=temp->vertex;
            if(!g->visited[adjVertex]){
                rear++;
                queue[rear]=adjVertex;
                g->visited[adjVertex]=1;
            }
            temp=temp->next;
        }

    }
}
int main(){
    struct graph g;
    int t=1;
    while(t){
        printf("Select 1 option \n1.Create\n2.DFS\n3.BFS\n");
        int k;
        scanf("%d",&k);
        switch(k){
            case 1:printf("Enter the number of vertices\n");
                   int numVertices;
                   scanf("%d",&numVertices);
                   initializeGraph(&g,numVertices);
                   printf("Enter the number of edges\n");
                   int n;
                   scanf("%d",&n);
                   for(int i=0;i<n;i++){
                    printf("Enter u v: \n");
                    int u; 
                    int v;
                    scanf("%d%d",&u,&v);
                    addEdge(&g,u-1,v-1);
                   }
                   printf("Graph created successfully\n");
                   break;
            case 2:printf("Enter the vertex\n");
                   int vertex;
                   scanf("%d",&vertex);
                   DFS(&g,vertex-1);
                   break;
            case 3:printf("Enter the starting vertex\n");
                   int startVertex;
                   scanf("%d",&startVertex);
                   BFS(&g,startVertex-1);
                   break;
            default:printf("Wrong\n");
                    t=0;
        }
    }
}