#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node*createNode(int data){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
struct node *enqueue(struct node *q, int data){
    struct node *newNode=createNode(data);
    if(!q){
        return newNode;
    }
    else{
        struct node *temp=q;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        return q;
    }
}
struct node *dequeue(struct node *q){
    if(!q){
        printf("The queue is empty\n");
        return q;
    }
    else{
        q=q->next;
        return q;
    }
}
void display(struct node *q){
    if(!q){
        printf("The queue is empty\n");
        return;
    }
    else{
        struct node *temp=q;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        return;
    }
}
int main(){
    struct node *q=NULL;
    int t=1;
    while(t){
        printf("Enter an appropriate option\n1.Enqueue\n2.Dequeue\n3.Display\n");
        int k;
        scanf("%d",&k);
        switch(k){
            case 1:printf("Enter the element to be enqueued\n");
                   int data;
                   scanf("%d",&data);
                   q=enqueue(q,data);
                   break;
            case 2:q=dequeue(q);
                   break;
            case 3:display(q);
                   break;
            default:printf("Enter an appropriate option\n");
                    t=0;
        }
    }
    return 0;
}