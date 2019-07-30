/*//����ʹ��DFS+��֦ ���������������Բ���ʶ�ʡȥ��
#include <iostream>
#include <cmath>
using namespace std;
#define INF 1000000
int mins[21], minv[21];
#define min(a, b) ((a) < (b) ? (a) : (b))
int n, m, best;
void init()
{
    int i;
    for(i = 1; i < 21; i++)
    {							//ע��������а뾶�͸߶ȶ��������������Կɵ������ʽ��
        mins[i] = mins[i - 1] + 2 * i * i;		//mins��ʾ��������һ�㵽 i �����С�����(����������˲���)
        minv[i] = minv[i - 1] + i * i * i;		//minv��ʾ��������һ�㵽 i �����С���
    }
}
//dfs��m�㿪ʼ����������һֱ������0�����
//deep��ʾ�ò������sums��ʾ��deep + 1 -> m�õ��ı������ sumv��ʾdeep + 1 -> m�õ��������r��ʾdeep + 1�İ뾶��h��ʾdeep + 1�ĸ߶�
void dfs(int deep, int sums, int sumv, int r, int h)
{
    if(deep == 0)
    {
        if(sumv == n && sums < best)
            best = sums;
        return ;
    }
    //�����õ���������֦
    //sums + mins[deep]> best ��ʾ��ǰ�ĵ���deep + 1�㵽 m ��ı�������ϴӶ��㵽deep�����С�����������������Ѿ��õ���best,��ô1��deep�������۰뾶�͸߶�ȡ��ֵ������Ч��
    //sumv + minv[deep] > nͬ��
    // 2 * (n - sumv) / r + sums >= best ���Ǹ���ľ��裬���û�еĻ�����ɳ�ʱ����Ϊ�˰�sumv��sums��ϵ������ԭ������:
    // �����ܹ��õ�bestʱ(Ϊʲô���������أ���Ϊ����ò����Ļ���ô���Ѿ�����һ����֦��ȥ��,�����ڵ�������֦��֤ʱ��ʾ�Ѿ�ͨ���˵�һ����֦��Ҫ��)��
    // n - sumv = h[1] * r[1] * r[1] + ... + h[deep] * r[deep] * r[deep] < h[1] * r[1] * r + ... + h[deep] * r[deep] * r ����Ϊr��deep + 1��İ뾶��
    //����h[1]...h[deep]��ʾ�ں������β�����£�1��deep��Ӧ��ȡ��hֵ��r[1]ͬ��
    // ����ͬʱ����r �ٳ���2�� 2 * (n - sumv) / r < 2 * (h[1] * r[1] + ... + h[deep] * r[deep])
    // 2 * (n - sumv) / r < best - sums
    // 2 * (n - sumv) / r + sums < best ���� ����ɵü�֦����
    if(sums + mins[deep] > best || sumv + minv[deep] > n || (2 * (n - sumv) / r + sums >= best))
            return;
    int i, j,  maxh;
    for(i = r - 1; i >= deep; i--)
    {
        if(deep == m)
            sums = i * i;
        maxh = min(n - sumv - minv[deep - 1] / i * i, h - 1);
        for(j = maxh; j >= deep; j--)
            dfs(deep - 1, sums + 2 * i * j, sumv + j * i * i, i, j);
    }
}
int main()
{
    best = INF;   //��best�ó�һ���ܴ��ֵ
    cin >> n >> m;
    dfs(m, 0, 0, sqrt(n) + 1, n + 1);  //��ʼ����m����һ��İ뾶Ϊsqrt(n) + 1����h����1ʱ�õ������ޣ��߶�h��ʾ�뾶Ϊ1ʱ�õ�������
    if(best == INF)
        cout << 0 << endl;
    else
        cout << best << endl;
    return 0;
}*/
#include<stdio.h>
#include<algorithm>
using namespace std;
#define INF 1000000000
#define max_m 21
int minv[max_m],mins[max_m];
int n,m,ans;
void init()
{
    int i,j;
    for(i=1;i<=max_m;i++)
    {
        minv[i]=minv[i-1]+i*i*i;
        mins[i]=mins[i-1]+2*i*i;
    }
}
void dfs(int k,int r,int h,int s,int v)
{

    if(k==0)
    {

        if(v==n&&ans>s)
            ans=s;
        return;
    }
    if (v+minv[k]>n||s+mins[k]>ans||s+2*(n-v)/r>ans) return;
    int r0,h0;
    for(r0=r-1;r0>=k;r0--)
    {
        h0=min(h-1,(n-v-minv[k-1])/(r0*r0));
        while(h0>=k)
        {
            if(k==m) s=r0*r0;
            dfs(k-1,r0,h0,s+2*r0*h0,v+r0*r0*h0);
            h0--;
        }
    }
}
int main()
{
    init();
    scanf("%d%d",&n,&m);
    ans=INF;
    dfs(m,n,n,0,0);
    if(ans!=INF)
        printf("%d\n",ans);
    else
        printf("0\n");
    return 0;
}
