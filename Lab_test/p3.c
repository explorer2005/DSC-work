#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct polynomial{
    int degree;
    int coeff[MAX];
}p1,p2,result;
void initpoly(struct polynomial *p){
    p->degree=0;
    for(int i=0;i<MAX;i++){
        p->coeff[i]=0;
    }
}
void inputPoly(struct polynomial *p){
    printf("Enter the degree of the polynomial\n");
    int d;
    scanf("%d",&d);
    p->degree=d;
    printf("Enter the number of non zero terms\n");
    int nt;
    scanf("%d",&nt);
    for(int i=0;i<nt;i++){
        printf("Enter the degree and coeff respectively\n");
        int pd,pc;
        scanf("%d %d",&pd,&pc);
        p->coeff[pd]=pc;
    }
}
struct polynomial addPoly(struct polynomial p1, struct polynomial p2){
    struct polynomial result;
    initpoly(&result);
    result.degree=((p1.degree)>(p2.degree))?p1.degree:p2.degree;
    for(int i=result.degree;i>=0;i--){
        result.coeff[i]=p1.coeff[i]+p2.coeff[i];
    }
    return result;
}
void display(struct polynomial p){
    int first=1;
    for(int i=p.degree;i>=0;i--){
        if(p.coeff[i]!=0){
            if(first){
               printf("%dx^%d",p.coeff[i],i);
               first=0;
    }
}
// void display(struct polynomial p){
//     int first = 1; // Flag to track the first term
//     for(int i=p.degree;i>=0;i--){
//         if(p.coeff[i] != 0){
//             if(first) {
//                 printf("%dx^%d", p.coeff[i], i); // Print the first term without '+'
//                 first = 0; // Set flag to false after printing the first term
//             } else {
//                 printf(" + %dx^%d", p.coeff[i], i); // Print subsequent terms with '+'
//             }
//         }
//     }
//     printf("\n"); // Print newline after polynomial
// }

int main(){
    printf("Enter polynomial 1\n");
    initpoly(&p1);
    inputPoly(&p1);
    printf("Enter polynomial 2\n");
    initpoly(&p2);
    inputPoly(&p2);

    struct polynomial ans = addPoly(p1,p2);
    display(ans);
}