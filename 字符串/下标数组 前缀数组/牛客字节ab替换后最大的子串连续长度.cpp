/**
    ��һ����������a���͡�b�������ַ����ַ���s������Ϊn��ÿ�β������԰�һ���ַ���һ��ת������һ����a������Ϊ��b�������߰�һ����b���óɡ�a��)��
    ���ǲ����Ĵ���������m���������޵Ĳ�������Χ�ڣ��ܹ��õ������������ͬ�ַ����Ӵ��ĳ����Ƕ��١�
 * ����ǰ׺������
 * ���磺
 * n=10,m=1,s=baabaabaab
 *   b a a b a a b a a b
 *   0 1 2 3 4 5 6 7 8 9
 *
 *   �� b-->a
 *   b ��ǰ׺������Ϊ
 *          sums={ 0, 3, 6, 9, 10}//10 Ϊ�ַ�������
 *   ���㳤�ȷֱ�Ϊ:
 *          3  6-0-1=5   9-3-1=5  10-6-1=3
 *     ==>>max = max{ max, sums[i]-sum[i-m-1]-1}
 */
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
using namespace std;
int arra[50005];
int arrb[50005];
int main(){
    //vector<int> arra;
    //vector<int> arrb;
    string a;
    int n,m;
    scanf("%d%d",&n,&m);
    cin >>a;
    int cnta=0,cntb=0,index1=0,index2=0;
    for(int i=0;i<n;i++){
        if(a[i]=='a'){
            cnta++;
            arra[index1++]=i;
            //arra.push_back(i);//��a���±걣������
        }
        else{
            cntb++;
            arrb[index2++]=i;
           // arrb.push_back(i);//��b���±걣������
        }
    }
    if(cnta<=m||cntb<=m){
        printf("%d",n);
    }
    else{
        /*for(vector<int>::iterator it=arra.begin();it!=arra.end();it++)
            printf("%d ",*it);
    putchar('\n');
        for(vector<int>::iterator it=arrb.begin();it!=arrb.end();it++)
            printf("%d ",*it);
            putchar('\n');*/
        //arra.push_back(n);//����Ҫ���ַ������һ���ַ���λ���±�Ž�ȥ���������һ���ַ�a�任Ϊbʱ����ַ��ұߵ�b���������һ�������õ��Ӵ�
        arra[index1++]=n;
        int max1=arra[m];//������Ϊ�±�Ϊ0��λ�������û���ַ����Բ���Ҫ���壬ֱ��ȡ��m+1��λ�õ�a���任���±�����Ѿ������Ӵ��ĸ���
        //printf("max1:");
        for(int i=m+1;i<index1;i++){//ѭ��ѡȡ����,����ȡ����m���Ӵ�����ʵ�е�̰�ĵ�˼ά��ֱ�Ӿ�ȡ���Ĵ���
            max1=max(max1,arra[i]-arra[i-m-1]-1);//arra[i]-arra[i-m-1]-1��ʾ��arra��ȡm��a��������ʵ������λ�����м����,i-m-1����Ҫ������ߵõ�a�ƶ�,ʵ�ʼ����ʱ���������߶���չ��һ��a�ַ�����Ϊ�м�任��b��,���߻�����������һ���Ӵ�
            //printf("%d ",max1);
        }
        //putchar('\n');
        //arrb.push_back(n);
        int max2=arrb[m];
        //printf("max2:");
        for(int i=m+1;i<index2;i++){
            max2=max(max2,arrb[i]-arrb[i-m-1]-1);
            //printf("test:%d\n",arrb[i]-arrb[i-m-1]-1);
            //printf("%d ",max2);
        }
        printf("%d",max1>max2?max1:max2);
    }
    return 0;
}
