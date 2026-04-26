#include <stdio.h>

long long arr[200005];


int main(){
    long long n;
    scanf("%lld",&n);

    long long primary_xor_sum = 0;

    scanf("%lld",&arr[0]);
    if(n >= 2){
        scanf("%lld",&arr[1]);
        primary_xor_sum = arr[0] ^ arr[1];
    }
    if(n > 2){
        for(long long i=2;i<=n-1;i++){
            scanf("%lld",&arr[i]);
            primary_xor_sum ^= arr[i];
        }
    }

    long long modified_xor_sum = primary_xor_sum;
    long long best_xor_sum = primary_xor_sum;

    for(long long i=0;i<=n-1;i++){
        for(long long j=1;j<=n/(i+1);j++){
            modified_xor_sum = primary_xor_sum ^ arr[i] ^ (arr[i]+j);
            if(modified_xor_sum > best_xor_sum){
                best_xor_sum = modified_xor_sum;
            }
            modified_xor_sum = primary_xor_sum ^ arr[i] ^ (arr[i]*j);
            if(modified_xor_sum > best_xor_sum){
                best_xor_sum = modified_xor_sum;
            }
        }
    }
    printf("%lld",best_xor_sum);
}
