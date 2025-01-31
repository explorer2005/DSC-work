#include<stdio.h>
#include<stdlib.h>
struct node{
    int degree;
    int coeff;
    struct node *next;
};
struct node * createNode(int degree, int coeff){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->degree=degree;
    newNode->coeff=coeff;
    newNode->next=NULL;
    return newNode;
}
void display(struct node *p){
    struct node *temp=p;
    while(temp!=NULL){
        if(temp->next==NULL){
            printf("%dx^%d",temp->coeff,temp->degree);
        }
        else{
            printf("%dx^%d+",temp->coeff,temp->degree);
        }
        
        temp=temp->next;
    }
}
struct node*insert(struct node *p,int degree,int coeff){
    struct node *newNode=createNode(degree,coeff);
    if(p==NULL||p->degree<degree){
        newNode->next=p;
        p=newNode;
        return p;
    }
    else{
        struct node *temp=p;
        while(temp->next!=NULL&&temp->next->degree>=degree){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        return p;
    }
}
void inputPoly(struct node **p){
    printf("Enter the number of non zero terms\n");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the degree and coeff respectively\n");
        int d;
        int c;
        scanf("%d%d",&d,&c);
        *p=insert(*p,d,c);
    }
}
struct node* addPoly(struct node *p1,struct node *p2){
    struct node *result=NULL;
    while(p1!=NULL&&p2!=NULL){
        if(p1->degree==p2->degree){
            int sum=p1->coeff+p2->coeff;
            if(sum!=0){
                result=insert(result,p1->degree,sum);
            }
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->degree>p2->degree){
            result=insert(result,p1->degree,p1->coeff);
            p1=p1->next;
        }
        else{
            result=insert(result,p2->degree,p2->coeff);
            p2=p2->next;
        }
    }
    while(p1!=NULL){
        result=insert(result,p1->degree,p1->coeff);
        p1=p1->next;
    }
    while(p2!=NULL){
        result=insert(result,p2->degree,p2->coeff);
        p2=p2->next;
    }
    return result;
}
int main(){
    struct node*p1=NULL;
    struct node *p2=NULL;
    inputPoly(&p1);
    printf("Now enter second\n");
    inputPoly(&p2);
    printf("The result is\n");
    struct node *ans=addPoly(p1,p2);
    printf("ans received\n");
    display(ans);
    return 0;
}