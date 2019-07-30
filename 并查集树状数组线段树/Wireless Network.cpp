#include<stdio.h>//���鼯
struct post
{
    int x,y;
};
int a[1002];
bool distance(int x1,int y1,int x2,int y2,int d)//�жϾ���
{
    if((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)<=d*d)
        return true;
    else return false;
}
int set_union(int x)//������ͨ��ϵ
{
    int anc=x;
    while(a[anc]!=anc)//������,Ҳ�ɲ��õݹ�,���ݹ��Ч��̫����
        anc=a[anc];
    for(int i=x,j;i!=anc;)//ѹ��·��
    {
        j=a[i];
        a[i]=anc;
        i=j;
    }
    return anc;
}
void join_talk(int x,int y)
{
    int i=set_union(x);
    a[i]=y;//ԭ�ȵ����Ƚ��ָ��������õĵ���,ͬʱ�µĵ��Ա���µ�����
}
void judge_union(int x,int y)
{
    int i=set_union(x);//����������Ƚ����������,��ִ��ѹ��·��ʹ����һ�εĲ��ұ�ø���
    int j=set_union(y);
    if(i==j)
        puts("SUCCESS");
    else
        puts("FAIL");
}
int main()
{
    for(int i=1;i<=1001;i++)//�ȼ۹�ϵ�����Է���,ÿ��Ԫ�صĸ��ڵ㶼�����Լ�����
        a[i]=i;
    bool flag[1002]={0};
    post b[1002];
    int n,d;
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&b[i].x,&b[i].y);
    char op;
    int t,p;
    while(scanf(" %c",&op)!=EOF)
    {
        switch(op)
        {
        case 'O':
            scanf("%d",&t);
            flag[t]=true;
            for(int i=1;i<=n;i++)
            {
                if(flag[i]&&distance(b[i].x,b[i].y,b[t].x,b[t].y,d)&&i!=t)
                    join_talk(i,t);
            }
            break;
        case 'S':
            scanf("%d%d",&t,&p);
            judge_union(t,p);
        }

    }
    return 0;
}
