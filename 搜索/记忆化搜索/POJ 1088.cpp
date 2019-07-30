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
//���仯���������Ѿ���������·��û��Ҫ�ظ���������֦��������·���������ߣ����õ�����·��Ӧ����
int dfs(int x,int y){
    if(dp[x][y])//��Ϊ�Ǽ��仯���������dp[x][y]��Ϊ0�������㿪ʼ��ö�ٵ�·���Ǳ��������ã���Ҫȥ�ظ��������Ǿ�ֱ����֮ǰ��������ֵ�ͺ�
        return dp[x][y];
    int xx,yy,res=0;
    for(int j=0;j<4;j++){//ö�ٷ���
        xx=x+dir[j][0];
        yy=y+dir[j][1];
        if(check(xx,yy)&&map[xx][yy]<map[x][y]){
            res=max(dfs(xx,yy),res);//����dp�е�״̬ת�Ʒ��̣�ȡmax�ľ��߷���
        }
    }
    dp[x][y]=res+1;//��Ϊ�����ǻ��µ���󳤶�
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
