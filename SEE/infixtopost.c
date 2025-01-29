#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct stack{
    int size;
    int top;
    char *arr;
};
struct stack* create(int size){
    struct stack * s = (struct stack*)malloc(sizeof(struct stack));
    s->top=-1;
    s->size=size;
    s->arr=(char *)malloc(s->size*sizeof(char));
    return s;
}
int isFull(struct stack *s){
    if(s->top==s->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(struct stack *s){
    if(s->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
struct stack * push(struct stack * s,int data){
    if(isFull(s)){
        printf("The stack is full\n");
        return s;
    }
    else{
        s->arr[++s->top]=data;
        return s;
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
        case '-':return 1;break;
        case '*':
        case '/':return 2;break;
    }
}
int isOperator(char ch){
    return ch=='+'||ch=='-'||ch=='/'||ch=='*';
}
char * infixToPostfix(char *infix){
    struct stack *s=create(100);
    char * postfix = (char *)malloc(100*sizeof(char));
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
        char ch = infix[i];
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
            postfix[j++]=infix[i++];
        }
        else if(isOperator(ch)){
            while(!isEmpty(s)&&precedence(ch)<=precedence(s->arr[s->top])){
                postfix[j++]=pop(s);
            }
            push(s,infix[i++]);
        }
        else if(ch=='('){
            push(s,ch);
            i++;
        }
        else if(ch==')'){
            while(!isEmpty(s)&&s->arr[s->top]!='('){
                postfix[j++]=pop(s);
            }
            if(!isEmpty(s)&&s->arr[s->top]=='('){
                pop(s);
            }
            i++;
        }
    }
    while(!isEmpty(s)){
        postfix[j++]=pop(s);
    }
    postfix[j]='\0';
    return postfix;
}
int main(){
    char ch[100];
    printf("Enter the infix expression\n");
    scanf("%s",&ch);
    char* ans = infixToPostfix(ch);
    printf("The postfix expression is: %s\n",ans);
    return 0;
}