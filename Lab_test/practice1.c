#include<stdio.h>
void binarySearch(int arr[1000],int s,int e,int k){
    int mid=s+(e-s)/2;
    if(s>e){
        printf("Key not found\n");
        return;
    }
    if(arr[mid]==k){
        printf("The number is found at the index %d\n",mid);
        return;
    }
    else if(k>arr[mid]){
        binarySearch(arr,mid+1,e,k);
    }
    else if(k<arr[mid]){
        binarySearch(arr,s,mid-1,k);
    }
    
}
void selectionSort(int arr[1000],int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}
int main(){
    printf("Enter the size of the array\n");
    int n;
    scanf("%d",&n);
    int arr[1000];
    printf("Enter the elements of the array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    selectionSort(arr,n);
    printf("Sorted \n");
    printf("Enter the key to be searched\n");
    int k;
    scanf("%d",&k);
    binarySearch(arr,0,n-1,k);
}