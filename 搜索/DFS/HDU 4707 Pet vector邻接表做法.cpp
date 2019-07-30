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
        //sum++;//������ֱ�ӵ�˼·ֻ���Ǿ������d�ĵ�
    for(int i=0;i<edge[pos].size();i++){
        if(!visit[edge[pos][i]]){
            visit[edge[pos][i]]=true;
            sum++;//������ֻ���Ǿ���С��d�ĵ�,��Ϊ������
            dfs(edge[pos][i],d0+1);
            //����û�б�Ҫ���޸�visitΪfalse��Ϊ����������� ��ͨ�޻�·,���Բ����ٻص��Ǹ��ѱ�ǵĵ�
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
            edge[a].push_back(b);//���ﵽ����û�б�Ҫ��һ�����ٷ���һ��ȡ������������ eg: 1->2 3->2 ����������������ǲ���dfs��ʱ��߼�vector�ͻ�©��һЩ��(���һ��ʼ�����1��ʼ����������2�󣬾��޷�������3�����),����������������к��񲻻� ���������,���� 1->2 2->3 3->4���ֵ�
            edge[b].push_back(a);//����Ϊ���Ƚ�һ�㽨�黹�Ƕ�������Ϊ����ͼ�Դ�
        }
        sum=1;
        visit[0]=true;
        dfs(0,1);
        printf("%d\n",n-sum);
    }
    return 0;
}
