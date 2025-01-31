#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct poly{
    int degree;
    int coeff[MAX];
};
void initPoly(struct poly *p){
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
void addPoly(struct poly p1,struct poly p2){
    printf("Addition\n");
    struct poly result;
    initPoly(&result);
    result.degree=(p1.degree>p2.degree)?p1.degree:p2.degree;
    for(int i=result.degree;i>=0;i--){
        result.coeff[i]=p1.coeff[i]+p2.coeff[i];
    }
    printf("Now displaying\n");
    display(result);
}
void inputPoly(struct poly *p){
    printf("Enter the degree of the polynomial\n");
    int de;
    scanf("%d",&de);
    p->degree=de;
    printf("Enter the number of non zero terms\n");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the coeff and degree respectively\n");
        int nd;
        int nc;
        scanf("%d%d",&nd,&nc);
        p->coeff[nd]=nc;
    }
}
int main(){
    struct poly p1;
    struct poly p2;
    initPoly(&p1);
    initPoly(&p2);
    inputPoly(&p1);
    inputPoly(&p2);
    printf("Now adding the polynomial\n");
    addPoly(p1,p2);
    return 0;
}
