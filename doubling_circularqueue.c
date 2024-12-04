#include<stdio.h>
#include<stdlib.h>
struct Circularqueue{
    int size;
    int f;
    int r;
    int *arr;
};
void enqueue(struct Circularqueue *q, int val){
    if(isFull(q)){
        resize(q);
    }
    q->r=(q->r+1)%q->size;
    q->arr[q->r]=val;
    printf("The enqueued value is: %d\n",q->arr[q->r]);
}
int dequeue(struct Circularqueue *q){
    if(!isEmpty(q)){
        q->f=(q->f+1)%q->size;
        int val=q->arr[q->f];
        return val;
    }
    else{
        printf("The queue is underflown\n");
    }
}
void resize(struct Circularqueue *q){
    int newSize=2*q->size;
    int *newArr=(int *)malloc(newSize*sizeof(int));
    int i=(q->f+1)%q->size;
    int j=0;
    while(i!=(q->r+1)%q->size){
        newArr[j++]=q->arr[i];
        i=(i+1)%q->size;
    }
    q->f=newSize-1;
    q->r=j-1;
    q->size=newSize;
    free(q->arr);
    q->arr=newArr;
    printf("Resized queue ot %d\n",newSize);
}
int isFull(struct Circularqueue *q){
    if((q->r+1)%q->size==q->f){
        return 1;
    }
    return 0;
}
int isEmpty(struct Circularqueue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
int main(){
    struct Circularqueue *q=(struct Circularqueue*)malloc(sizeof(struct Circularqueue));
    q->size=3;
    q->f=q->r=0;
    q->arr=(int *)malloc(q->size*sizeof(int));
    printf("Condition: %d\n",isEmpty(q));
    printf("Condition: %d\n",isFull(q));
    enqueue(q,96);
    enqueue(q,58);
    enqueue(q,36);
    enqueue(q,20);
    enqueue(q,56);
}