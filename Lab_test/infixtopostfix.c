#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int size;
    int top;
    char *arr;
};
int isEmpty(struct stack *s){
    // if(s->top==-1){
    //     return 1;
    // }
    // return 0;
    return s->top==-1;
}
int isFull(struct stack *s){
    // if(s->top==s->size-1){
    //     return 1;
    // }
    // return 0;
    return s->top==s->size-1;
}
void push(struct stack *s,char data){
    if(!isFull(s)){
        s->arr[++s->top]=data;
    }
    else{
        printf("The stack is full\n");
    }
}
char pop(struct stack *s){
    if(!isEmpty(s)){
        return(s->arr[s->top--]);
    }
    else{
        printf("The stack is empty\n");
        return NULL;
    }
}
int precedence(char ch){
    switch(ch){
        case '+': 
        case '-': return 1;
                  break;
        case '*':
        case '/': return 2;
                  break;
        default: return 0;
    }
}
int isOperator(char ch){
    return ch=='+'||ch=='-'||ch=='*'||ch=='/'; 
}

char *infixtopostfix(char *infix){
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->size=strlen(infix);
    s->top=-1;
    s->arr=(char *)malloc(s->size*(sizeof(char)));

    int i=0;
    int j=0;
    char *postfix=(char *)malloc((s->size+1)*sizeof(char));
    while(infix[i]!='\0'){
    if(infix[i]>='a'&& infix[i]<='z' || infix[i]>='A'&&infix[i]<='Z'){
        postfix[j++]=infix[i++];
    }
    else if(infix[i]=='('){
            push(s,infix[i++]);
    }
    else if(infix[i]==')'){
        while(!isEmpty(s)&&s->arr[s->top]!='('){
            postfix[j++]=pop(s);
        }
        if(!isEmpty(s)&&s->arr[s->top]=='('){
            pop(s);
        }
        i++;
    }
    else if(isOperator(infix[i])){
        while(!isEmpty(s)&&precedence(s->arr[s->top]>=precedence(infix[i]))){
            postfix[j++]=pop(s);
        }
        push(s,infix[i++]);
    }
    }
    while(!isEmpty(s)){
        postfix[j++]=pop(s);
    }
    postfix[j]='\0';
    return postfix;
}
int main(){
    char infix[200];
    printf("Enter the infix expression\n");
    scanf("%s",&infix);
    char *postfix = infixtopostfix(infix);
    printf("The ans is: %s\n",postfix);
    return 0;

}