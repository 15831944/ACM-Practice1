#include<cstdio>
#include<queue>
using namespace std;
__int64 sum;
int main(){
    int n,tmp,a,b;
    while(scanf("%d",&n)!=EOF){
        priority_queue<int,vector<int>,greater<int> > Q;//½¨Á¢Ð¡¶¥¶Ñ
        while(n--){
            scanf("%d",&tmp);
            Q.push(tmp);
        }
        sum=0;
        if(n==1){
            sum=tmp;
        }
        while(Q.size()>1){
            a=Q.top();
            Q.pop();
            b=Q.top();
            Q.pop();
            sum+=(a+b);
            Q.push(a+b);
        }
        Q.pop();
        printf("%I64d\n",sum);
    }
    return 0;
}
