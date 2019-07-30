#include<cstdio>
#include<cstring>
bool visit[28][28];
int dir[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
int p,q,a[28],b[28];

bool judge(int x,int y){
    if(x>=1&&x<=p&&y>=1&&y<=q&&!visit[x][y])
        return true;
    return false;
}

bool dfs(int x,int y,int sum){
    if(sum==p*q)
        return true;
    int xx,yy;
    for(int i=0;i<8;i++){
        xx=x+dir[i][0];
        yy=y+dir[i][1];
        if(judge(xx,yy)){
            a[sum]=xx,b[sum]=yy;//这里用个数组专门记录路径，不能按照visit的标记去输出路径因为那不一定是真实的路径
            visit[xx][yy]=true;
            if(dfs(xx,yy,sum+1))
                return true;
            visit[xx][yy]=false;
        }
    }
    return false;
}
int main(){
    int n,k=1;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&q,&p);//这里p、q得逆置才行,不知什么原因
        memset(visit,false,sizeof(visit));
        visit[1][1]=true;
        a[0]=1,b[0]=1;
        printf("Scenario #%d:\n",k);
        if(dfs(1,1,1)){
            for(int i=0;i<p*q;i++)
                printf("%c%d",a[i]+64,b[i]);
        }
        else
            printf("impossible");
        printf("\n");
        if(n!=0)
            printf("\n");
        k++;
    }
    return 0;
}
