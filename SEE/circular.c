#include<stdio.h>
#include<stdlib.h>
struct circular{
    int front;
    int rear;
    int size;
    int *arr;
};
struct circular* create(int size){
    struct circular* c=(struct circular *)malloc(sizeof(struct circular));
    c->front=c->rear=0;
    c->arr=(int *)malloc(c->size*sizeof(int));
    return c;
}
int isFull(struct circular *c){
    return c->front==(c->rear + 1)%c->size;
}
int isEmpty(struct circular *c){
    return c->front==c->rear;
}
struct circular *enqueue(struct circular *c, int data){
    if(isFull(c)){
        doubleSize(c);
    }
    c->rear=(c->rear + 1)%c->size;
    c->arr[c->rear]=data;
    printf("Enqueued the value %d\n",data);
    return c;
}
struct circular *dequeue(struct circular *c){
    if(isEmpty(c)){
        printf("The queue is empty\n");
        return c;
    }
    c->front=(c->front + 1)%c->size;
    printf("Dequeued the value %d\n",c->arr[c->front]);
    return c;
}
void display(struct circular *c){
    if(isEmpty(c)){
        printf("The queue is empty\n");
        return;
    }
    int i=(c->front +1 )%c->size;
    while(i!=(c->rear +1)%c->size){
        printf("%d ",c->arr[i]);
        i=(i+1)%c->size;
    }
}
void doubleSize(struct circular* c){
    int oldSize=c->size;
    c->size=oldSize*2;
    int *newArr=(int *)malloc(c->size*sizeof(int));
    int j=0;
    int i=(c->front +1)%oldSize;
    while(i!=(c->rear +1)%oldSize){
        newArr[j++]=c->arr[i];
        i=(i+1)%oldSize;
    }
    int front=-1;
    int rear=j-1;
    free(c->arr);
    c->arr=newArr;
    printf("Doubled the size %d\n",c->size);
    return ;
}
int main(){
    struct circular *c=create(3);
    int t=1;
    while(t){
        printf("Select an appropriate option\n1.Enqueue\n2.Dequeue\n3.Display\n");
        int k;
        scanf("%d",&k);
        switch(k){
            case 1:printf("Enter the data to be enqueued\n");
                   int data;
                   scanf("%d",&data);
                   c=enqueue(c,data);
                   break;
            case 2:c=dequeue(c);
                   break;
            case 3:display(c);
                   break;
            default:printf("Entered the wrong input\n");
                    t=0;
        }
    }
    return 0;
}