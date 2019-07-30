#include<stdio.h>
char G[730][730];
int dis(int k)
{
	int res=1;
	for (int i = 1; i < k-1; i++)
		res *= 3;
		return res;
}
void solve(int k,int row,int col)
{
	if (k == 1)
		G[row][col] = 'X';
	else
	{
		int dist = dis(k);
		solve(k - 1, row, col);
		solve(k - 1, row, col + 2 * dist);
		solve(k - 1, row + dist, col + dist);
		solve(k - 1, row + 2 * dist, col);
		solve(k - 1, row + 2 * dist, col + 2 * dist);
	}
}
void print(int k)
{
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		if (G[i][j] == 'X')
			putchar(G[i][j]);
		else
			putchar(' ');
		putchar('\n');
	}
	puts("-");
}
int main()
{
	int k,dist;
	solve(7, 0, 0);
	while (scanf("%d", &k) != EOF)
	{
		dist = dis(k + 1);
		print(dist);
	}
	return 0;
}