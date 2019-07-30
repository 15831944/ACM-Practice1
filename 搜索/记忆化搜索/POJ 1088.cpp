#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int map[105][105],k,n,m;
int dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
int dp[105][105];
bool check(int x,int y){
    if(x<0||x>n-1||y<0||y>m-1)
        return false;
    return true;
}
//记忆化搜索决定已经搜索过的路径没必要重复搜索，剪枝对搜索的路径做出决策，不好的搜索路径应舍弃
int dfs(int x,int y){
    if(dp[x][y])//因为是记忆化搜索，如果dp[x][y]不为0代表从这点开始所枚举的路径是被搜索过得，不要去重复搜索，那就直接用之前所搜索的值就好
        return dp[x][y];
    int xx,yy,res=0;
    for(int j=0;j<4;j++){//枚举方向
        xx=x+dir[j][0];
        yy=y+dir[j][1];
        if(check(xx,yy)&&map[xx][yy]<map[x][y]){
            res=max(dfs(xx,yy),res);//类似dp中的状态转移方程，取max的决策方案
        }
    }
    dp[x][y]=res+1;//因为求解的是滑坡的最大长度
    return dp[x][y];
}
int main(){
    int res=0;
    memset(dp,0,sizeof(dp));
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&map[i][j]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            res=max(res,dfs(i,j));
        printf("%d\n",res);
    return 0;
}
