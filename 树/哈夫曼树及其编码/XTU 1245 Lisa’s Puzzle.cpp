#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
struct node{
    int l,r,cnt;
    node(){
        l=r=-1;
        cnt=0;
    }
}huff[maxn<<3];
int main(){
    int n,m,cnt=0,index,res[maxn];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        index=0;//cnt��û�����¸�ֵ,һֱ������
        while(m){//���չ����������������ʽȥģ��,��¼ÿ�����Ķ�����λ��·��,0��Ϊ��һλ�����Ƶ�������,1��Ϊ��һλ������λ��������
            if(m&1){
                if(huff[index].r==-1){//��λ��·���ϻ�û�м�¼
                    huff[index].r=++cnt;;//��¼������һλ�������±�,�����ǰ��ղ������,�����Ƚ��ȳ�������ʽ
                    index=cnt;//index��ǰ��־��¼��һλ�±�
                }
                else{//����λ���
                    index=huff[index].r;//index����һλ�Ͱ���ǰ��·��ȥ����,ֻҪ��Ⱦ�һֱ�������ֵ����Ȼ���ֵ��һ�����õ������ǡ��m�������·���ϵ����ͻ��õ�
                    huff[index].cnt++;//ÿ�����ӵ���������һλ��ֵ,��Ϊres[i]Ҫ��¼����±�,ͬʱindex��Ҫ�任,����ֻ����cnt��������ǰһλ����res��¼
                }
            }
            else{
                if(huff[index].l==-1){//ͬ��
                    huff[index].l=++cnt;
                    index=cnt;
                }
                else{
                    index=huff[index].l;
                    huff[index].cnt++;
                }
            }
            m>>=1;
        }
        res[i]=index;
    }
    for(int i=0;i<n;i++)
        printf("%d\n",huff[res[i]].cnt);
    return 0;
}
