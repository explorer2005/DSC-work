#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *insertatbegin(struct node*p, int value){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=value;
    ptr->next=p;
    return ptr;
}
struct node *insertatlast(struct node *p, int value){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *temp=p;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ptr; 
    ptr->data=value;
    ptr->next=NULL;
    return p;
}
struct node *insertinbetween(struct node *p, int index, int value){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *temp=p;
    int i=0;
    while(i!=index-1){
        temp=temp->next;
        i++;
    }
    ptr->data=value;
    ptr->next=temp->next;
    temp->next=ptr;
    return p;
}
struct node *insertatnode(struct node *head, struct node *prevnode, int value){
    struct node *ptr=(struct mode*)malloc(sizeof(struct node));
    ptr->data=value;
    ptr->next=prevnode->next;
    prevnode->next=ptr;
    return head;
}
void linkedlisttraversal(struct node *p){
    while(p!=NULL){
        printf("The element is: %d\n",p->data);
        p=p->next;
    }
}
int main(){
    struct node *head=(struct node*)malloc(sizeof(struct node));
    struct node *second=(struct node*)malloc(sizeof(struct node));
    struct node *third=(struct node*)malloc(sizeof(struct node));
    struct node *fourth=(struct node*)malloc(sizeof(struct node));

    head->data=7;
    head->next=second;
    second->data=23;
    second->next=third;
    third->data=35;
    third->next=fourth;
    fourth->data=80;
    fourth->next=NULL;
    linkedlisttraversal(head);
    head=insertatbegin(head,15);
    linkedlisttraversal(head);
    head=insertatlast(head,16);
    linkedlisttraversal(head);
    head=insertinbetween(head,3,59);
    linkedlisttraversal(head);
    head=insertatnode(head,second,99);
    linkedlisttraversal(head);
}