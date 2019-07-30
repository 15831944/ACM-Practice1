#include<cstdio>
#include<cstring>
#define INF 0x3FFFFFFF
int map[210][210];
bool flag[210];
int cost[210],a[210];

void Dijkstra(int n,int a){
    memset(flag,false,sizeof(flag));
    for(int i=1;i<=n;i++){
        if(i!=a)
            cost[i]=map[a][i];
    }
    flag[a]=true;
    for(int m=1;m<n;m++){
    int tmp=INF,j;
    for(int i=1;i<=n;i++){
        if(!flag[i]){
            if(cost[i]<tmp){
                tmp=cost[i];
                j=i;
            }
        }
    }
        int min_num=j;
        flag[min_num]=true;
        for(int k=1;k<=n;k++){
            if(!flag[k]){
                if(cost[min_num]+map[min_num][k]<cost[k]){
                    cost[k]=cost[min_num]+map[min_num][k];
                }
            }
        }
    }
}

int main(){
    int N,A,B;
    while(scanf("%d",&N),N){
    for(int i=1;i<=210;i++)
        for(int j=1;j<=210;j++)
            map[i][j]=INF;
    scanf("%d%d",&A,&B);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            map[i][j]=INF;
        for(int i=1;i<=N;i++){
        scanf("%d",a+i);
        if(i+a[i]<=N)
            map[i][i+a[i]]=1;
        if(i-a[i]>=1)
            map[i][i-a[i]]=1;
    }
    Dijkstra(N,A);
    if(cost[B]!=INF)
        printf("%d\n",cost[B]);
    else
        printf("-1\n");
    }
    return 0;
}
