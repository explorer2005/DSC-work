#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct stack{
    int size;
    int top;
    int *arr;
};
struct stack* create(int size){
    struct stack * s = (struct stack*)malloc(sizeof(struct stack));
    s->top=-1;
    s->size=size;
    s->arr=(int *)malloc(s->size*sizeof(int));
    return s;
}
int isEmpty(struct stack *s){
    if(s->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack *s){
    if(s->top==s->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
struct stack * push(struct stack *q,int data){
    if(isFull(q)){
        printf("The stack is full\n");
        return q;
    }
    else{
        q->arr[++q->top]=data;
        return q;
    }
}
int pop(struct stack *q){
    if(isEmpty(q)){
        printf("The stack is empty\n");
        return 0;
    }
    else{
        return q->arr[q->top--];
    }
}
int evaluate(char* postfix){
    struct stack *s=create(100);
    for(int i=0;postfix[i]!='\0';i++){
        char ch = postfix[i];
        if(isdigit(ch)){
            push(s,ch-'0');
        }
        else{
            int b =pop(s);
            int a =pop(s);
            switch(ch){
                case '+':push(s,a+b);
                         break;
                case '-':push(s,a-b);
                         break;
                case '*':push(s,a*b);
                         break;
                case '/':if(b!=0){
                            push(s,a/b);
                        }
                        else{
                            printf("Expression is invalid\n");
                        }
            }
        }
    }
    return s->arr[s->top];
}
int main(){
    char ch[100];
    printf("Enter the postfix expression\n");
    scanf("%s",&ch);
    int ans=evaluate(ch);
    printf("The ans is: %d\n",ans);
    return 0;
}