#include <stdio.h>

const char key[6] = "AHSTU";

char str[200005];

int judge(long long n){
    if (n % 2 == 0) return 0;
    int key_ptr = 0;

    int counts[26] = {0};
    for (int i = 0; i < n; i++) {
        counts[str[i] - 'A']++;
    }

    // 3. 频率限制检查
    for (int i = 0; i < 26; i++) {
        int target_cnt = 0;
        // 检查当前字母是否在 "AHSTU" 中
        if (i == 'A'-'A' || i == 'H'-'A' || i == 'S'-'A' || i == 'T'-'A' || i == 'U'-'A') {
            target_cnt = 1;
        }
        
        // 如果某种字符多出的数量超过了可配对消除的上限
        if (2 * (counts[i] - target_cnt) > (n - 5)) {       //某个字母数量不得多于总删除量的一半！
            return 0;
        }
    }

    for(int i=0;i<=n-1;i++){
        if(str[i] == key[key_ptr]){
            key_ptr += 1;
            if(key_ptr == 5) return 1;
        }
    }
    return 0;
}
int main(){
    long long T;
    scanf("%lld",&T);

    long long n;

    for(long long i=1;i<=T;i++){
        scanf("%lld",&n);
        scanf("%s",str);
        if(judge(n)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}
