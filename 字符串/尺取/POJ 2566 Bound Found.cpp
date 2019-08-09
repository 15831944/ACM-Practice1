#include<cstdio>//我这段 代码有问题
#include<cmath>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
pair<int,int> pp[100005];
int main(){
    int n,k,t;
    int left,right,res,ans,sum;
    while(scanf("%d%d",&n,&k)&&n+k){
        for(int i=0;i<n;i++){
            scanf("%d",&pp[i].first);
            pp[i].first+=pp[i-1].first;
            pp[i].second=i;
        }
        sort(pp,pp+n);
        while(k--){
            scanf("%d",&t);
            left=0,right=0,res,ans=INF,sum=0;
            while(right<n){
                res=pp[right].first-pp[left].first;
                if(abs(res-t)<ans){
                    ans=abs(res-t);
                    sum=res;
                    left=pp[left].second;
                    right=pp[right].second;
                }
                if(res>t)
                    left++;
                else if(res<t)
                    right++;
                else
                    break;
                if(left==right)
                    right++;
            }
            if(left>right)
                swap(left,right);
            printf("%d %d %d\n",sum,left,right-1);
        }
    }
    return 0;
}
/*#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 0x3f3f3f3f
#define LL long long
#define MAX 100010
using namespace std;

typedef pair<LL, int> p;
LL a[MAX], t, ans, tmp, b;
int n, k, l, u, st, en;
p sum[MAX];

LL myabs(LL x)
{
    return x>=0? x:-x;
}

int main()
{
    while (scanf("%d %d", &n, &k), n+k){
        sum[0] = p(0, 0);
        for (int i = 1; i <= n; i++){
            scanf("%I64d", a+i);
            sum[i] = p(sum[i-1].first+a[i], i);
        }
        sort(sum, sum+1+n);
        while (k--){
            scanf("%I64d", &t);
            tmp = INF; st = 0, en = 1;
            while(en <= n){
                b = sum[en].first-sum[st].first;
                if(myabs(t-b) < tmp){
                    tmp = myabs(t-b);
                    ans = b;
                    l = sum[st].second; u = sum[en].second;
                }
                if(b > t) st++;
                else if(b < t) en++;
                else break;
                if(st == en) en++;
            }
            if (u < l) swap(u, l);
            printf("%I64d %d %d\n", ans, l+1, u);
        }
    }
    return 0;
}*/
