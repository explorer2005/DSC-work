#include<stdio.h>
#include<string.h>
void nway (char * give, char *pattern){
    int n=strlen(give);
    int m=strlen(pattern);
    int found=0;
    for(int i=0;i<=n-m;i++){
        int j;
        for(j=0;j<m;j++){
            if(give[i+j]!=pattern[j]){
                break;
            }
            
        }
        if(j==m){
                found=1;
                printf("Pattern is found at %d\n",i);
            }
    }
    if(!found){
        printf("Pattern not found\n");
    }
}
int main(){
    char give[100];
    char pattern[100];
    printf("Enter the pattern\n");
    scanf("%s",&give);
    printf("Enter the pattern to be searched\n");
    scanf("%s",&pattern);
    nway(give,pattern);
}