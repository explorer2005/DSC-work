#include<stdio.h>
#include<stdlib.h>
struct  node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *createNode(int data){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
void display(struct node *head){
    if(!head){
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
struct node *insert(struct node *head,int data,int pos){
    struct node *newNode=createNode(data);
    if(!head){
        return newNode;
    }
    if(pos==0){
        newNode->next=head;
        head->prev=newNode;
        return newNode;
    }
    else{
        struct node *temp=head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
            if(temp==NULL){
                printf("Out of  bound addition of the node\n");
                return head;
            }
        }
        newNode->next=temp->next;
        
        if(temp->next!=NULL){
            temp->next->prev=newNode;
        }
        newNode->prev=temp;
        temp->next=newNode;
        return head;
    }
}
struct node *delete(struct node *head, int pos){
    if(!head){
        printf("The list is empty\n");
        return head;
    } 
    if(pos==0){
        head=head->next;
        head->prev=NULL;
        return head;
    }  
    else{
        struct node *temp=head;
        for(int i=0;i<pos;i++){
            temp=temp->next;
            if(temp==NULL){
                printf("Out of bound\n");
                return head;
            }
        }
        if(temp->prev!=NULL){
            temp->prev->next=temp->next;
        }
        if(temp->next!=NULL){
            temp->next->prev=temp->prev;
        }
        return head;
    }
}
int main(){
    struct node *head=NULL;
    int t=1;
    while(t){
        printf("Select an appropriate option\n1.Insert\n2.Delete\n3.Display\n");
        int k;
        scanf("%d",&k);
        switch(k){
            case 1:printf("Enter the data and postion at which its to be entered\n");
                   int data;
                   int pos;
                   scanf("%d%d",&data,&pos);
                   head=insert(head,data,pos);
                   break;
            case 2:printf("Enter the positionto be deleted\n");
                   int pos2;
                   scanf("%d",&pos2);
                   head=delete(head,pos2);
                   break;
            case 3:display(head);
                   break;
            default:printf("Entered the wrong input\n");
                    t=0;
        }
    }
}