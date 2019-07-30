#include<stdio.h>
int a[8], n = 8, cnt;//之所以是a[8],因为实际上位置的放置永远也只赋了8次值，某一个位置永远也只能赋一次值，会被覆盖的
void DFS(int row)
{
	if (row == n)
	{
		cnt++;
		printf("第%d种摆放方案:\n", cnt);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n;j++)
			if (a[i] == j) printf("1 ");//代表放置有皇后
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
			a[row] = i;//代表第row行,第i列
			flag = true;
			for (int j = 0; j < row; j++)//只需要考虑row行之前的行是否冲突,row行之后假定还没放置皇后,因为前面的一次方案里row行之后可能会有不必要的冲突
			if (a[row] == a[j] || row - j == a[row] - a[j] || row - j == a[j] - a[row])//分别为同一列是否冲突,主对角线是否冲突,次对角线是否冲突
			{
				flag = false;//说明有冲突,置标记为0,重新判断别的行而不进入下一行的dfs
				break;
			}
			if (flag) DFS(row + 1);
		}
	}
}
int main()
{
	DFS(0);
	printf("八皇后问题总共有%d种摆放方案\n", cnt);
	return 0;
}
