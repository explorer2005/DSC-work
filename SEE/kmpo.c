#include<stdio.h>
#include<string.h>
void computeLPSArray(char *pattern, int m, int *lps){
    int len=0;
    int i=1;
    lps[0]=0;
    while(i<m){
        if(pattern[i]==pattern[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}
void kmp(char *text, char *pattern){
    int n=strlen(text);
    int m=strlen(pattern);
    int lps[m];
    computeLPSArray(pattern,m,lps);
    int i=0;
    int j=0;
    int found=0;
    while(i<n){
        if(pattern[j]==text[i]){
            i++;
            j++;
        }
        if(j==m){
            printf("The pattern is found at index %d\n",i-j);
            j=lps[j-1];
            found=1;
        }
        else if(i<n&&pattern[j]!=text[i]){
            if(j==0){
                i++;
            }
            else{
                j=lps[j-1];
            }
        }
    }
    if(!found){
        printf("Not found\n");
    }
}
int main(){
    char give[100];
    char pattern[100];
    printf("Enter the pattern\n");
    scanf("%s",&give);
    printf("Enter the pattern to be searched\n");
    scanf("%s",&pattern);
    kmp(give,pattern);
}