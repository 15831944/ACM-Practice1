#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define maxn 100001
vector<int> edge[maxn];
int n,d,sum;
bool visit[maxn];
void dfs(int pos,int d0){
    if(d0>d)
        return;
        //sum++;//这里是直接的思路只考虑距离大于d的点
    for(int i=0;i<edge[pos].size();i++){
        if(!visit[edge[pos][i]]){
            visit[edge[pos][i]]=true;
            sum++;//这里是只考虑距离小于d的点,最为做减法
            dfs(edge[pos][i],d0+1);
            //这里没有必要再修改visit为false因为是深度搜索树 连通无回路,所以不会再回到那个已标记的点
        }
    }
}
int main(){
    int T,a,b;
    scanf("%d",&T);
    while(T--){
        memset(visit,false,sizeof(visit));
        for(int i=0;i<maxn;i++)
            edge[i].clear();
        scanf("%d%d",&n,&d);
        for(int i=0;i<n-1;i++){
            scanf("%d%d",&a,&b);
            edge[a].push_back(b);//这里到底有没有必要把一条边再反向建一遍取决于输入序列 eg: 1->2 3->2 如果是这样的序列是不是dfs的时候边级vector就会漏掉一些边(如果一开始起点是1开始可能搜索到2后，就无法搜索到3这个点),不过这题的输入序列好像不会 有这种情况,都是 1->2 2->3 3->4这种的
            edge[b].push_back(a);//不过为了稳健一点建议还是都把它作为无向图对待
        }
        sum=1;
        visit[0]=true;
        dfs(0,1);
        printf("%d\n",n-sum);
    }
    return 0;
}
