#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 10005
#define maxm 50005
struct node{
    int to,next;
}edge[maxm];
int head[maxn];
int visit[maxn];
int employee[maxn],index;

void add_edge(int from,int to){
    edge[index].to=to;
    edge[index].next=head[from];
    head[from]=index;
    index++;
}

int dfs(int pos){
    if(head[pos]==-1)
        return employee[pos]=888;
    int tmp,res;
    for(int i=head[pos];i!=-1;i=edge[i].next){
        tmp=edge[i].to;
        if(visit[tmp]==-1) return -1;
        if(!visit[tmp]){
            visit[tmp]=-1;
            if((res=dfs(tmp))==-1) return -1;
            employee[pos]=max(employee[pos],res+1000);
            visit[tmp]=1;
        }
    }
    return employee[pos];
}

int main(){
    int k,n,m,a,b,sum,res;
    scanf("%d",&k);
    while(k--){
        memset(visit,0,sizeof(visit));
        memset(employee,-1,sizeof(employee));
        memset(head,-1,sizeof(head));
        sum=0,index=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            add_edge(a,b);
        }
        for(int i=1;i<=n;i++){
            if(!visit[i]){
                res=dfs(i);
                if(res==-1) break;
            }
        }
        if(res==-1){
            printf("%d\n",n*888);
            printf("888");
            for(int i=2;i<=n;i++)
                printf(" 888");
        }
        else{
            for(int i=1;i<=n;i++)
                sum+=employee[i];
            printf("%d\n",sum);
            printf("%d",employee[1]);
            for(int i=2;i<=n;i++)
                printf(" %d",employee[i]);
        }
        putchar('\n');
    }
    return 0;
}
