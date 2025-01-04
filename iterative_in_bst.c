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
    n->right=NULL;
    n->left=NULL;
    return n;
}
int isBST(struct node *root){
    static struct node *pre=NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(pre!=NULL && pre->data>=root->data){
            return 0;
        }
        pre=root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}
struct node * iteSearch(struct node *root,int key){
    while(root!=NULL){
        if(root->data==key){
            return root;
        }
        else if(root->data>key){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return NULL;
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
    if(isBST(p1)){
        printf("Enter the key to be searched\n");
        int key;
        scanf("%d",&key);
        struct node *ans=iteSearch(p1,key);
        if(ans!=NULL){
            printf("The answer is found ");
        }
        else{
            printf("The answer is not found");
        }
    }
    else{
        printf("Enter a valid binary search tree");
    }
    return 0;
}