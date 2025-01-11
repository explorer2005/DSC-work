#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *createNode(int data){
    struct node *newNode=(struct node * )malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
struct node * push(struct node *top,int data){
    struct node * newNode = createNode(data);
    newNode->next=top;
    printf("%d is pushed\n",data);
    return newNode;
}
struct node * pop(struct node *top){
    if(top==NULL){
        printf("The stackis underflown!\n");
    }
    else{
        struct node * temp=top;
        printf("The following data is popped: %d\n",top->data);
        top=top->next;
        free(temp);
    }
    return top;
}
void display(struct node *top){
    if(top==NULL){
        printf("The stack is empty\n");
    }
    else{
        while(top!=NULL){
            printf("%d ",top->data);
            top=top->next;
        }
    }
}
void peek(struct node *top){
    if(top==NULL){
        printf("No peek element, the stack is empty\n");
    }
    else{
        // while(top!=NULL){
        //     top=top->next;
        // }
        printf("The peek element is: %d\n",top->data);
    }
}
int main(){
    struct node *top=NULL;

    int t=1;
    while(t){
    printf("Select the appropriate option\n 1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
    int k;
    scanf("%d",&k);
    switch(k){
        case 1:printf("Enter the elemt\n");
               int value;
               scanf("%d",&value);
               top=push(top,value);
               break;
        case 2:top=pop(top);
               break;
        case 3:peek(top);
               break;
        case 4:display(top);
               break;
        case 5:printf("Exiting...");
               t=0;
              exit(0);
              break;
        default: printf("Entered the wrong digbit\n");

    }

    }
    return 0;
}