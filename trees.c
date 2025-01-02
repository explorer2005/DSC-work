#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(int data){
    struct Node* n;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->data=data;
    n->right=NULL;
    n->left=NULL;
    return n;
}
int main(){
    struct Node*p1=createNode(2);
    struct Node*p2=createNode(11);
    struct Node*p3=createNode(10);
    p1->left=p2;
    p1->right=p3;
    return 0;
}