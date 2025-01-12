#include<stdio.h>
#include<stdlib.h>
struct circularQueue{
    int size;
    int rear;
    int front;
    int *arr;
};
struct circularQueue *create(int size){
    struct circularQueue *q=(struct circularQueue*)malloc(sizeof(struct circularQueue));
    q->size=size;
    q->front=q->rear=0;
    q->arr=(int *)malloc(q->size*sizeof(int));
    return q;
}
int isEmpty(struct circularQueue *q){
    return q->front==q->rear;
}
int isFull(struct circularQueue *q){
    return (q->rear+1)%q->size==q->front;
}
struct circularQueue* enqueue(struct circularQueue*q, int value){
    if(isFull(q)){
        doubleCapacity(q);
    }
    q->rear=(q->rear + 1)%q->size;
    q->arr[q->rear]=value;
    printf("Enqueued the value %d\n",value);
    return q;
}
struct circularQueue* dequeue(struct circularQueue*q){
    if(isEmpty(q)){
        printf("The circular queue is empty\n");
        return q;
    }
    else{
        q->front=(q->front + 1)%q->size;
        printf("Dequeued the value %d\n",q->arr[q->front]);
        return q;
    }
}
void doubleCapacity(struct circularQueue *q){
    int oldSize=q->size;
    q->size*=2;
    int *newArr=(int *)malloc(q->size*sizeof(int));
    int j=0;int i=(q->front + 1)%oldSize;

    while(i!=(q->rear + 1)%oldSize){
        newArr[j++]=q->arr[i];
        i=(i+1)%oldSize;
    }

    q->front=-1;
    q->rear=j-1;

    free(q->arr);
    q->arr=newArr;

    printf("Doubled the capacity %d\n",q->size);

}
void display(struct circularQueue *q){
    if(isEmpty(q)){
        printf("The queue is empty\n");
        return;
    }
    else{
        int i=(q->front+1)%q->size;
        while(i!=(q->rear+1)%q->size){
            printf("%d ",q->arr[i]);
            i=(i+1)%q->size;
        }
        printf("\n");
    }
}
int main(){
    printf("Enter the initial size of the circular queue\n");
    int size;
    scanf("%d",&size);
    struct circularQueue *q=create(size);

    int t=1;
    while(t){
        printf("Select one option\n1.Insert\n2.Dequeue\n3.Display\n4.Exit\n");
        int k;
        scanf("%d",&k);
        switch(k){
            case 1:printf("Enter the value to be entered\n");
                   int value;
                   scanf("%d",&value);
                   q=enqueue(q,value);
                   break;
            case 2:q=dequeue(q);
                   break;
            case 3:display(q);
                   break;
            case 4:exit(0);
        }
    }
}