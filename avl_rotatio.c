#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
    int height;
};
int getHeight(struct node *root){
    if(root==NULL){
        return 0;
    }
    return root->height;
}
struct node * createNode(int data){
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    n->height=1;
    return n;
}
int getBalanceFactor(struct node *root){
    if(root==NULL){
        return 0;
    }
    return getHeight(root->right)-getHeight(root->left);
}
struct node *leftRotate(struct node *x){
    struct node *y=
}