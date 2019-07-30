#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
int a[100001];
int main(){
    int k,n,s,sum,l,r,num,len,total;
    scanf("%d",&k);
    while(k--){
        scanf("%d%d",&n,&s);
        total=0;
        for(int i=0;i<n;i++){
            scanf("%d",a+i);
            total+=a[i];
        }
        if(total<s){
            printf("0\n");
            continue;
        }
        sum=0,l=0,r=0,num=INF,len=0;
        while(r<n){
            while(r<n&&sum<s){
                sum+=a[r++];
            }
            while(sum>=s){
                sum-=a[l++];
            }
            num=min(num,r-l+1);
        }
        printf("%d\n",num);
    }
    return 0;
}
