#include<cstdio>
#include<cstring>
#define maxn 100002
struct node{
    int to;
    int next;
}edge[maxn<<2];
int head[maxn],n,d,index,sum;
bool visit[maxn];

void add_edge(int from,int to){
    edge[index].to=to;
    edge[index].next=head[from];
    head[from]=index;
    index++;
}
void dfs(int pos,int d0){
    if(d0>d)
        sum++;
    for(int i=head[pos];i!=-1;i=edge[i].next){
        if(!visit[edge[i].to]){
            visit[edge[i].to]=true;
            dfs(edge[i].to,d0+1);
        }
    }
}
int main(){
    int T,a,b;
    scanf("%d",&T);
    while(T--){
        memset(head,-1,sizeof(head));
        memset(visit,false,sizeof(visit));
        scanf("%d%d",&n,&d);
        n--;
        index=0;
        while(n--){
            scanf("%d%d",&a,&b);
            add_edge(a,b);
            add_edge(b,a);
        }
        sum=0;
        visit[0]=true;
        dfs(0,0);
        printf("%d\n",sum);
    }
    return 0;
}
