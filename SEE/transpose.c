#include<stdio.h>
#include<stdlib.h>
struct sparse{
    int r;
    int c;
    int v;
};
void display(struct sparse s[]){
    for(int i=0;i<=s[0].v;i++){
        printf("%d %d %d\n",s[i].r,s[i].c,s[i].v);
    }
}
void sparseMatrix(int arr[][30],int row,int col,struct sparse s[]){
    int k=1;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]!=0){
                s[k].r=i;
                s[k].c=j;
                s[k].v=arr[i][j];
                k++;
            }
        }
    }
    s[0].r=row;
    s[0].c=col;
    s[0].v=k-1;
    display(s);
}
void simpleTranspose(struct sparse s[], struct sparse a[]){
    int k=1;
    for(int col=0;col<s[0].c;col++){
        for(int i=1;i<=s[0].v;i++){
            if(s[i].c==col){
                a[k].r=s[i].c;
                a[k].c=s[i].r;
                a[k].v=s[i].v;
                k++;
            }
        }
    }
    a[0].r=s[0].c;
    a[0].c=s[0].r;
    a[0].v=s[0].v;
    display(a);
}
void fastTranspose(struct sparse s[], struct sparse a[]){
    int index[100]={0};
    int total[100]={0};
    for(int i=1;i<=s[0].v;i++){
        index[s[i].c]++;
    }
    total[0]=1;
    for(int i=1;i<=s[0].c;i++){
        total[i]=total[i-1]+index[i-1];
    }
    for(int i=1;i<=s[0].v;i++){
        int loc = total[s[i].c]++;
        a[loc].r=s[i].c;
        a[loc].c=s[i].r;
        a[loc].v=s[i].v;
    }
    a[0].r=s[0].c;
    a[0].c=s[0].r;
    a[0].v=s[0].v;
    display(a);
}
int main(){
    struct sparse s[50];
    struct sparse a[50];
    printf("Enter the number of rows and coloumns respectively\n");
    int r;
    int c;
    scanf("%d%d",&r,&c);
    int arr[r][30];
    printf("Enter the elements of the matrix\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    sparseMatrix(arr,r,c,s);
    printf("Enter an option\n1.Simple Transpose\n2.Fast Transpose\n");
    int k;
    scanf("%d",&k);
    switch(k){
        case 1:simpleTranspose(s,a);
               break;
        case 2:fastTranspose(s,a);
               break;
    }
    return 0;
}