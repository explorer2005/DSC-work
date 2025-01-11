#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node*createNode(int data){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
struct node*enqueue(struct node *rear,int data){
    struct node *newNode = createNode(data);
    if(rear!=NULL){
        rear->next=newNode;
    }
    return newNode;
}
struct node*dequeue(struct node *front){
    if(front==NULL){
        printf("The queue is empty\n");
        return NULL;
    }
    else{
        struct node *temp=front;
        printf("The dequeued element is: %d\n",front->data);
        front=front->next;
        return front;
    }
}
void peek(struct node *front){
    if(front==NULL){
        printf("The queue is empty\n");
    }
    else{
        printf("The peek element is: %d\n",front->data);
    }
}
void display(struct node *front){
    if(front==NULL){
        printf("The queue is empty.\n");
    }
    else{
        while(front!=NULL){
            printf("%d ",front->data);
            front=front->next;
        }
    }
}
int main(){
    struct node *front=NULL;
    struct node *rear=NULL;
    int t=1;
    while(t){
        printf("Select the correct option\n1.enqueue\n2.dequeue\n3.peek\n4.display\n");
        int k;
        scanf("%d",&k);
        switch(k){
            case 1:printf("Enter the element to be enqueued\n");
                   int val;
                   scanf("%d",&val);
                   if(front==NULL){
                    front=rear=enqueue(rear,val);
                   }
                   else{
                    rear=enqueue(rear,val);
                   }
                   break;
            case 2:front=dequeue(front);
                   break;
            case 3:peek(front);
                   break;
            case 4:display(front);
                   break;
            case 5:printf("Exiting....\n");
                   t=0;
                   exit(0);
        }
    }

}