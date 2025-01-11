#include<stdio.h>
#include<stdlib.h>
struct node{
    int degree;
    int coeff;
    struct node* next;
};
struct node * createNode(int degree, int coeff){
    struct node*newNode = (struct node *)malloc(sizeof(struct node));
    newNode->coeff=coeff;
    newNode->degree=degree;
    newNode->next=NULL;
    return newNode;
}
struct node * insertNode(struct node *head,int degree,int coeff){
    struct node *newNode = createNode(degree,coeff);
    if(head==NULL || head->degree<degree){
        newNode->next=head;
        head=newNode;
    }
    else{
        struct node *temp=head; 
        while(temp->next!=NULL && temp->next->degree>=degree){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
    return head;
}
void inputPoly(struct node **head){
    printf("Enter the non zero terms in the polynomial\n");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the degree and coeff respectively\n");
        int d,c;
        scanf("%d%d",&d,&c);
        *head=insertNode(*head,d,c);
    }
}
struct node * addPoly(struct node *p1,struct node *p2){
    struct node *result=NULL;
    while(p1!=NULL && p2!=NULL){
        if(p1->degree==p2->degree){
            int sum = p1->coeff+p2->coeff;
            if(sum!=0){
                result = insertNode(result,p1->degree,sum);
            }
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->degree>p2->degree){
            result=insertNode(result,p1->degree,p1->coeff);
            p1=p1->next;
        }
        else{
            result=insertNode(result,p2->degree,p2->coeff);
            p2=p2->next;
        }
    }
    while(p1!=NULL){
        result=insertNode(result,p1->degree,p1->coeff);
        p1=p1->next;
    }
    while(p2!=NULL){
        result=insertNode(result,p2->degree,p2->coeff);
        p2=p2->next;
    }
    return result;

}
void display(struct node *head){
    struct node *temp = head;
    while(temp!=NULL){
        if(temp->next==NULL){
            printf("%dx^%d",temp->coeff,temp->degree);
        }
        else{
            printf("%dx^%d + ",temp->coeff,temp->degree);
        }
        temp=temp->next;
    }
}
int main(){
    printf("Enter polynomial 1\n");
    struct node *p1=NULL;
    inputPoly(&p1);
    printf("Enter polynomial 2\n");
    struct node *p2=NULL;
    inputPoly(&p2);

    struct node *ans= addPoly(p1,p2);
    printf("Displaying result\n");
    display(ans);
}