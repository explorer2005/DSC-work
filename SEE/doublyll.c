#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node * createNode(int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->next=NULL;
    newNode->prev=NULL;
    newNode->data=data;
    return newNode;
}
void display(struct node *head){
    if(head==NULL){
        printf("The list is empty\n");
        return;
    }
    else{
        struct node *temp=head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        return;
    }
}
struct node * insert(struct node *head, int data, int pos){
    if(pos==1){
        struct node*newNode=createNode(data);
        newNode->next=head;
        newNode->prev=NULL;
        if(head!=NULL){
            head->prev=newNode;
        }
        return newNode;
    }
    else{
        struct node *newNode=createNode(data);
        struct node *temp=head;
        for(int i=0;i<pos-1;i++){
            if(temp==NULL){
                printf("Out of bound position\n");
                return head;
            }
            temp=temp->next;
        }
        newNode->next=temp->next;
        
        if(temp->next!=NULL){
            temp->next->prev=newNode;
        }
        temp->next=newNode;
        newNode->prev=temp;
        
        return head;
    }
}
struct node *delete(struct node *head,int pos){
    struct node *temp=head;
    if(pos==1){
        head=head->next;
        if(head!=NULL){
            head->prev=NULL;
        }
    }
    else{
        for(int i=0;i<pos;i++){
        if(temp==NULL){
        printf("Out of bound position\n");
        return head;
    }
        temp=temp->next;
    }
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    if(temp->prev!=NULL){
        temp->prev->next=temp->next;
    }
    return head;
    }    
}
int main(){
    struct node *head=NULL;
    int t=1;
    while(t){
        printf("Enter the appropriate option\n1.Insert\n2.Delete\n3.Display\n");
        int k;
        scanf("%d",&k);
        switch(k){
            case 1:printf("Enter the element to be entered\n");
                   int data;
                   scanf("%d",&data);
                   printf("Enter the position at which the element is to be inserted\n");
                   int pos;
                   scanf("%d",&pos);
                   head=insert(head,data,pos);
                   break;
            case 2:printf("Enter the position to be deleted\n");
                   int pos2;
                   scanf("%d",&pos2);
                   head=delete(head,pos2);
                   break;
            case 3:display(head);
                   break;
            default:printf("Enter an appropriate option\n");
                     t=0;
        }
    }
    return 0;
}