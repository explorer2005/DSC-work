#include<stdio.h>
#include<strings.h>
int main(){
    char big[10];
    char small[4];
    printf("Enter the bigger string \n");
    scanf("%s",&big);
    printf("Enter the smaller string \n");
    scanf("%s",&small);
    int max=strlen(big)-strlen(small)+1;
    int flag=0;
    for(int i=0;i<max;i++){
        int j;
        for(j=0;j<strlen(small);j++){
            if(big[i+j]!=small[j]){
                break;
            }
        }
        if(j==strlen(small)){
        printf("The pattern is found\n");
        flag=1;
    }
    }
    if(flag==0){
        printf("The pattern is not found\n");
    }

    }
    