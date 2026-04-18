#include <stdio.h>

void trans(char arr[],int n){
    for(int i=0;i<=n-1;i++){
        arr[i] -= '0';
    }
}

int main(){
    int n;
    scanf("%d",&n);
    char arr[n+1];
    scanf("%s",arr);
    trans(arr,n);
    int a=0,b=0;
    for(int i=0;i<=n-2;i+=2){
        a += arr[i];
        b += arr[i+1];
    }
    if(a == b) printf("YES");
    else printf("NO");
}