#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct heap{
    int size;
    int *arr;
};
void delete(struct heap *h){
    if(h->size<=0){
        printf("The heap is underflown\n");
        return;
    }
    int root=h->arr[0];
    h->arr[0]=h->arr[h->size-1];
    h->size--;

    int i=0;
    while(1){
        int left = 2*i+1;
        int right = 2*i+2;
        int largest=i;
        if(left<h->size&&h->arr[left]>h->arr[0]){
            largest=left;
        }
        if(right<h->size&&h->arr[right]>h->arr[0]){
            largest=right;
        }
        if(largest!=i){
            int temp=h->arr[i];
            h->arr[i]=h->arr[largest];
            h->arr[largest]=temp;
            i=largest;
        }
        else{
            break;
        }
    }
    printf("Deleted the element %d\n",root);
}
void insert(struct heap *h,int data){
    if(h->size>MAX){
        printf("The heap is overflown\n");
        return;
    }
    h->arr[h->size]=data;
    int i=h->size;
    h->size++;

    while(i!=0&&h->arr[i]>h->arr[(i-1)/2]){
        int temp=h->arr[i];
        h->arr[i]=h->arr[(i-1)/2];
        h->arr[(i-1)/2]=temp;
        i=(i-1)/2;
    }
    printf("Inserted the element %d\n",data);
}
void display(struct heap h){
    if(h.size<=0){
        printf("The heap is empty\n");
        return;
    }
    for(int i=0;i<h.size;i++){
        printf("%d ",h.arr[i]);
    }
    printf("\n");
}
int main(){
    struct heap h;
    h.size=0;
    int t=1;
    while(t){
        printf("Select an appropriate option\n1.Insert\n2.Delete\n3.Display\n");
        int k;
        scanf("%d",&k);
        switch(k){
            case 1:printf("Enter the value to be inserted\n");
                   int value;
                   scanf("%d",&value);
                   insert(&h,value);
                   break;
            case 2:delete(&h);break;
            case 3:display(h);break;
            default:printf("Enter a valid input\n");
                    t=0;
        }
    }
}