#include<cstdio>
#include<queue>
using namespace std;
struct pool{
    int a,b;
    friend bool operator< (const pool &x,const pool &y){
        return x.a < y.a;
    }
};
int main(){
    int T,n,m,sum;
    pool tmp;
    scanf("%d",&T);
    priority_queue<pool> Q;//������ʱ��ʵ����д��forѭ������,�����������Ż��������ʣ����¿�һ��,���û��ʣ��Ӧ�û���������
    while(T--){
        sum=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%d%d",&tmp.a,&tmp.b);
            Q.push(tmp);
        }
        for(int i=0;i<m&&!Q.empty();i++){//�����п��ܵ�����m�����Ѿ�û���ܵ���������
            tmp=Q.top();
            if(!tmp.b){
                sum+=(m-i)*tmp.a;
                break;
            }
            Q.pop();
            sum+=tmp.a;
            tmp.a-=tmp.b;
            if(tmp.a>0) Q.push(tmp);//��Ϊ�п���tmp.a��һ�ε�����tmp.b��tmp.a�����Ϊ������
        }
        while(!Q.empty()) Q.pop();
         printf("%d\n",sum);
    }
    return 0;
}
