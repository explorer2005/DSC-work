#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int *arr;
    int f;
    int r;
};
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q, int value){
    if(!isFull(q)){
        q->r++;
        q->arr[q->r]=value;
    }
    else{
        printf("Queue is full\n");
    }
}
int dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("queue is empty, not possible\n");
    }
    else{
        int a;
        q->f++;
        a=q->arr[q->f];
        return a;
    }
}
int main(){
    struct queue *q=(struct queue *)malloc(sizeof(struct queue));
    q->f=q->r=-1;
    q->size=7;
    q->arr=(int *)malloc(q->size*sizeof(int));
    int node;
    int i=6;
    int visited[7]={0,0,0,0,0,0,0};
    int a[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    printf("%d ",i);
    visited[i]=1;
    enqueue(q,i);
    while(!isEmpty(q)){
        int node=dequeue(q);
        for(int j=0;j<7;j++){
            if(a[node][j]==1 && visited[j]==0){
                printf("%d ",j);
                visited[j]=1;
                enqueue(q,j);
            }
        }
    }
}