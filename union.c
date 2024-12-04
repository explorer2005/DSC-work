#include<stdio.h>
#include<string.h>
union Student{
        char name[20];
        int marks;
        int Id;
        char usn[20];
} s1, s2;
int main(){
    strcpy(s1.name,"Dhruv");
    strcpy(s2.name,"Riya");
    s1.marks=200;
    printf("The marks of s1 are %d \n",s1.marks);
    s2.marks=250;
    s1.Id=369;
    s2.Id=370;
    strcpy(s1.usn,"1MS23CS059");
    strcpy(s2.usn,"1MS23CS060");
    printf("The marks of s1 are %d \n",s1.marks);
    printf("The marks of s1 are %d \n",s1.name);
    printf("The marks of s1 are %d \n",s2.marks);
    printf("The marks of s1 are %d \n",s2.name);


}