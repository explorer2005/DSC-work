#include<stdio.h>
#include<stdlib.h>
struct stack{
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
void push(struct stack *s, int value){
    if(isFull(s)){
        printf("The stack is overflow \n");
    }
    else{
        (*s).arr[(*s).top++]=value;
    }
}
int pop(struct stack *s){
    if(isEmpty(s)){
        printf("The stack is underflow \n");
    }
    else{
        int k=(*s).arr[(*s).top];
        (*s).top--;
        return k;
    }
}
int peak_element(struct stack *s, int index){
    if((*s).top-index+1<0){
        printf("Your entered an invalid position\n");
    }
    else{
        return (*s).arr[(*s).top-index+1];
    }
}
int main(){
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    (*s).size=10;
    (*s).top=-1;
    (*s).arr=(int *)malloc((*s).size*sizeof(int));
    printf("%d\n",isFull(s));
    printf("%d\n",isEmpty(s));
    push(s,56);
    push(s,69);
    push(s,5);
    push(s,6);
    push(s,75);
    push(s,89);
    push(s,30);
    printf("%d\n",isFull(s));
    printf("%d\n",isEmpty(s));
    printf("%d\n",peak_element(s,1));
    pop(s);
    printf("%d\n",isFull(s));
    printf("%d\n",isEmpty(s));

    return 0;
}