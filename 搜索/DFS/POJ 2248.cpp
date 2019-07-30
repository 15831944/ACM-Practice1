#include<cstdio>
#include<cstring>
int a[105],n;
bool visit[105];
//这题目不知道为什么我写的时间是400多ms,别人写的94ms，搞不懂
int dfs(int index,int id){
    if(index>id||a[index]>n)
        return -1;
    if(a[index]==n)
        return index;
    int tmp,len;
    for(int i=index;i>=0;i--){
        for(int j=i;j>=0;j--){//枚举前面的加数
            tmp=a[i]+a[j];
            if(tmp<=a[index]) return -1;
            if(!visit[tmp]&&tmp>a[index]){//其实标记数组没必要，因为前面的相加的值一旦枚举过,一定<=a[index]
                visit[tmp]=true;
                a[index+1]=tmp;
                if((len=dfs(index+1,id))>=0)
                    return len;
                visit[tmp]=false;
            }
        }
    }
    return -1;
}
int main(){
    int len;
    a[0]=1;
    while(scanf("%d",&n)&&n){
        for(int i=0;i<n;i++){//贪心 这里最开始就从最短得到长度开始枚举
            memset(visit,false,sizeof(visit));
            if((len=dfs(0,i))>=0){
                printf("1");
                for(int i=1;i<=len;i++)
                    printf(" %d",a[i]);
                    putchar('\n');
                break;
            }
        }
    }
    return 0;
}
