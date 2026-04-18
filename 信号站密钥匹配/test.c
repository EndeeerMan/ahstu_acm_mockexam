#include <stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int gcd(int a,int b){
    if(a<b) swap(&a,&b);

    int temp = a%b;
    if(temp == 0){
        return b;
    }

    return gcd(b,temp);
}

int main(){
    int n=1;
    scanf("%d",&n);
    int last_vol[1000];

    for(int i=0;i<=1000-1;i++){
        last_vol[i] = -1;
    }
    int num;
    for(int i=0;i<=n-1;i++){
        scanf("%d",&num);
        last_vol[num-1] = i+1;
    }

    int count = -1;
    for(int i=0;i<=1000-1;i++){
        for(int j=i;j<=1000-1;j++){
            if(gcd(i+1,j+1) == 1){    
                if(count <= last_vol[i] + last_vol[j] && last_vol[i] != -1 && last_vol[j] != -1) count = last_vol[i] + last_vol[j];
            }
        }
    }

    printf("%d",count);
}