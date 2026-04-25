#include <stdio.h>
#include <stdlib.h>

int battle[10][2];
int members[10];

int m,n;

int best_rank = 10;

int calc_rank(){
    int rank = 1;
    for(int i=0;i<=n-1;i++){
        if(members[i] > members[0]){
            rank += 1;
        }
    }
    return rank;
}

void dfs(int index){
    if(index == m){
        int current_rank = calc_rank();
        if(current_rank <= best_rank){
            best_rank = current_rank;
        }
        return;
    }

    int you = battle[index][0] - 1;
    int rival = battle[index][1] - 1;

    if(you == 0 || rival == 0){
        members[0] += 4;
        dfs(index + 1);
        members[0] -= 4;    //回溯，否则会改变数组。
    }else{

        members[you] += 4;      //you胜利
        dfs(index + 1);
        members[you] -= 4;

        members[rival] += 4;    //rival胜利
        dfs(index + 1);
        members[rival] -= 4;

        members[you] += 2;      //平局
        members[rival] += 2;
        dfs(index + 1);
        members[you] -= 2;
        members[rival] -= 2;
    }
}

int main(){
    scanf("%d %d",&n,&m);

    for(int i=0;i<=n-1;i++){
        scanf("%d",&members[i]);
    }

    for(int i=0;i<=m-1;i++){  //循环n次，读入对战双方。
        scanf("%d %d",&battle[i][0],&battle[i][1]);
    }

    dfs(0);

    printf("%d",best_rank);
}