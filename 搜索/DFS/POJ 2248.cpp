#include<cstdio>
#include<cstring>
int a[105],n;
bool visit[105];
//����Ŀ��֪��Ϊʲô��д��ʱ����400��ms,����д��94ms���㲻��
int dfs(int index,int id){
    if(index>id||a[index]>n)
        return -1;
    if(a[index]==n)
        return index;
    int tmp,len;
    for(int i=index;i>=0;i--){
        for(int j=i;j>=0;j--){//ö��ǰ��ļ���
            tmp=a[i]+a[j];
            if(tmp<=a[index]) return -1;
            if(!visit[tmp]&&tmp>a[index]){//��ʵ�������û��Ҫ����Ϊǰ�����ӵ�ֵһ��ö�ٹ�,һ��<=a[index]
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
        for(int i=0;i<n;i++){//̰�� �����ʼ�ʹ���̵õ����ȿ�ʼö��
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
