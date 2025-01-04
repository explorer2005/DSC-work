#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
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
struct node * createNode(int data){
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    n->data=data;
    n->right=NULL;
    n->left=NULL;
    return n;
}
struct node* search(struct node *root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    else if(root->data>key){
        return search(root->left,key);
    }
    else if(root->data<key){
        return search(root->right,key);
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
    if(bst(p1)){
        printf("Enter the key to be searched ");
        int k;
        scanf("%d",&k);

        struct node*ans=search(p1,k);
        if(ans!=NULL){
            printf("The answer is: %d"+k);
        }
        else{
            printf("The key is not present ");
        }
    }
    else{
        printf("Enter a valid tree for binary search");
    }
}