#include<stdio.h>
#define MAX(a,b)  if(a>b)\
                    printf("a is maximum \n");\
                  else\
                    printf("b is maximum \n");
int main(){
    MAX(4,5);
    MAX(9,2);
}