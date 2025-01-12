#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
struct stack{
    int size;
    int top;
    int *arr;
};
struct stack * create(int size){
    struct stack *q=(struct stack *)malloc(sizeof(struct stack));
    q->size=size;
    q->top=-1;
    q->arr=(int *)malloc(q->size*sizeof(int));
    return q;
}
int isFull(struct stack *q){
    return q->top==q->size-1;
}
int isEmpty(struct stack *q){
    return q->top==-1;
}
struct stack * push(struct stack *q,int value){
    if(!isFull(q)){
        q->arr[++q->top]=value;
        return q;
    }
}
int pop(struct stack *q){
    if(!isEmpty(q)){
        return q->arr[q->top--];
    }
}
int evaluate(char *postfix){
    struct stack *q=create(100);
    for(int i=0;postfix[i]!='\0';i++){
        char ch=postfix[i];

        if(isdigit(ch)){
            push(q,ch-'0');
        }
        else{
            int b=pop(q);
            int a=pop(q);
            switch(ch){
                case '+': push(q,a+b);break;
                case '-': push(q,a-b);break;
                case '*': push(q,a*b);break;
                case '/': if(b==0){
                    printf("Not possible\n");
                    return -1;
                }
                else{
                    push(q,a/b);
                }
                break;
            }
        }
    }
    return pop(q);
}
int main(){
    char ch[100];
    printf("Enter the postfix expression\n");
    scanf("%s",&ch);
    int ans=evaluate(ch);
    if(ans==-1){
        printf("Error in the expression\n");
    }
    else{
        printf("The ans is: %d\n",ans);
    }
}