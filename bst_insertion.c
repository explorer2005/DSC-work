#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left;
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
int isBst(struct node *root){
    static struct node *pre=NULL;
    if(root!=NULL){
        if(!isBst(root->left)){
            return 0;
        }
        if(pre!=NULL && pre->data>=root->data){
            return 0;
        }
        pre=root;
        return isBst(root->right);
    }
    else{
        return 1;
    }
}
void insert(struct node *root, int key){
    struct node *pre=NULL;
    while(root!=NULL){
        pre=root;
        if(root->data==key){
            printf("Same number cannot be inserted\n");
            return;
        }
        else if(root->data>key){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    struct node *new=createNode(key);
    if(pre->data>key){
        pre->left=new;
    }
    else{
        pre->right=new;
    }
}
int main(){
     struct node *p1=createNode(8);
    struct node *p2=createNode(5);
    struct node *p3=createNode(9);
    struct node *p4=createNode(1);
    struct node *p5=createNode(6);
    p1->left=p2;
    p1->right=p3;
    p2->left=p4;
    p2->right=p5;
    if(isBst(p1)){
       printf("Enter the number to be inserted\n");
       int key;
       scanf("%d",&key);
       insert(p1,key);
       printf("%d",p1->right->right->data);
    }
    else{
        printf("Enter a valid binary search tree");
    }
    return 0;
}