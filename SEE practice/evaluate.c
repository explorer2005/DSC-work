#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100;
struct stack{
    int top;
    int size;
    int *arr;
};
int isEmpty(struct stack *s){
    return s->top==-1;
}
int isFull(struct stack *s){
    return s->top==s->size-1;
}
void push(struct stack *s, int data){
    if(isFull(s)){
        printf("The satck is full.\n");
        return;
    }
    else{
        s->arr[++s->top]=data;
        return;
    }
}
int pop(struct stack *s){
    if(isEmpty(s)){
        printf("The stack is empty\n");
        return 0;
    }
    else{
        int v=s->arr[s->top--];
        return v;
    }
}
void evaluate(char *postfix){
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->size=MAX;
    s->top=-1;
    s->arr=(int *)malloc(s->size*sizeof(int));
    for(int i=0;postfix[i]!='\0';i++){
        char ch=postfix[i];
        if(isdigit(ch)){
            push(s,ch-'0');
        }
        else{
            int b=pop(s);
            int a=pop(s);
            switch(ch){
                case '+':push(s,a+b);break;
                case '-':push(s,a-b);break;
                case '*':push(s,a*b);break;
                case '/':if(b==0){
                         printf("Not possible as denominator is 0\n");
                         return;
                        }
                        else{
                            push(s,a/b);
                        }
                        break;
                default:return;
            }
        }
    }
    printf("The ans is: %d\n",pop(s));
}
int main(){
    char ch[50];
    printf("Enter the postfix expression\n");
    scanf("%s",&ch);
    evaluate(ch);
    return 0;
}