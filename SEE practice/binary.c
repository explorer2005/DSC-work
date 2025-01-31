#include<stdio.h>
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    printf("The sorted array is\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void binarySearch(int arr[],int n,int s,int e,int k){
    if(s>e){
        printf("The element is not found\n");
        return;
    }
    int mid=s+(e-s)/2;
    if(arr[mid]==k){
        printf("The element is found at the index %d\n",mid);
    }
    else if(arr[mid]>k){
        binarySearch(arr,n,0,mid-1,k);
    }
    else{
        binarySearch(arr,n,mid+1,n-1,k);
    }
}
int main(){
    printf("Enter the size of the array\n");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    selectionSort(arr,n);
    printf("Enter the key to be searched\n");
    int k;
    scanf("%d",&k);
    binarySearch(arr,n,0,n-1,k);
    return 0;
}