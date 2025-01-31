#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node * createNode(int data){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
struct node *push(struct node *top,int data){
    struct node *newNode=createNode(data);
    newNode->next=top;
    printf("successfully pushed the element %d\n",data);
    return newNode;
}
struct node *pop(struct node *top){
    if(!top){
        printf("The stack is empty\n");
        return top;
    }
    else{
        int temp=top->data;
        top=top->next;
        printf("Popped the element %d\n",temp);
        free(temp);
        return top;
    }
}
void peek(struct node *top){
    if(!top){
        printf("The stack is empty\n");
        return;
    }
    else{
        printf("The peek element is: %d\n",top->data);
        return;
    }
}
void display(struct node *top){
    if(!top){
        printf("The stack is empty\n");
        return;
    }
    else{
        struct node *temp=top;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        return;
    }
}
int main(){
    struct node *top=NULL;
    int t=1;
    while(t){
    printf("Select an approriate option\n1.Push\n2.Pop\n3.Peek\4.Display\n");
    int k;
    scanf("%d",&k);
    switch(k){
        case 1:printf("Enter the element to be pushed\n");
               int data;
               scanf("%d",&data);
               top=push(top,data);
               break;
        case 2:top=pop(top);
               break;
        case 3:peek(top);
               break;
        case 4:display(top);
               break;
        default:printf("Select an appropriate option\n");
                t=0;
    }
    }
}