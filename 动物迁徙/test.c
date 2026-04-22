#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int grid[501][501];
int belong[501][501];
long long animal[501][501];

int qx[250005],qy[250005];

int block_id = 0;

int direct_x[4] = {-1,1,0,0};
int direct_y[4] = {0,0,-1,1};

void split_partion(int x,int y,int id,int n,int m){
    int head = 0, tail = 0;
    qx[tail] = x , qy[tail] = y , tail++;
    belong[x][y] = id;
    while(head < tail){
        int cx = qx[head], cy = qy[head];       //初始化之前扫描到的位置
        head++;                 //移动头指针，作为下次扫描的起点
        for(int i=0;i<=3;i++){      //按方向direct数组扫描周围区域
            int nx = cx + direct_x[i] , ny = cy + direct_y[i];
            if(grid[nx][ny] == 1 && belong[nx][ny] == 0 && nx >= 0 && ny >= 0 && nx <= n-1 && ny <= m-1){ //检查是否是空位，是否被标记，是否越界
                belong[nx][ny] = id;
                qx[tail] = nx, qy[tail] = ny, tail++;
            }
        }
    }
}

void clean_all_mem(){       //归零所有数组
    memset(qx,0,sizeof(qx));
    memset(qy,0,sizeof(qy));

    for(int i=0;i<=500;i++){
        memset(grid[i],0,sizeof(grid[i]));
        memset(belong[i],0,sizeof(belong[i]));
        memset(animal[i],0,sizeof(animal[i]));
    }
}

int main(){
    clean_all_mem();

    long long n,m,k;
    scanf("%lld %lld %lld",&n,&m,&k);

    for(long long i=0;i<=n-1;i++){        //记录空地与障碍物
        for(long long j=0;j<=m-1;j++){
            scanf("%lld",&grid[i][j]);
        }
    }

    for(long long i=0;i<=n-1;i++){        //计算区块并分块
        for(long long j=0;j<=m-1;j++){
            if(grid[i][j] == 1 && belong[i][j] == 0){
                block_id += 1;
                split_partion(i,j,block_id,n,m);
            }
        }
    }

    long long x,y;

    for(long long i=1;i<=k;i++){      //记录动物坐标
        scanf("%lld %lld",&x,&y);
        animal[x][y]++;
    }

    long long mount_of_each_blocks[block_id + 1];

    memset(mount_of_each_blocks,0,sizeof(mount_of_each_blocks));

    for(long long i=0;i<=n-1;i++){        //记录空地与障碍物
        for(long long j=0;j<=m-1;j++){
            if(animal[i][j] != 0 && grid[i][j] != 0){
                mount_of_each_blocks[belong[i][j]] += animal[i][j];
            }
        }
    }

    long long sum = 0;

    for(long long i=1;i<=block_id;i++){
        sum += mount_of_each_blocks[i] * mount_of_each_blocks[i];
    }
    
    printf("%lld",sum);
}