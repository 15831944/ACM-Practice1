#include<stdio.h>
bool visit[10];
int temp[10],n,sum;
bool permutation(int *a,int k)
{
    if(k==n)
    {
        for(int i=0; i<n; i++) temp[i]=a[i];
        for(int i=0; i<n-1; i++)
            for(int j=0; j<n-i-1; j++) temp[j]+=temp[j+1];
        if(*temp==sum)
        {
            for(int i=0; i<n-1; i++) printf("%d ",a[i]);
            printf("%d\n",a[n-1]);
            return true;
        }
        return false;
    }
    else
        for(int i=0; i<n; i++)
            if(visit[i]==false)
            {
                a[k]=i+1;//将当前位的值与上一次退栈的位的值交换
                visit[i]=true;
                if(permutation(a,k+1)) return true;//每次递归都会向低位前进发生相邻的交换，再依次向前交换
                visit[i]=false;//为下次的回溯做好准备
            }
    return false;
}
int main()
{
    int a[10];
    int k;
    while(scanf("%d%d",&n,&sum)!=EOF)
    {
        k=0;
        permutation(a,k);
    }
    return 0;
}
/*#include<stdio.h> //宏定义输出和for循环
#define For(i,n) for(int i=0;i<n;i++)
#define output(x) printf("%d ",x)
bool visit[10];
int temp[10];
bool permutation(int *a,int k,int n,int sum)
{
    if(k==n)
    {
        For(i,n) temp[i]=a[i];
        For(i,n-1)
        For(j,n-i-1) temp[j]+=temp[j+1];
        if(*temp==sum)
        {
            For(i,n-1) output(a[i]);
            printf("%d\n",a[n-1]);
            return true;
        }
        return false;
    }
    else
        For(i,n)
        if(visit[i]==false)
        {
            a[k]=i+1;//将当前位的值与上一次退栈的位的值交换
            visit[i]=true;
            if(permutation(a,k+1,n,sum)) return true;//每次递归都会向低位前进发生相邻的交换，再依次向前交换
            visit[i]=false;//为下次的回溯做好准备
        }
    return false;
}
int main()
{
    int a[10];
    int n,sum,k;
    while(scanf("%d%d",&n,&sum)!=EOF)
    {
        k=0;
        permutation(a,k,n,sum);
    }
    return 0;
}*/
