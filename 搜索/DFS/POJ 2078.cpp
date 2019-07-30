#include<cstdio>
#define INF1 -0x3f3f3f3f
#define INF2 0x3f3f3f3f
int map[8][8];
int min_sum,n;
void shift(int row){
    int tmp=map[row][n];
    for(int i=n;i>=2;i--)
        map[row][i]=map[row][i-1];
    map[row][1]=tmp;
}

void dfs(int row){
    if(row>n) return;
    int sum,max_sum=INF1;
    bool flag=true;
    for(int i=1;i<=n;i++){
        shift(row);
        for(int i=1;i<=n;i++){
            sum=0;
            for(int j=1;j<=n;j++){
                sum+=map[j][i];
            }
            if(sum>min_sum){//剪枝 如果某一列的值都比之前的min_sum大 就没有必要去计算其余列了，因为max_sum只会取这些列中最大的
                flag=false;
                break;
            }
            max_sum=(sum>max_sum?sum:max_sum);
        }
        if(flag)
            min_sum=(max_sum<min_sum?max_sum:min_sum);
        else
            flag=true;
        dfs(row+1);
    }
}
int main(){
    while(scanf("%d",&n)&&n!=-1){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&map[i][j]);
            }
        }
        min_sum=INF2;
        dfs(1);
        printf("%d\n",min_sum);
    }
    return 0;
}
