#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *rlink;
    struct node *llink;
};
struct node *createNode(int data){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->rlink=NULL;
    newNode->llink=NULL;
    return newNode;
}
struct node *insert(struct node *root,int data){
    if(!root){
        struct node *newNode=createNode(data);
        return newNode;
    }
    else{
    if(root->data==data){
        printf("Same value cannot be inserted\n");
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
    
}
void preorder(struct node *root){
    if(root){
        printf("%d ",root->data);
        preorder(root->llink);
        preorder(root->rlink);
    }
}
void postorder(struct node *root){
    if(root){
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d ",root->data);
    }
}
void inorder(struct node*root){
    if(root){
        inorder(root->llink);
        printf("%d ",root->data);
        inorder(root->rlink);
    }
}
void search(struct node *root, int data){
    if(!root){
        printf("The element is not present in the bst\n");
        return;
    }
    else{
        if(root->data==data){
            printf("The data is found successfully in the BST\n");
            return;
        }
        else if(root->data>data){
            search(root->llink,data);
        }
        else{
            search(root->rlink,data);
        }
    }
}
int main(){
    struct node *root=NULL;
    int t=1;
    while(t){
        printf("Select the appropriate option\n1.Insert\n2.Search\n3.PreOrder\n4.PostOrder\n5.InOrder\n");
        int k;
        scanf("%d",&k);
        switch(k){
            case 1:printf("Enter the value to be inserted\n");
                   int value;
                   scanf("%d",&value);
                   root=insert(root,value);
                   printf("Successfully inserted the element\n");
                   break;
            case 2:printf("Enter the element to be searched\n");
                   int data;
                   scanf("%d",&data);
                   search(root,data);
                   break;
            case 3:preorder(root);
                   break;
            case 4:postorder(root);
                   break;
            case 5:inorder(root);
                   break;
            default:printf("Enter a valid input\n");
                    t=0;
        }
    }
}