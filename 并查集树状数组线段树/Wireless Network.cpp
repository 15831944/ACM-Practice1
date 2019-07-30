#include<stdio.h>//并查集
struct post
{
    int x,y;
};
int a[1002];
bool distance(int x1,int y1,int x2,int y2,int d)//判断距离
{
    if((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)<=d*d)
        return true;
    else return false;
}
int set_union(int x)//建立联通关系
{
    int anc=x;
    while(a[anc]!=anc)//找祖先,也可采用递归,但递归的效率太低了
        anc=a[anc];
    for(int i=x,j;i!=anc;)//压缩路径
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
    a[i]=y;//原先的祖先结点指向新修理好的电脑,同时新的电脑变成新的祖先
}
void judge_union(int x,int y)
{
    int i=set_union(x);//这里查找祖先结点如果不相等,会执行压缩路径使得下一次的查找变得更快
    int j=set_union(y);
    if(i==j)
        puts("SUCCESS");
    else
        puts("FAIL");
}
int main()
{
    for(int i=1;i<=1001;i++)//等价关系满足自反性,每个元素的根节点都是它自己本身
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
