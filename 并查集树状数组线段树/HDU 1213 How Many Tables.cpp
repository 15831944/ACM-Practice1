#include<cstdio>
int student[1010];

void init(int n){
    for(int i=1;i<=n;i++){
        student[i]=i;
    }
}

int find(int x){
    int tmp=x;
    while(student[x]!=x){
        x=student[x];
    }
    while(student[tmp]!=x){
        student[tmp]=x;
        tmp=student[tmp];
    }
    return x;
}

void union0(int x,int y){
    int v=find(x);
    int w=find(y);
    if(v!=w)
        student[v]=w;
}
int main(){
    int T,n,m,x,y,ans,num;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        init(n);
        ans=0;
        while(m--){
            scanf("%d%d",&x,&y);
            union0(x,y);
        }
        for(int i=1;i<=n;i++){
            if(student[i]==i)//判断有几个独立的联通集
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
