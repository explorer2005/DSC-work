#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int *arr;
};
void enqueue(struct queue *q, int val){
    if(!isFull(q)){
        q->r++;
        q->arr[q->r]=val;
    }
    else{
        printf("queue is  overflowed \n");
    }
}
int dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("queue is underflow \n");
    }
    else{
        q->f++;
        int r=q->arr[q->f];
        return r;
    }
}
int isEmpty(struct queue *q){
    if(q->f==q->r){
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
int main(){
    struct queue *q=(struct queue *)malloc(sizeof(struct queue));
    q->size=10;
    q->f=q->r=-1;
    q->arr=(int *)malloc((q->size)*sizeof(int));
    printf("%d\n",isEmpty(q));
    printf("%d\n",isFull(q));

    enqueue(q,56);
    enqueue(q,96);
    enqueue(q,70);
    printf("Dequeued valus is %d\n",dequeue(q));
    printf("Dequeued valus is %d\n",dequeue(q));
    return 0;
}