#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node * createNode(int data){
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void preOrder(struct node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct node *root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}
void inOrder(struct node *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
int bst(struct node *root){
    static struct node *pre=NULL;
    if(root!=NULL){
        if(!bst(root->left)){
            return 0;
        }
        if(pre!=NULL && pre->data>=root->data){
            return 0;
        }
        pre=root;
        return bst(root->right);
    }
    else{
        return 1;
    }
}
int main(){
    struct node*p1=createNode(5);
    struct node*p2=createNode(3);
    struct node*p3=createNode(8);
    struct node*p4=createNode(1);
    struct node*p5=createNode(4);
    struct node*p6=createNode(7);
    struct node*p7=createNode(9);
    p1->left=p2;
    p1->right=p3;
    p2->left=p4;
    p2->right=p5;
    p3->left=p6;
    p3->right=p7;
    preOrder(p1);
    printf("\n");
    inOrder(p1);
    printf("\n");
    postOrder(p1);
    printf("\n");
    if(bst(p1)){
        printf("yes its a binary search tree");
    }
}