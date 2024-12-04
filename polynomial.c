#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct Polynomial{
    int degree;
    int coeff[MAX];
} p1,p2,result;
void initpoly(struct Polynomial *p){
    (*p).degree=0;
    for(int i=0;i<MAX;i++){
        (*p).coeff[i]=0;
    }
}
void inputpoly(struct Polynomial *p){
    printf("Enter the degree of the polynomial \n");
    scanf("%d",&(*p).degree);

    printf("Enter the corresponding coefficients \n");
    for(int i=(*p).degree;i>=0;i--){
        printf("Enter the coefficient for x^%d: \n",i);
        scanf("%d",&(*p).coeff[i]);
    }
}
struct Polynomial addpoly(struct Polynomial p1, struct Polynomial p2){
    struct Polynomial result;
    initpoly(&result);
    result.degree=p1.degree>p2.degree? p1.degree: p2.degree;
    for(int i=0;i<=result.degree;i++){
        result.coeff[i]=p1.coeff[i]+p2.coeff[i];
    }
    return result;
}
void display(struct Polynomial a){
    printf("The added polynomial is \n");
    for(int i=a.degree;i>=0;i--){
        printf("%dx^%d +",a.coeff[i],i);
    }
}
int main(){
    initpoly(&p1);
    initpoly(&p2);
    printf("Now we will take the input for polynomials \n");
    inputpoly(&p1);
    inputpoly(&p2);
    result=addpoly(p1,p2);
    display(result);
}