#include<stdio.h>
#include<stdlib.h>
struct circular{
    int front;
    int rear;
    int size;
    int *arr;
};
int isEmpty(struct circular *q){
    if(q->front==q->rear){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct circular *q){
    if((q->rear+1)%q->size==q->front){
        return 1;
    }
    else{
        return 0;
    }
}
void display(struct circular *q){
    if(isEmpty(q)){
        printf("The queue is empty\n");
        return;
    }
    else{
        int i=(q->front +1)%q->size;
        while(i!=(q->rear+1)%q->size){
            printf("%d ",q->arr[i]);
            i=(i+1)%q->size;
        }
        return;
    }
}
struct circular * doubleSize(struct circular *q){
    int oldSize=q->size;
    q->size=q->size*2;
    int *newArr= (int *)malloc(q->size*sizeof(int));
    int j=0;
    int i=(q->front+1)%oldSize;
    while(i!=(q->rear+1)%oldSize){
        newArr[j++]=q->arr[i];
        i=(i+1)%oldSize;
    }
    q->front=-1;
    q->rear=j-1;
    free(q->arr);
    q->arr=newArr;
    printf("Doubled the size of the array %d\n",q->size);
    return q;
}
void enqueue(struct circular *q,int value){
    if(isFull(q)){
        q=doubleSize(q);
    }
    q->rear=(q->rear+1)%q->size;
    q->arr[q->rear]=value;
    printf("Enqueued the value %d\n",value);
    return;
}
void dequeue(struct circular *q){
    if(isEmpty(q)){
        printf("The queue is empty\n");
        return;
    }
    else{
        q->front=(q->front+1)%q->size;
        printf("Dequeued the element %d\n",q->arr[q->front]);
        return;
    }
}
int main(){
    struct circular *q=(struct circular*)malloc(sizeof(struct circular));
    q->front=q->rear=0;
    printf("Enter the size of the queue\n");
    int n;
    scanf("%d",&n);
    q->size=n;
    q->arr=(int *)malloc(q->size*sizeof(int));
    int t=1;
    while(t){
        printf("Select an appropriate option\n1.Enqueue\n2.Dequeue\n3.Display\n");
        int k;
        scanf("%d",&k);
        switch(k){
            case 1:printf("Enter the data to be enqueued\n");
                   int data;
                   scanf("%d",&data);
                   enqueue(q,data);
                   break;
            case 2:dequeue(q);
                   break;
            case 3:display(q);
                   break;
            default:printf("Entered the wrong input\n");
                    t=0;
        }
    }
}
