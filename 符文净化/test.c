#include <stdio.h>

int main(){
    int size = 0;
    int buf = getchar();
    while(buf != -1 && buf != '\0' && buf != '\n'){
        if(buf == '6') size++;
        buf = getchar();
    }
    for(int i=1;i<=size;i++){
        putchar('6');
    }
}