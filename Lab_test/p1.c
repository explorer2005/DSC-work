#include<stdio.h>
int binarySearch(int arr[],int s,int e, int k){
    int m = s+(e-s)/2;
    if(arr[m]==k){
        return m+1;
    }
    else if(arr[m]<k){
        return binarySearch(arr,m+1,e,k);
    }
    else{
        return binarySearch(arr,0,m-1,k);
    }
    return 0;
}
void selectionSort(int arr[],int n){
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
    printf("Sorted array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    printf("Whta you wanted to do? type 1 for selection sort and 2 for recursive binary search!");
    int k;
    scanf("%d",&k);
    if(k==1){
        printf("Enter the size of the array to be sorted");
        int n;
        scanf("%d",&n);
        int arr[n];
        printf("Enter the elements of the array");
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        selectionSort(arr,n);
    }
    else if (k==2){
        printf("Enter the size of the array");
        int n;
        scanf("%d",&n);
        int arr[n];
        printf("Enter the elements of the array.");
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        printf("Enter the element to be searched");
        int key;
        scanf("%d",&key);
        int ans = binarySearch(arr,0,n-1,key);
        if(ans!=0){
            printf("Element is found at the index  %d",ans);
        }
        else{
            printf("Ans not found in the given array");
        }
    }
    else{
        printf("You have entered a wrong input");
    }
    return 0;
}