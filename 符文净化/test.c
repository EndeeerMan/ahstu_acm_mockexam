#include <stdio.h>

char str[10005];

int main(){
    scanf("%s",str);

    int i = 0;
    int temp = str[i++] - '0';

    while(temp >= 0 && temp <= 9){
        if(temp == 6){
            printf("6");
        }
        temp = str[i++] - '0';
    }
}
