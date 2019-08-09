#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#define INF 0x3f3f3f3f
#define LL long long
using namespace std;
typedef pair<LL, pair<LL, LL> > p;
p ans[1010];

int main()
{
    LL n, st, en, sum;
    while (~scanf("%I64d", &n)){
        st = 1, en = 1, sum = 0;
        int k = 0;
        while (1){
            if (sum == n) ans[k++] = p(en-st, pair<LL, LL>(st, en-1));
            if (sum >= n) sum -= st*st, st++;
            else{
                if (en*en <= n) sum += en*en, en++;
                else break;
            }
        }
        printf("%d\n", k);
        for (int i = 0; i < k; i++){
            printf("%I64d ", ans[i].first);
            for (int j = ans[i].second.first; j <= ans[i].second.second; j++) printf("%I64d ", j);
            puts("");
        }
    }
    return 0;
}
