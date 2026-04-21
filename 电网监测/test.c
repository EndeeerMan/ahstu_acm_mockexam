#include <stdlib.h>
#include <stdio.h>

long long arr[100001];
long long tree[100001];

long long lowbit(long long x){
    return x & -x;
}

void add_tree(long long x,long long k,long long n){
    while(x<=n){
        tree[x] += k;
        x += lowbit(x);
    }
}

long long sum_tree(long long x,long long y){
    long long ans1 = 0;
    long long ans2 = 0;
    x -= 1;
    while(x>0){
        ans1 += tree[x];
        x -= lowbit(x);
    }
    while(y>0){
        ans2 += tree[y];
        y -= lowbit(y);
    }
    return ans2 - ans1;
}

int main(){
    long long n,q;
    scanf("%lld %lld",&n,&q);

    arr[0] = 0;
    tree[0] = 0;

    for(int i=1;i<=n;i++){
        scanf("%lld",&arr[i]);
        add_tree(i,arr[i],n);
    }

    long long x,y,z;
    long long sum;

    for(int i=1;i<=q;i++){
        scanf("%lld %lld %lld",&x,&y,&z);
        if(x == 1){
            add_tree(y,z-arr[y],n);
            arr[y] = z;
        }else if(x == 2){
            sum = sum_tree(y,z);
            if(sum%3 != 0){
                printf("NO\n%lld\n",3-(sum%3));
            }else{
                printf("YES\n%lld\n",sum);
            }
        }else exit(1);
    }
}