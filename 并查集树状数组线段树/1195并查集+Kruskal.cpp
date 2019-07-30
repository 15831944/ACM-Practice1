#include<cstdio>
#include<algorithm>
using namespace std;
struct edge{
	int x;
	int y;
	int price;
}city[10001];
int vertex[1002];
bool cmp(edge a, edge b){
	return a.price > b.price;
}
void Init(int n){
	for (int i = 1; i <= n; i++)
		vertex[i] = i;
}
/*int find(int x){
	int tmp=x;
	while (vertex[x] != x)
		x = vertex[x];
	while (vertex[tmp] != x){
		vertex[tmp] = x;
		tmp = vertex[tmp];
	}
	return x;
}*/
int find(int x){
	if (vertex[x] != x)
		return vertex[x] = find(vertex[x]);
	else
		return x;
}
bool Union(int v, int w){//����ÿ�ζ���������ͨ���ڵ����н��ĸ��ڵ㶼ͳһ�ģ��ÿ�����ӵ������ıߵĽ������ͨ����λ�ã��ǲ��ǵ�һ����㣬����ǵ�һ�����ͻ�ȫ������,�Ⲣ��Ӱ����С��Ȩֵ�ĺ͵���ȡ
	int x = find(v);
	int y = find(w);
	if (x != y){
		vertex[x] = y;
		return true;
	}
	else
		return false;
}
int Kruskal(int m,int n){
	sort(city, city + m, cmp);
	int sum=0,cnt=0;
	for (int i = 0; i < m; i++){
		if (cnt == n - 1) return sum;//������������ͨ�޻�·,�������ڵ�����1,������ʵ���������������ֻҪ���������������¼������̶ȵؼӱ�
		if (Union(vertex[city[i].x], vertex[city[i].y])){
			sum += city[i].price;
			cnt++;
		}
	}
	return sum;
}
int main(){
	int n, m,num;
	scanf("%d", &num);
	while (num--){
		scanf("%d%d", &n, &m);
		Init(n);
		for (int i = 0; i < m; i++)
			scanf("%d%d%d", &city[i].x, &city[i].y, &city[i].price);
		printf("%d\n",Kruskal(m, n));
	}
	return 0;
}
