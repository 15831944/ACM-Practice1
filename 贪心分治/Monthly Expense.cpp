#include<stdio.h>
#define N 100010
int a[N],n,m;
void erfen(int left,int right)
{
    if(left==right)
    {
        printf("%d",right);
        return;
    }
    int cnt=0,sum=0,mid;
    mid=(left+right)/2;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum>mid)//��ʱ��sum�еĸ���a[i]���Թ���һ��Ԥ���,��ʵmid�Ҿ���Ӧ��ֻ��һ�ֺ����ı�׼
        {
            cnt++;
            sum=a[i];
        }
    }
    cnt++;//�����ǰ���󲻹�����Щ�ݶ�ҲҪ����һ��Ԥ���,��Ϊ���в����,��ҲҪ���乹��һ��Ԥ�����Ȼ������Ԥ���ҪС
    if(cnt<=m)
        erfen(left,mid);
    else
        erfen(mid+1,right);//����mid+1��Ҫ����Ϊ������Щֵ��2���ε�midֵһ�������޵ݹ���ȥ,�������Ļ��Ϳ��Բ��������������Ϊ�о�ȷλ�ı���
}
int main()
{
    int maxn=0,sum=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
        if(maxn<a[i])
            maxn=a[i];
        sum+=a[i];
    }
    erfen(maxn,sum);
    return 0;
}
