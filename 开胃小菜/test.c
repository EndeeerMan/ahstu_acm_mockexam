#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int row = 0;

void swap(char *a,char *b){
    char temp = *b;
    *b = *a;
    *a = temp;
}
void judge(char result[10],int cir_i,int fst){
    if (result[fst] == '\0') return;
    int flag = fst;
    char temp = '\0';
    for(int j=fst;j<=9;j++){
        if(result[j] == '\0') break;
        if(temp <= result[j]){
            temp = result[j];
            flag = j;
        }
    }
    if(result[fst] < result[flag]){
        swap(&result[fst],&result[flag]);
        return;
    }else{
        judge(result,cir_i,fst+1);
    }
}

void modify(int fst,int cir_i,char result[][10]){
    for(;row<=cir_i-1;row++){
        fst = 0;
        judge(result[row],cir_i,fst);
    }
}

int main(){
    int cir_i = 0;
    scanf("%d",&cir_i);
    char result[cir_i][10];
    for(int i=0;i<=cir_i-1;i++){
        char buf[10];
        scanf("%s",buf);
        strcpy(result[i],buf);
    }
    modify(0,cir_i,result);
    for(int i=0;i<=cir_i-1;i++){
        printf("%s\n",result[i]);
    }
}