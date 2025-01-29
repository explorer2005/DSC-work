#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *rlink;
    struct node *llink;
};
struct node * createNode(int data){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->rlink=NULL;
    newNode->llink=NULL;
    return newNode;
}
void preorder(struct node*root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->llink);
        preorder(root->rlink);
    }
}
void postorder(struct node*root){
    if(root!=NULL){
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d ",root->data);
    }
}
void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->llink);
        printf("%d ",root->data);
        inorder(root->rlink);
    }
}
struct node * insert(struct node *root, int data){
    if(root==NULL){
        root=createNode(data);
        printf("Inserted the element%d\n",data);
        return root;
    }
    else if(root->data<data){
        root->rlink=insert(root->rlink,data);
        return root;
    }
    else if(root->data>data){
        root->llink=insert(root->llink,data);
        return root;
    }
    else{
        printf("The same data cannotbe inserted\n");
        return root;
    }
}
void search(struct node *root,int data){
    if(root!=NULL){
    if(root->data==data){
        printf("The data is found in the binarysearch tree\n");
        return;
    }
    else if(root->data>data){
        search(root->llink,data);
    }
    else if(root->data<data){
        search(root->rlink,data);
    }
    }
    else{
        printf("The element is not in the binary search tree\n");
        return;
    }
}
int main(){
    struct node *root=NULL;
    int t=1;
    while(t){
        printf("Select the appropriate option\n1.Insert\n2.PreOrder\n3.PostOrder\n4.Inorder\n5.Search\n");
        int k;
        scanf("%d",&k);
        switch(k){
            case 1:printf("Enter the data to be inserted\n");
                   int data;
                   scanf("%d",&data);
                   root=insert(root,data);
                   break;
            case 2:preorder(root);
                   break;
            case 3:postorder(root);
                   break;
            case 4:inorder(root);
                   break;
            case 5:printf("Enter the element to be searched\n");
                   int data2;
                   scanf("%d",&data2);
                   search(root,data2);
                   break;
            default:printf("Enter correct option\n");
                    t=0;
        }
    }
    return 0;
}