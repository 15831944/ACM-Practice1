#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int num[210],n;
struct node{
    int floor, step;
    bool operator <(const node &p)const{
        return step>p.step;
    }
};
int BFS(int a,int b){
    priority_queue<node> Q;
    node v,x;
    static bool visit[210];
    memset(visit, false, sizeof(visit));
    v.floor = a, v.step = 0;
    visit[a] == true;
    Q.push(v);
    while (!Q.empty()){
        v = Q.top();
        Q.pop();
        if (v.floor == b) return v.step;
        x.floor =v.floor+num[v.floor];
        if (!visit[x.floor] && x.floor <= n){
            x.step =v.step+ 1;
            visit[x.floor] = true;
            Q.push(x);
        }
        x.floor = v.floor - num[v.floor];
        if (!visit[x.floor] && x.floor >= 1){
            x.step = v.step + 1;
            visit[x.floor]=true;
            Q.push(x);
        }
    }
    return -1;
}
int main(){
    int  a, b;
    while (scanf("%d", &n), n){
        scanf("%d%d", &a, &b);
        for (int i = 1; i <= n; i++)
            scanf("%d", num + i);
        printf("%d\n", BFS(a, b));
    }
    return 0;
}

