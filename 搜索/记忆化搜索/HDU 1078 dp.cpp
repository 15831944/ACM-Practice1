#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int map[105][105],k,n;
int dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
int dp[105][105];
bool check(int x,int y){
    if(x<0||x>n-1||y<0||y>n-1)
        return false;
    return true;
}
//记忆化搜索决定已经搜索过的路径没必要重复搜索，剪枝对搜索的路径做出决策，不好的搜索路径应舍弃
int dfs(int x,int y){
    if(dp[x][y])//因为是记忆化搜索，如果dp[x][y]不为0代表从这点开始所枚举的路径是被搜索过得，不要去重复搜索，那就直接用之前所搜索的值就好
        return dp[x][y];
    int xx,yy,res=0;
    for(int i=1;i<=k;i++){//枚举每次所走的步长
        for(int j=0;j<4;j++){//枚举方向
            xx=x+dir[j][0]*i;
            yy=y+dir[j][1]*i;
            if(check(xx,yy)&&map[xx][yy]>map[x][y]){
                res=max(dfs(xx,yy),res);//类似dp中的状态转移方程，取max的决策方案
            }
        }
    }
    dp[x][y]=res+map[x][y];
    return dp[x][y];
}
int main(){
    while(scanf("%d%d",&n,&k)&&n!=-1&&k!=-1){
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&map[i][j]);
        printf("%d\n",dfs(0,0));
    }
    return 0;
}
