#include<stdio.h>
#include<stdlib.h>
struct Circularqueue{
    int size;
    int f;
    int r;
    int *arr;
};
void enqueue(struct Circularqueue *q, int val){
    if(!isFull(q)){
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
        printf("Enqueued %d\n",val);
    }
    else{
        printf("queue is  overflowed \n");
    }
}
int dequeue(struct Circularqueue *q){
    if(isEmpty(q)){
        printf("queue is underflow \n");
    }
    else{
        q->f=(q->f+1)%q->size;
        int r=q->arr[q->f];
        return r;
    }
}
int isEmpty(struct Circularqueue *q){
    if(q->f==q->r){
        return 1;
    }
    return 0;
}
int isFull(struct Circularqueue *q){
    if((q->r+1)%q->size==q->f){
        return 1;
    }
    return 0;
}
int main(){
    struct Circularqueue *q=(struct Circularqueue *)malloc(sizeof(struct Circularqueue));
    q->size=4;
    q->f=q->r=0;
    q->arr=(int *)malloc((q->size)*sizeof(int));
    printf("%d\n",isEmpty(q));
    printf("%d\n",isFull(q));

    enqueue(q,56);
    enqueue(q,96);
    enqueue(q,70);
    printf("Dequeued valus is %d\n",dequeue(q));
    printf("Dequeued valus is %d\n",dequeue(q));
    printf("Dequeued valus is %d\n",dequeue(q));
    enqueue(q,56);
    enqueue(q,96);
    enqueue(q,70);
    return 0;
}