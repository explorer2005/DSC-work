#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node * insertStPosition(struct node *head, int data, int pos){
    struct node* newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    if(pos==1){
        newNode->next=head;
        if(head!=NULL){
            head->prev=newNode;
        }
        return newNode;
    }
    

    struct node *temp=head;
    for(int i=1;i<pos-1;i++){
        if(temp==NULL){
            printf("Out of bound\n");
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
struct node * deleteAtPosition(struct node *head,int position){
    if(head==NULL){
        return head;
    }
    if(position==1){
        head=head->next;
    
    if(head!=NULL){
        head->prev=NULL;
    }
    printf("Deleted\n");
    return head;

    }
    struct node *temp=head;
    for(int i=1;i<position;i++){
        if(temp==NULL){
            printf("Out of bound\n");
            return head;
        }
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Out of bound\n");
        return head;
    }
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    if(temp->prev!=NULL){
        temp->prev->next=temp->next;
    }
    printf("Deleted\n");
    return head;
}
void display(struct node *head){
    if(head==NULL){
        printf("The list is empty\n");
        return;
    }
    struct node*temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main(){
    struct node *head=NULL;
    int t=1;
    while(t){
        printf("Select\n1.insert\n2.delete\n3.display\n");
        int k;
        scanf("%d",&k);
        switch(k){
            case 1:printf("Enter the values and position to be inserted resp.\n");
                   int pos; int val;
                   scanf("%d%d",&val,&pos);
                   head=insertStPosition(head,val,pos);
                   printf("The element %d is inserted: ",val);
                   break;
            case 2:printf("Enter the position to be deleted\n");
                   int posi;
                   scanf("%d",&posi);
                   head=deleteAtPosition(head,pos);
                   break;
            case 3:display(head);
                   break;
        }
    }
}