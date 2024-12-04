// Online C compiler to run C program online
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack {
        int size;
        int top;
        char *arr;
};
int isFull(struct stack *s){
    if((*s).top==(*s).size-1){
        return 1;
    }
    return 0;
}
int isEmpty(struct stack *s){
    if((*s).top==-1){
        return 1;
    }
    return 0;
}
int precedence(char ch){
    switch(ch){
        case '+':
        case '-': return 1;
        case '*': 
        case '/': return 2;
        case '^': return 3;
        default : return 0;
    }
}
int isOperator(char ch){
    if(ch=='+'|| ch=='-'|| ch=='*' || ch=='/'){
        return 1;
    }
    else{
        return 0;
    }
}
char pop(struct stack *s){
    if(!isEmpty(s)){
        int v=(*s).arr[(*s).top];
        (*s).top--;
        return v;
    }
    else{
        return '\0';
    }
}
void push(struct stack *s, char val){
    if(!isFull(s)){
        (*s).top++;
        (*s).arr[(*s).top]=val;
    }
    else{
        printf("The stack is overflown \n");
    }
}
char *infixtopostfix(char * infix){
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    (*s).size=10;
    (*s).top=-1;
    (*s).arr=(char *)malloc((*s).size*sizeof(char));
    char *postfix = (char *)malloc((strlen(infix)+1)*sizeof(char));
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
    if(!isOperator(infix[i])){
        if(infix[i]>='a'&&infix[i]<='z'||infix[i]>='A'&&infix[i]<='Z'){
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else if(infix[i]=='('){
            push(s,infix[i]);
            i++;
        }
        else if(infix[i]==')'){
            while(!isEmpty(s)&&(*s).arr[(*s).top]!='('){
                postfix[j]=pop(s);
                j++;
            }
            if(!isEmpty(s)&&(*s).arr[(*s).top]=='('){
                pop(s);
            }
            i++;
        }
    }
    else{
        if(precedence(infix[i])>precedence((*s).arr[(*s).top])){
            push(s, infix[i]);
            i++;
        }
        else{
            postfix[j]=pop(s);
            j++;
        }
    }
    }
    while(!isEmpty(s)){
        postfix[j]=pop(s);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}
int main(){
    char *infix="(x-y/z)*(k+d)";
    printf("The postfix expression is: %s",infixtopostfix(infix));
    return 0;
}