#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long arr[200005];

int main(){
    memset(arr,0,sizeof(arr));
    
    long long n;
    scanf("%lld",&n);
    
    long long xor_sum;
    
    for(long long i=1;i<=n;i++){
        scanf("%lld",&arr[i]);
        if(i==2){
            xor_sum = arr[1] ^ arr[2];
        }else if(i>2){
            xor_sum ^= arr[i];
        }
    }

    long long xor_max_temp = xor_sum;
    long long xor_max = xor_sum;

    for(long long i=1;i<=n;i++){
        long long j = n/i;
        for(long long x=1;x<=j;x++){
            xor_max_temp = xor_sum ^ arr[i] ^ (arr[i] + x);
            if(xor_max_temp > xor_max){
                xor_max = xor_max_temp;
            }
            xor_max_temp = xor_sum ^ arr[i] ^ (arr[i] * x);
            if(xor_max_temp > xor_max){
                xor_max = xor_max_temp;
            }
        }
    }
    printf("%lld\n",xor_max);
}