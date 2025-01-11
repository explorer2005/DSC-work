#include<stdio.h>
#include<stdlib.h>
struct sparse{
    int r;
    int c;
    int v;
}s[100];
void sparseMatrix(int arr[][60], int row, int col){
    //printf("Reached in function\n");
    int k=1;
    
    for(int i=0;i<row;i++){
        //printf("inside loop 1\n");
        for(int j=0;j<col;j++){
              //printf("inside loop 2\n");
            if(arr[i][j]!=0){
                  //printf("if cond");
                s[k].r=i;
                s[k].c=j;
                s[k].v=arr[i][j];
                k++;
            } 
        }
        //printf("out of loop 2\n");
    }
    //printf("Loop finished");
    s[0].r=row;
    s[0].c=col;
    s[0].v=k-1;
    for(int i=0;i<k;i++){
        printf("%d %d %d",s[i].r,s[i].c,s[i].v);
        printf("\n");
    }

}
int main(){
    printf("Enter the number of rows and columns respectively\n");
    int r, c;
    scanf("%d %d",&r,&c);
    int arr[r][c];
    printf("Enter the elements of the matrix\n");
    int count = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==0){
                count++;
            }
        }
    }
    if(count>=(r*c)/2){
        printf("Sparse Matrix is possible\n");
        printf("Select from the options below\n");
        printf("1. Sparse matrix\n2. fast transpose\n3. slow transpose\n");
        int v;
        scanf("%d",&v);
        if(v==1){
            sparseMatrix(arr,r,c);
        }
        else if(v==2){

        }
        else if(v==3){

        }
        else{
            printf("Wrong input\n");
        }
    }
    else{
        printf("No need of sparse matrix as number of zeroes is less\n");
    }
    return 0;
}