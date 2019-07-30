#include<stdio.h>
int num_1(int x)
{
    int cnt=0;
    while(x)
    {
        if(x&1) cnt++;
        x>>=1;
    }
    return cnt;
}
void xor_(int *a,int m,int *b,int n)
{
    int temp1,temp2,temp3,result;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            temp1=b[i]^a[j];
            temp2=num_1(temp1);
            if(j==0)
            {
                temp3=temp2;
                result=a[j];
            }
            else
            {
                if(temp2<temp3)
                {
                    temp3=temp2;
                    result=a[j];
                }
                else if(temp2==temp3)
                    if(result>a[j])
                    result=a[j];
            }
        }
        printf("%d\n",result);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    int a[100],b[100];
    while(T--)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        for(int i=0; i<m; i++)
            scanf("%d",a+i);
        for(int j=0; j<n; j++)
            scanf("%d",b+j);
        xor_(a,m,b,n);
    }
    return 0;
}
