#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
struct stack{
    int top;
    int size;
    char *arr;
};
int isEmpty(struct stack *s){
    return s->top==-1;
}
int isFull(struct stack *s){
    return s->top==s->size-1;
}
void push(struct stack *s, char data){
    if(isFull(s)){
        printf("The stack is full\n");
        return;
    }
    else{
        s->arr[++s->top]=data;
        return;
    }
}
char pop(struct stack *s){
    if(isEmpty(s)){
        printf("The stack is empty\n");
        return 0;
    }
    else{
        return s->arr[s->top--];
    }
}
int precedence(char ch){
    switch(ch){
        case '+':
        case '-': return 1;
        case '*':
        case '/':return 2;
    }
    return 0;
}
int isOperator(char ch){
    return ch=='+'||ch=='-'||ch=='*'||ch=='/';
}
void infixToPostfix(char *infix){
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->size=MAX;
    s->top=-1;
    s->arr=(char *)malloc(s->size*sizeof(char));
    char postFix[MAX];
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
        char k = infix[i];
        if((k>='a'&&k<='z')||(k>='A'&&k<='Z')){
            postFix[j++]=infix[i];
            i++;
        } 
        else if(k=='('){
            push(s,k);
            i++;
        }
        else if(k==')'){
            while(!isEmpty(s)&&s->arr[s->top]!='('){
                postFix[j++]=pop(s);
            }
            pop(s);
            i++;
        }
        else if(isOperator(k)){
            while(!isEmpty(s)&& precedence(k)<=precedence(s->arr[s->top])){
                postFix[j++]=pop(s);
            }
            push(s,k);
            i++;
        }
    }
    while(!isEmpty(s)){
        postFix[j++]=pop(s);
    }
    postFix[j]='\0';
    printf("The postfix expression is: %s\n",postFix);
}
int main(){
    char infix[MAX];
    printf("Enter the infix expression\n");
    scanf("%s",infix);
    infixToPostfix(infix);
    return 0;
}