#include<stdio.h>
#include<stdlib.h>
struct node{
    int deg;
    int coeff;
    struct node *next;
};
struct node * createNode(int d,int c){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->deg=d;
    newNode->coeff=c;
    newNode->next=NULL;
    return newNode;
}
struct node *insert(struct node *head,int d,int c){
    struct node *newNode=createNode(d,c);
    if(head==NULL || head->deg<d){
        newNode->next=head;
        head=newNode;
        return head;
    }
    else{
        struct node *temp=head;
        while(temp->next!=NULL&&temp->next->deg>=d){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        
        return head;
    }
}
void input(struct node **head){
    printf("Enter the number of terms with non zero coefficients\n");
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        printf("Enter the degree and coeff respectively\n");
        int d; int c;
        scanf("%d%d",&d,&c);
        *head = insert(*head,d,c);
    }
}
void display(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
    if(temp->next==NULL){
        printf("%dx^%d",temp->coeff,temp->deg);
    }
    else{
        printf("%dx^%d + ",temp->coeff,temp->deg);
    }
    temp=temp->next;
    }
}
struct node * addPoly(struct node *p1, struct node *p2){
    struct node *result=NULL;
    while(p1!=NULL&&p2!=NULL){
    if(p1->deg==p2->deg){
        int sum = p1->coeff+p2->coeff;
        if(sum!=0){
            result=insert(result,p1->deg,sum);
        }
        p1=p1->next;
        p2=p2->next;
    }
    else if(p1->deg>p2->deg){
        result=insert(result,p1->deg,p1->coeff);
        p1=p1->next;
    }
    else if(p2->deg>p1->deg){
        result=insert(result,p2->deg,p2->coeff);
        p2=p2->next;
    }
    }
    while(p1!=NULL){
        result=insert(result,p1->deg,p1->coeff);
        p1=p1->next;
    }
    while(p2!=NULL){
        result=insert(result,p2->deg,p2->coeff);
        p2=p2->next;
    }
    return result;
}
int main(){
    struct node *p1=NULL;
    struct node *p2=NULL;
    input(&p1);
    input(&p2);
    struct node *result=addPoly(p1,p2);
    display(result);
    return 0;
}