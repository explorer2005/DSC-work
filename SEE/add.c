#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct poly{
    int degree;
    int coeff[MAX];
};
void initpoly(struct poly *p){
    p->degree=0;
    for(int i=0;i<MAX;i++){
        p->coeff[i]=0;
    }
}
void display(struct poly p){
    int first=1;
    for(int i=p.degree;i>=0;i--){
        if(p.coeff[i]!=0){
        if(first){
            printf("%dx^%d",p.coeff[i],i);
            first=0;
        }
        else{
            printf("+%dx^%d",p.coeff[i],i);
        }
        }
    }
}
void inputPoly(struct poly *p){
    printf("Enter the degree of the polynomial\n");
    int n;
    scanf("%d",&n);
    p->degree=n;
    printf("Enter the number of non zero terms\n");
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        printf("enter the degree and coefficient respectively\n");
        int pd,pc;
        scanf("%d%d",&pd,&pc);
        p->coeff[pd]=pc;
    }
}
struct poly addPoly(struct poly p1, struct poly p2){
    struct poly result;
    initpoly(&result);
    result.degree=(p1.degree>p2.degree)?p1.degree:p2.degree;
    for(int i=result.degree;i>=0;i--){
        result.coeff[i]=p1.coeff[i]+p2.coeff[i];
    }
    return result;
}
int main(){
    struct poly p1;
    struct poly p2;
    initpoly(&p1);
    initpoly(&p2);
    inputPoly(&p1);
    inputPoly(&p2);
    struct poly ans;
    initpoly(&ans);
    ans=addPoly(p1,p2);
    display(ans);
    return 0;
}