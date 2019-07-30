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
//���仯���������Ѿ���������·��û��Ҫ�ظ���������֦��������·���������ߣ����õ�����·��Ӧ����
int dfs(int x,int y){
    if(dp[x][y])//��Ϊ�Ǽ��仯���������dp[x][y]��Ϊ0�������㿪ʼ��ö�ٵ�·���Ǳ��������ã���Ҫȥ�ظ��������Ǿ�ֱ����֮ǰ��������ֵ�ͺ�
        return dp[x][y];
    int xx,yy,res=0;
    for(int i=1;i<=k;i++){//ö��ÿ�����ߵĲ���
        for(int j=0;j<4;j++){//ö�ٷ���
            xx=x+dir[j][0]*i;
            yy=y+dir[j][1]*i;
            if(check(xx,yy)&&map[xx][yy]>map[x][y]){
                res=max(dfs(xx,yy),res);//����dp�е�״̬ת�Ʒ��̣�ȡmax�ľ��߷���
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
