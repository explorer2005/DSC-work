#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node * createNode(int data){
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
struct node * push(struct node * top, int data){
    struct node * newNode = createNode(data);
    newNode->next=top;
    return newNode;
}
struct node * pop(struct node *top){
    if(top==NULL){
        printf("Its empty\n");
        return top;
    }
    struct node *temp=top;
    printf("%d is popped successfully\n",temp->data);
    top=top->next;
    free(temp);
    return top;
}
void peek(struct node *top){
    if(top==NULL){
        printf("Its empty\n");
        return ;
    }
    printf("The peek element is %d\n",top->data);
    return;
}
void display(struct node *top){
    printf("The stack is as follows\n");
    struct node *temp=top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main(){
    int t=1;
    struct node *top=NULL;
    while(t){
        printf("Select the appropriate option\n1.push\n2.pop\n3.peek\n4.display\n");
        int m;
        scanf("%d",&m);
        switch(m){
            case 1:printf("Enter the data to be pushed\n");
                   int l;
                   scanf("%d",&l);
                   top=push(top,l);
                   break;
            case 2:printf("Popping\n");
                   top=pop(top);
                   break;
            case 3:peek(top);
                   break;
            case 4:display(top);
                   break;
            default:printf("Enter the appropriate option\n");
                    t=0;
        }
    }
    return 0;
}