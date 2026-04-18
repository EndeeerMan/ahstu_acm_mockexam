#include <stdio.h>

char target[6] = "AHSTU";

int judge(int len,char str[]){
    if((len-5)%2) return 0;
    int counter = 0;
    char buf = '\0';
    int j = 0;
    for(int i=0;i<=4;i++){
        buf = target[i];
        for(;j<=len-1;j++){
            if(buf == str[j]){
                counter++;
                j++;
                break;
            }
        }
    }
    return (counter >= 5);
}

int main(){
    int cir_i;
    scanf("%d",&cir_i);
    int i = cir_i;
    int result[cir_i];
    while(cir_i--){
        int n;
        scanf("%d",&n);
        char str[n+1];
        scanf("%s",str);
        if(judge(n,str)){
            result[cir_i] = 1;
        }else{
            result[cir_i] = 0;
        }
    }
    for(i-=1;i>=0;i--){
        if(result[i] == 1) printf("YES\n");
        else printf("NO\n");
    }
}