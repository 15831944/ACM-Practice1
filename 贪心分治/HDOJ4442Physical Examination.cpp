#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100001
const long long mod  =365 * 24 * 60 * 60;
struct sub{
    int a, b;
    double x;
    friend bool operator<(sub A,sub B){
        return A.x < B.x;
    }
}a[N];
int main(){
    int n,sum;
    while (scanf("%d", &n), n){
        for (int i = 0; i < n; i++){
            scanf("%d%d", &a[i].a, &a[i].b);
            a[i].x = (1.0)*a[i].a / a[i].b;
        }
        sort(a, a + n);
        long long sum = 0;
        for (int i = 0; i < n; i++)
            sum =(sum+ a[i].a + a[i].b*sum)%mod;
        printf("%lld\n", sum);
    }
    return 0;
}
