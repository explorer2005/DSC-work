#include<stdio.h>
#include<string.h>
void computeLPSarray(char *pattern, int m, int  *lps){
    int len=0;
    lps[0]=0;
    int i=1;
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
void KMP(char *text,char *pattern){
    int n=strlen(text);
    int m=strlen(pattern);
    int lps[m];
    computeLPSarray(pattern,m,lps);
    int i=0;
    int j=0;
    int found=0;
    while(i<n){
        if(pattern[j]==text[i]){
            i++;
            j++;
        }
        if(j==m){
            found=1;
            printf("Pattern found at index %d\n",i);
            j=lps[j-1];
        }
        else if(i<n&&pattern[j]!=text[i]){
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    if(!found){
        printf("Pattern not found\n");
    }
}
void nfind(char *text, char *pattern){
    int n=strlen(text);
    int m=strlen(pattern);
    int found =0;
    for(int i=0;i<=n-m;i++){
        int j;
        for(j=0;j<m;j++){
            if(text[i+j]!=pattern[j]){
                break;
            }
        }
        if(j==m){

            found=1;
            printf("Pattern found at index%d\n",i);
        }
    }
    if(!found){
        printf("Pattern not found\n");
    }
}
int main(){
    char text[50];
    char pattern[50];
    printf("Enter the text\n");
    scanf("%s",text);
    printf("Enter the pattern\n");
    scanf("%s",pattern);
    printf("Select\n1.KMP\n2.Nfind\n");
    int k;
    scanf("%d",&k);
        if(k==1){
            KMP(text,pattern);
        }
        else{
            nfind(text,pattern);
        }
}