#include<stdio.h>
int row, n = 8,cnt;
bool judge_attack(int row, int col, int(*a)[8])
{
	static bool flag1, flag2, flag3, flag4;
	flag1 = flag2 = flag3 = flag4 = true;
	for (int i = 0; i < row;i++)
	if (a[i][col])
	{
		flag1 = false;
		break;
	}
	for (int i = row, j = col; i >= 0 && j >= 0;i--,j--)
	if (a[i][j])
	{
		flag2 = false;
		break;
	}
	for (int i = row, j = col; i >= 0 && j < n;i--,j++)
	if (a[i][j])
	{
		flag3 = false;
		break;
	}
	if (flag1&&flag2&&flag3)
		return true;
	else
		return false;
}
void DFS(int row, int(*s)[8])
{
	if (row == n)
	{
		cnt++;
		printf("�˻ʺ�����ĵ�%d�ַ���:\n", cnt);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				printf("%d ", s[i][j]);
			putchar('\n');
		}
	}
	else
	{
		/*int s[8][8];//�������һ�ζ�ά����ռ俪����Ϊ�˽�������ʱ�ܻص���ʱ�ݹ����ʱn�ʺ�Ĳ���
		for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			s[i][j] = a[i][j];*/
		for (int i = 0; i < n; i++)//�ж�ÿһ��
		{
			if (judge_attack(row, i,s))//�ж��Ƿ���໥����
			{
				/*for (int j = 0; j < n; j++)//���ַ���̫����,��57��,��s[row][i]�ٸĻ�0��������,���ﲻ��ʡ��,ԭ���ǻ���׼��������һ�е�������ʱ���������һ�е�����λ�ö�����,���º���ĵݹ鶼�ᵼ��ͬһ�еĳ�ͻ���Ծ���ԶҲû�н���DFS��,row��ȻҲ�Ͳ��ᵽ8,���о�ȥ����һ�ַ�����û���е��벻ͨ,��ʵ�ϸо�Ӧ���ǻ��8�����ҵ�,Ӧ����ѭ�����ַ����ö�ٵ���ǰ���α���Ҳû���ɰ˻ʺ�,���漸��ͬһ�з��õ�û���Խ��Խ�ർ�º���ĵݹ�Ҳȫ��ʧ����
					s[row][j] = 0;*/
				s[row][i] = 1;
				DFS(row + 1,s);
				s[row][i]=0;
			}
		}
	}
}
int main()
{
	static int a[8][8];
	DFS(0,a);
	printf("�˻ʺ����⹲��%d�ַ���\n", cnt);
	return 0;
}
