#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void linkedlisttraversal(struct node *q){
    while(q!=NULL){
        printf("The element is: %d\n",q->data);
        q=q->next;
    }
}

int main(){
    struct node *head=(struct node *)malloc(sizeof(struct node));
    struct node *second=(struct node *)malloc(sizeof(struct node));
    struct node *third=(struct node *)malloc(sizeof(struct node));
    struct node *fourth=(struct node *)malloc(sizeof(struct node));

    head->data=7;
    head->next=second;
    second->data=19;
    second->next=third;
    third->data=22;
    third->next=fourth;
    fourth->data=30;
    fourth->next=NULL;
    linkedlisttraversal(head);
    return 0;
}