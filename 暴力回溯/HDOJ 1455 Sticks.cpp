#include<cstdio>
#include<algorithm>
#include<functional>
#include<cstring>
using namespace std;
int a[70],n,num,stdlen;//stdlen代表木棍原始长度
bool visit[70];
bool DFS(int curlen,int curpos,int step){//curlen代表现在多跟枝干构成的长度,curpos代表要从哪里开始枚举,step代表现在已经达到标准长度的木棍的 个数
    if (step == num){
        printf("%d\n", stdlen);
        return true;
    }
    else{
        for (int i = curpos; i <n; i++){//从大到小排序后，按顺序搜索
            if (visit[i]) continue;
            visit[i] = true;
            if (curlen + a[i] < stdlen){
                if(DFS(curlen + a[i],curpos+1 , step)) return true;
            }
            else if ( curlen + a[i] == stdlen){//当拼完一根后，继续拼下一根
                if (DFS(0, 0, step + 1)) return true;
            }
            visit[i] = false;
            if (curlen == 0) break;//如果第一根时失败  剪枝
            while (a[i] == a[i + 1]) i++;//如果下一根长度跟当前的失败的长度一样，剪枝
        }
    }
    return false;
}
int main(){
    int sum;
    bool flag;
    while (scanf("%d", &n),n){
        sum = 0;
        memset(visit, false, sizeof(visit));
        for (int i = 0; i < n; i++){
            scanf("%d", a + i);
            sum += a[i];
        }
        sort(a, a + n, greater<int>());
        for (int i = a[0]; i <= sum;i++)//最坏的情形是这些木棍原本都是一根大木棍上剪下来的
        if (sum%i == 0){
            stdlen = i;
            num = sum / stdlen;
            flag=DFS(0, 0, 0);
            if (flag) break;
        }
    }
    return 0;
}
