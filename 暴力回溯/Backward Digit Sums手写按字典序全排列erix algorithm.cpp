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
                a[k]=i+1;//����ǰλ��ֵ����һ����ջ��λ��ֵ����
                visit[i]=true;
                if(permutation(a,k+1)) return true;//ÿ�εݹ鶼�����λǰ���������ڵĽ�������������ǰ����
                visit[i]=false;//Ϊ�´εĻ�������׼��
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
/*#include<stdio.h> //�궨�������forѭ��
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
            a[k]=i+1;//����ǰλ��ֵ����һ����ջ��λ��ֵ����
            visit[i]=true;
            if(permutation(a,k+1,n,sum)) return true;//ÿ�εݹ鶼�����λǰ���������ڵĽ�������������ǰ����
            visit[i]=false;//Ϊ�´εĻ�������׼��
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
