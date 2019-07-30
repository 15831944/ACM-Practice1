#include<stdio.h>//默认permutation 产生的全排列为按字典序顺序 而且好像不会产生重复的排列的http://blog.csdn.net/desirepath/article/details/50447712 http://blog.csdn.net/ac_gibson/article/details/45308645
#include<algorithm>
using namespace std;
int main()
{
    int n,sum;
    int a[10],temp[10];
    while(scanf("%d%d",&n,&sum)!=EOF)
    {
        for(int i=0;i<n;i++) a[i]=i+1;
        do
        {
            for(int i=0;i<n;i++)
            temp[i]=a[i];
            for(int i=0;i<n-1;i++)
                for(int j=0;j<n-i-1;j++)
                temp[j]=temp[j]+temp[j+1];
            if(temp[0]==sum)
            {
                printf("%d",a[0]);
                for(int i=1;i<n;i++)
                    printf(" %d",a[i]);
                putchar('\n');
                break;
            }
        }while(next_permutation(a,a+n));
    }
    return 0;
}
