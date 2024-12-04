#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
void linkedlisttraversal(struct node *s){
    while(s!=NULL){
        printf("The element is: %d\n",(*s).data);
        s=(*s).next;
    }
}
int main(){
    struct node *head=(struct node*)malloc(sizeof(struct node));
    struct node *second=(struct node*)malloc(sizeof(struct node));
    struct node *third=(struct node*)malloc(sizeof(struct node));
    struct node *fourth=(struct node*)malloc(sizeof(struct node));

    head->data=7;
    head->next=second;
    second->data=8;
    second->next=third;
    third->data=9;
    third->next=fourth;
    fourth->data=10;
    fourth->next=NULL;

    linkedlisttraversal(head);
}