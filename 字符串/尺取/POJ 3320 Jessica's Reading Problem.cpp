#include<cstdio>
#include<map>
#include<set>
#define INF 0x3f3f3f3f
using namespace std;
int a[1000010];
set<int> b;//����set ����ͬҳ���漰����֪ͬʶ����˵�
map<int,int> mp;//��¼ĳһ��֪ʶ��ѡ�еĴ���
int main(){
    int p,num;
    b.clear();
    mp.clear();
    scanf("%d",&p);
        for(int i=0;i<p;i++){
            scanf("%d",&a[i]);
            b.insert(a[i]);
        }
        num=b.size();//�ܵ�֪ʶ��ĸ���
        int left=0,right=0,sum=0,res=INF;
        while(left<p&&right<p){
            if(!mp[a[right]]){//�����֪ʶ��֮ǰ��û�漰 �ܸ���+1
                sum++;
            }
            mp[a[right]]++;//���֪ʶ���Ӧ�ĸ�����1
            while(mp[a[left]]>1){
                mp[a[left]]--;//�������֪ʶ���޳� ֱ�������漰һ����֪ʶ��
                left++;
            }
            if(sum==num){//�����е�֪ʶ�㶼�漰����
                if(right-left+1<res)
                    res=right-left+1;
                if(mp[a[left]]==1)
                    sum--;//������˵����Ϊ1��֪ʶ��������1
                mp[a[left]]--;//��ʼ����������
                left++;
            }
            right++;//��������
        }
        printf("%d\n",res);
    return 0;
}
