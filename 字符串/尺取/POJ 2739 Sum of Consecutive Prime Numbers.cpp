#include<cstdio>
using namespace std;
int prime[10010];
bool flag[10010];
void prim(){
    for(int i=2;i<5005;i++){
        for(int j=i*2;j<10010;j+=i)
            flag[j]=true;
    }
    for(int i=2,j=0;i<10010;i++){
        if(!flag[i]){
            prime[j++]=i;
        }
    }
}
int main(){
    int n,l,r,sum,ans;
    prim();
    while(scanf("%d",&n)&&n){
        l=r=ans=sum=0;
        while(1){
            if(sum>=n)
                sum-=prime[l++];
            else{
                    if(prime[r]<=n)
                        sum+=prime[r++];
                    else
                        break;
            }
            if(sum==n) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
