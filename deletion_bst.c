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
int isBst(struct node *root){
    struct node *pre=NULL;
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
void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void insert(struct node *root, int value){
    struct node *pre=NULL;
    while(root!=NULL){
        pre=root;
        if(root->data>value){
            root=root->left;
        }
        else if(root->data<value){
            root=root->right;
        }
        else{
            printf("Same valuecannot be inserted \n");
            return;
        }
    }
    struct node *new=createNode(value);
    if(pre->data>new->data){
        pre->left=new;
    }
    else{
        pre->right=new;
    }
}
struct node* inOrderPre(struct node *root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
struct node * delete(struct node *root,int value){
    struct node *iPre;
    if(root==NULL){
        return NULL;
    }
    if(value>root->data){
        root->right=delete(root->right,value);
    }
    else if(value<root->data){
        root->left=delete(root->left,value);
    }
    else{
        if(root->right==NULL){
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        if(root->left==NULL){
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        iPre=inOrderPre(root);
        root->data=iPre->data;
        root->left=delete(root->left,iPre->data);
    }
    return root;
}
int main(){
    // struct node *p1=createNode(5);
    // struct node *p2=createNode(3);
    // struct node *p3=createNode(6);
    // struct node *p4=createNode(1);
    // struct node *p5=createNode(4);
    // p1->left=p2;
    // p1->right=p3;
    // p2->left=p4;
    // p2->right=p5;
    // inorder(p1);
    // delete(p1,1);
    // printf("\n");
    // inorder(p1);
    // insert(p1,1);
    // printf("\n");
    // inorder(p1);
    //     delete(p1,3);
    // printf("\n");
    // inorder(p1);
        struct node *p1=createNode(5);
    struct node *p2=createNode(6);
    struct node *p3=createNode(7);
    struct node *p4=createNode(8);
    struct node *p5=createNode(9);
    p1->right=p2;
    p2->right=p3;
    p3->right=p4;

    p4->right=p5;
    inorder(p1);
    delete(p1,7);
    printf("\n");
    inorder(p1);
    return 0;
}