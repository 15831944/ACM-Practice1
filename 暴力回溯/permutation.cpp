#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[10];
void permutation1(int k,int n){//���������ظ�Ԫ�ص�ȫ����
	if (k == n){
		for (int i = 0; i < n; i++)
			printf("%d ", a[i]);
		putchar('\n');
	}
	else{
		for (int i = k; i < n; i++){
			swap(a[i], a[k]);
			permutation1(k + 1, n);
			swap(a[i], a[k]);
		}
	}
}
int visit[10];
void permutation2(int k, int n){
	int i;
	if (k == n){
		for (i = 0; i<n; i++) printf("%d ", a[i]);
		printf("\n");
	}
	else{
		for (i = 0; i<n; i++){
			if (!visit[i]){
				a[k] = i + 1;//����ĸ�ֵ������ʵ���ǽ���,ֻ������Ϊ���ֵ�ԭ��,����ʵ���˽���
				visit[i] = 1;
				permutation2(k + 1, n);//��һ����ջ����ݵ�����
				visit[i] = 0;//Ϊ��һ������ָʾӦ�ý�����ֵ��Ԫ������
			}
		}
	}
}
bool judge_repetition(int i, int k){
	for (int j = k; j < i;j++)
	if (a[j] == a[i])
		return false;
	return true;
}
void permutation3(int k, int n){//�������ظ�Ԫ�ص�ȫ����
	if (k == n){
		for (int i = 0; i < n; i++)
			printf("%d ", a[i]);
		putchar('\n');
	}
	else{
		for (int i = k; i < n; i++){
			if (!judge_repetition(i, k)) continue;//�жϵ�i��Ԫ���Ƿ���k,i��1�г��ֹ�,�������������һ��ѭ��,�����ʵû̫������,����Ϊʲô���ܸĳ�break,����ֻҪ�������һ��continue���жϻ��ǻ���ȵ�
			swap(a[i], a[k]);
			permutation3(k + 1, n);
			swap(a[i], a[k]);
		}
	}
}
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	int b[5];
	for (int i = 0; i < n; i++)
		b[i] = a[i];
	permutation3(0, n);
	return 0;
}