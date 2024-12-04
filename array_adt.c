#include<stdio.h>
#include<stdlib.h>
struct myArray {
    int total_size;
    int unused_size;
    int *ptr;
};
void createarray(struct myArray *a, int tsize, int usize){
    (*a).total_size=tsize;
    (*a).unused_size=usize;
    (*a).ptr=(int*)malloc(tsize*sizeof(int));
}
void setvalue(struct myArray *a){
    for(int i=0;i<(*a).unused_size;i++){
        scanf("%d",&(*a).ptr[i]);
    }
}
void showevalue(struct myArray *a){
    for(int i=0;i<(*a).unused_size;i++){
        printf("The element at %d index is: %d",i,(*a).ptr[i]);
    }
}
int main(){
    struct myArray marks;
    createarray(&marks,10,2);
    printf("Setting the value of all the indexs \n");
    setvalue(&marks);
    printf("Showcasing the setvalues \n");
    showevalue(&marks);
    return 0;
}