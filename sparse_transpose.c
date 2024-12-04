#include<stdio.h>
#define MAX 100
#include<stdlib.h>
struct matrix{
    int row;
    int col;
    int val;
} sparse[MAX], result[MAX];
void display(struct matrix sparse[MAX]){
    for(int i=0;i<=sparse[0].val;i++){
        
        printf("%d\t%d\t%d",sparse[i].row,sparse[i].col,sparse[i].val);
        printf("\n");
    }
}
void fasttranspose(struct matrix sparse[MAX],struct matrix result[MAX]){
    int index[MAX]={0};
    int total[MAX]={0};

    result[0].row=sparse[0].col;
    result[0].col=sparse[0].row;
    result[0].val=sparse[0].val;

    for(int i=1;i<sparse[0].col;i++){
        index[sparse[i].col]++;
    }
    total[0]=1;
    for(int i=1;i<=sparse[0].col;i++){
        total[i]=total[i-i]+index[i-1];
    }
    for(int i=1;i<=sparse[0].val;i++){
        int loc=index[sparse[i].col]++;
        result[loc].row=sparse[i].col;
        result[loc].col=sparse[i].row;
        result[loc].val=sparse[i].val;
    }
}
void simpletranspose(struct matrix sparse[MAX],struct matrix resut[MAX]){
    result[0].row=sparse[0].col;
    result[0].col=sparse[0].row;
    result[0].val=sparse[0].val;

    int k=1;
    for(int col=0;col<sparse[0].col;col++){
        for(int i=1;i<=sparse[0].val;i++){
            if(sparse[i].col==col){
                result[k].row=sparse[i].col;
                result[k].col=sparse[i].row;
                result[k].val=sparse[i].val;
                k++;
            }
        }
    }
}
int main(){
    int r;
    int c;
    printf("Enter the number of rows and columns\n");
    scanf("%d %d",&r, &c);
    int mat[r][c];
    printf("Enter the elements of the matrix \n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    printf("\n\n The entered matrix is as follows \n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
    int v=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i][j]!=0){
                v++;
            }
        }
    }
    if(v<(r*c)/2){
        printf("\n Yes the sparse matrix is possible\n");
    }
    sparse[0].row=r;
    sparse[0].col=c;
    sparse[0].val=v;
    int k=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i][j]!=0){
                sparse[k].row=i;
                sparse[k].col=j;
                sparse[k].val=mat[i][j];
                k++;
            }
        }
    }
    display(sparse);
    printf("want to continue with which transpose please select the appropriate option \n");
    printf("1. Simple transpose\n");
    printf("2. Fast transpose\n");
    int a;
    scanf("%d",&a);
    switch(a){
        case 1: simpletranspose(sparse,result);
                display(result);
                break;
        case 2: fasttranspose(sparse,result);
                display(result);
                break;
        default: printf("Select an appropriate option \n");
                 break;
    }
}