#include<stdio.h>
#include<stdlib.h>
struct stack {
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *s){
    if((*s).top==-1){
        return 1;
    }
    return 0;
}
int isFull(struct stack *s){
    if((*s).top==(*s).size-1){
        return 1;
    }
    return 0;
}
int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    (*s).size=80;
    (*s).top=-1;
    (*s).arr=(int *)malloc(((*s).size)*sizeof(int));
    if(isEmpty(s)){
        printf("The stack is empty");
    }
    else{
        printf("The stack is not empty");
    }
    if(isFull(s)){
        printf("The stack is full");
    }
    else{
        printf("The stack is not full");
    }
}