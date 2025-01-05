#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node * createNode(int data){
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    n->data=data;
    n->prev=NULL;
    n->next=NULL;
    return n;
}
struct node *deleteStart(struct node *head){
    struct node *temp=head;
    if(head!=NULL){
        head=head->next;
        head->prev=NULL;
    }
    free(temp);
    return head;
    
}
struct node *deleteEnd(struct node *head){
    struct node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    if(temp->prev!=NULL){
    temp->prev->next=NULL;
    }else{
        head=NULL;
    }
    free(temp);
    return head;

}
struct node *deleteAtIndex(struct node *head, int index){
    struct node* temp=head;
    struct node* temp2;
    int i=0;
    while(i!=index-1){
        temp=temp->next;
        if(temp==NULL){
            return head;
        }
        i++;
    }
    if(temp->prev!=NULL){
    temp->prev->next=temp->next;
    }
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    free(temp);
    return head;
}
struct node * insertStart(struct node *head, int data){
    struct node *temp = createNode(data);
    temp->next=head;
    head->prev=temp;
    temp->prev=NULL;
    return temp;
}
struct node * insertEnd(struct node *head, int data){
    struct node *temp = createNode(data);
    struct node *temp2=head;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp;
    temp->prev=temp2;
    temp->next=NULL;
    return head;
}
struct node * insertAtIndex(struct node *head, int data, int index){
    struct node *temp = createNode(data);
    struct node *temp2=head;
    for(int i=0;i<index;i++){
        temp2=temp2->next;
    }
    temp->next=temp2->next;
    temp2->next=temp;
    temp->prev=temp2;
    // temp->next = temp2->next;
    // if (temp2->next != NULL) {
    //     temp2->next->prev = temp; // Update the `prev` pointer of the next node
    // }
    // temp2->next = temp;
    // temp->prev = temp2;

    return head;
}
void frontdisplay(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void backdisplay(struct node *tail){
    struct node *temp=tail;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->prev;
    }
}
int main(){
    struct node *n1 = createNode(5);
    struct node *n2 = createNode(6);
    struct node *n3 = createNode(7);
    struct node *n4 = createNode(8);
    struct node *n5 = createNode(9);
    struct node *n6 = createNode(10);
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;
    n6->prev=n5;
    n5->prev=n4;
    n4->prev=n3;
    n3->prev=n2;
    n2->prev=n1;

    frontdisplay(n1);
    printf("\n");
    backdisplay(n6);
    n1=insertStart(n1,100);
    printf("\n");
    frontdisplay(n1);
    n1=insertEnd(n1,50);
    printf("\n");
    frontdisplay(n1);
    n1=insertAtIndex(n1,700,2);
    printf("\n");
    frontdisplay(n1);
    n1=deleteStart(n1);
    printf("\n");
    frontdisplay(n1);
    n1=deleteEnd(n1);
    printf("\n");
    frontdisplay(n1);
    n1=deleteAtIndex(n1,3);
    printf("\n");
    frontdisplay(n1);
}