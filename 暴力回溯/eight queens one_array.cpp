#include<stdio.h>
int a[8], n = 8, cnt;//֮������a[8],��Ϊʵ����λ�õķ�����ԶҲֻ����8��ֵ��ĳһ��λ����ԶҲֻ�ܸ�һ��ֵ���ᱻ���ǵ�
void DFS(int row)
{
	if (row == n)
	{
		cnt++;
		printf("��%d�ְڷŷ���:\n", cnt);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n;j++)
			if (a[i] == j) printf("1 ");//��������лʺ�
			else printf("0 ");
			putchar('\n');
		}
		putchar('\n');
	}
	else
	{
		bool flag;
		for (int i = 0; i < n; i++)
		{
			a[row] = i;//�����row��,��i��
			flag = true;
			for (int j = 0; j < row; j++)//ֻ��Ҫ����row��֮ǰ�����Ƿ��ͻ,row��֮��ٶ���û���ûʺ�,��Ϊǰ���һ�η�����row��֮����ܻ��в���Ҫ�ĳ�ͻ
			if (a[row] == a[j] || row - j == a[row] - a[j] || row - j == a[j] - a[row])//�ֱ�Ϊͬһ���Ƿ��ͻ,���Խ����Ƿ��ͻ,�ζԽ����Ƿ��ͻ
			{
				flag = false;//˵���г�ͻ,�ñ��Ϊ0,�����жϱ���ж���������һ�е�dfs
				break;
			}
			if (flag) DFS(row + 1);
		}
	}
}
int main()
{
	DFS(0);
	printf("�˻ʺ������ܹ���%d�ְڷŷ���\n", cnt);
	return 0;
}
