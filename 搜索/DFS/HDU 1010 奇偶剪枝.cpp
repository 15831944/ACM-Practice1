#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
char map[10][10];
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
bool visit[10][10];
int n,m,T,x2,y2;
bool judge(int x,int y){
    if(x>=1&&x<=n&&y>=1&&y<=m){
        if((map[x][y]=='.'||map[x][y]=='D')&&!visit[x][y])
            return true;
        return false;
    }
    return false;
}
int dfs(int x,int y,int t){
    int min_s=abs(x-x2)+abs(y-y2);
    //奇偶剪枝 无论是走，我们的步数肯定比最短路径数多一个偶数 输入的步数比最短路径数多得是一个奇数，那么我们永远也不可能走到
    if(min_s<=T-t){
        if((T-t-min_s)&1)
            return 0;
    }
    else
        return 0;
    if(t==T&&map[x][y]=='D')
        return 1;
    if(t>T) return 0;
    int xx,yy;
    for(int i=0;i<4;i++){
        xx=x+dir[i][0];
        yy=y+dir[i][1];
        if(judge(xx,yy)){
            visit[xx][yy]=true;
            if(dfs(xx,yy,t+1))
                return 1;
            visit[xx][yy]=false;
        }
    }
    return 0;
}
int main(){
    int x1,y1,min_s;
    while(scanf("%d%d%d",&n,&m,&T)&&n||m||T){
        memset(visit,false,sizeof(visit));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf(" %c",&map[i][j]);
                if(map[i][j]=='S'){
                    x1=i,y1=j;
                    map[x1][y1]='.';
                    visit[x1][y1]=true;
                }
                if(map[i][j]=='D')
                    x2=i,y2=j;
            }
        }
        if(dfs(x1,y1,0))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
