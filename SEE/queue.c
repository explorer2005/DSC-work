#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node * createNode(int data){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
struct node * enqueue(struct node *rear, int data){
    struct node *newNode=createNode(data);
    if(rear!=NULL){
    rear->next=newNode;
    printf("Enqueued the element %d\n",newNode->data);
    }
    return newNode;
}
struct node *dequeue(struct node *front){
    if(front==NULL){
        printf("Its empty\n");
        return front;
    }
    struct node *temp=front;
    front=front->next;
    printf("Dequeued the element %d\n,temp");
    free(temp);
    return front;
}
void peek(struct node *rear){
    if(rear==NULL){
        printf("The queue is empty\n");
        return;
    }
    printf("The peek element is %d\n,rear->data");
    return;
}
void display(struct node *front){
    if(front==NULL){
        printf("The queue is empty\n");
        return;
    }
    struct node *temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return;
}
int main(){
    struct node *rear=NULL;
        struct node *front=NULL;
    int t=1;
    while(t){
        
        printf("Select the appropriate option\n1.Enqueue\n2.Dequeue\n3.peek\n4.display\n");
        int k;
        scanf("%d",&k);
        switch(k){
            case 1:printf("Enter the data to be enqueued\n");
                   int data;
                   scanf("%d",&data);
                   if(front==NULL){
                    front=rear=enqueue(rear,data);
                   }
                   else{
                    rear=enqueue(rear,data);
                   }
                   break;
            case 2:front=dequeue(front);
                   break;
            case 3:peek(rear);
                   break;
            case 4:display(front);
                   break;
            default:printf("Enter the valid input\n");
                    t=0;
        }
    }
    return 0;
}