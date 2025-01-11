#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct sparse{
    int r;
    int c;
    int v;
}sparse[MAX],result[MAX];
void display(struct sparse sparse[MAX]){
    for(int i=0;i<=sparse[0].v;i++){
        printf("%d  %d  %d\n",sparse[i].r,sparse[i].c,sparse[i].v);
    }
}
void fastTranspose(struct sparse sparse[MAX],struct sparse result[MAX]){
    int index[MAX]={0};
    int total[MAX]={0};

    result[0].r=sparse[0].c;
    result[0].c=sparse[0].r;
    result[0].v=sparse[0].v;

    total[0]=1;
    for(int i=1;i<=sparse[0].c;i++){
        index[sparse[i].c]++;
    }

    for(int i=1;i<sparse[0].c;i++){
        total[i]=total[i-1]+index[i-1];
    }
    int k=1;
    for(int i=1;i<=sparse[0].v;i++){
        int loc = total[sparse[i].c]++;
        result[loc].r=sparse[i].c;
        result[loc].c=sparse[i].r;
        result[loc].v=sparse[i].v;
    }

    display(result);
}
void simpleTranspose(struct sparse sparse[MAX],struct sparse result[MAX]){
    result[0].r=sparse[0].c;
    result[0].c=sparse[0].r;
    result[0].v=sparse[0].v;

    int k=1;
    for(int col=0;col<sparse[0].c;col++){
        for(int i=1;i<=sparse[0].v;i++){
            if(sparse[i].c==col){
                result[k].r=sparse[i].c;
                result[k].c=sparse[i].r;
                result[k].v=sparse[i].v;
                k++;
            }
        }
    }
    display(result);
}
void sparseMatrix(int arr[][60],int row,int col){
    printf("Sparse Matrix is: \n");
    int k=1;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]!=0){
                sparse[k].r=i;
                sparse[k].c=j;
                sparse[k].v=arr[i][j];
                k++;
            }
        }
    }
    sparse[0].r=row;
    sparse[0].c=col;
    sparse[0].v=k-1;
    display(sparse);
}
int main(){
    printf("Enter the number of rows and columns respectively\n");
    int r,c;
    scanf("%d %d",&r,&c);
    int arr[r][c];
    printf("Enter the elements of the matrix\n");
    int count=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j]!=0){
                count++;
            }
        }
    }
    if(count<(r*c)/2){
        printf("Sparse matrix is useful and beneficial\n");
        printf("Select an appropriate option\n1.sparse matrix \n2.simple transpose \n3.fast transpose\n");
        int k;
        scanf("%d",&k);
        if(k==1){
            sparseMatrix(arr,r,c);
        }
        else if(k==2){
            sparseMatrix(arr,r,c);
            simpleTranspose(sparse,result);
        }
        else if(k==3){
            sparseMatrix(arr,r,c);
            fastTranspose(sparse,result);
        }
        else{
            printf("You have entered a wrong input\n");
        }
    }
    return 0;

}