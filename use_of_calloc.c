#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr;
    int n;
    printf("Enter the no of elements in the array \n");
    scanf("%d",&n);
    ptr=(int*)calloc(n,sizeof(int));
    printf("Enter the elements of the array \n");
    for(int i=0;i<n;i++){
        printf("Enter the elements of the array at the position %d\n",i);
        scanf("%d",&ptr[i]);
    }
    for(int i=0;i<n;i++){
        printf("The element at the %d position is:%d\n",i,ptr[i]);
    }
    return 0;
}