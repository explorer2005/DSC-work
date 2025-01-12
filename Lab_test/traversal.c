#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *rlink;
    struct node *llink;
};
struct node * insert(struct node * root, int data){
    if(!root){
        root=(struct node*)malloc(sizeof(struct node));
        root->data=data;
        root->rlink=NULL;
        root->llink=NULL;
        return root;
    }
    else if(root->data>data){
        root->llink=insert(root->llink,data);
        return root;
    }
    else{
        root->rlink=insert(root->rlink,data);
        return root;
    }
}
void preorder(struct node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->llink);
        preorder(root->rlink);
    }
}
void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->llink);
        printf("%d ",root->data);
        inorder(root->rlink);
    }
}
void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d ",root->data);
    }
}
void search(struct node *root, int data){
    if(root!=NULL){
        if(root->data==data){
            printf("The value is found\n");
            return;
        }
        else if(root->data>data){
            search(root->llink,data);
        }
        else{
            search(root->rlink,data);
        }
    }
    if(root==NULL){
            printf("The element is not found.\n");
            return;
    }
}
int main(){
    struct node *root=NULL;
    int t=1;
    while(t){
        printf("Select the appropriate option\n1.Insert\n2.Inorder\n3.PreOrder\n4.PostOrder\n5.Exit\n");
        int k;
        scanf("%d",&k);
        switch(k){
            case 1:printf("Enter the element to be inserted\n");
                   int v;
                   scanf("%d",&v);
                   root=insert(root,v);
                   printf("The %d is inserted\n",v);
                   break;
            case 2:inorder(root);
                   break;
            case 3:preorder(root);
                   break;
            case 4:printf("Enter the element to be searched\n");
                   int t;
                   scanf("%d",&t);
                   search(root,t);
                   break;
            case 5:printf("Exiting.....\n");
                   t=0;
                   exit(0);
                   break;
        }
    }
}