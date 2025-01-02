#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *right;
    struct node *left;
};
struct node* createNode(int data){
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void postorder(struct node*root){
    if(root!=NULL){
            postorder(root->left);
    postorder(root->right);
        printf("%d ",root->data);
    }
}
int main(){
    struct node *p1=createNode(4);
    struct node *p2=createNode(1);
    struct node *p3=createNode(6);
    struct node *p4=createNode(5);
    struct node *p5=createNode(2);
    p1->left=p2;
    p1->right=p3;
    p2->left=p4;
    p2->right=p5;
    postorder(p1);

}