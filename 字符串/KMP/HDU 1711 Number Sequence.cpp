#include<cstdio>
int n,m,b[10010],a[1000010],next[10010];
void getNext(){
    int i=0,j=-1;
    next[0]=-1;
    while(i<m){
        if(j==-1||b[i]==b[j]){
            i++;
            j++;
            next[i]=j;
        }
        else{
            j=next[j];
        }
    }
}

int kmp(){
    int i=0,j=0;
    while(i<n&&j<m){
        if(j==-1||a[i]==b[j]){
            i++;
            j++;
        }
        else
            j=next[j];
    }
    if(j==m)
        return i-m+1;
    else
        return -1;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        for(int i=0;i<m;i++)
            scanf("%d",b+i);
        getNext();
        printf("%d\n",kmp());
    }
    return 0;
}
