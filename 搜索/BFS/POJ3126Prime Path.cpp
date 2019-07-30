#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
#define N 10000
bool prime[N];
struct node{
	int n;
	int time;
};
void prim(){
	for (int i = 0; i < N; i++)
		prime[i] = true;
	prime[0] = prime[1] = false;
	for (int i = 2; i < 100; i++){
		if (prime[i])
		for (int j = i*i; j < N; j += i)
			prime[j] = false;
	}
}
int BFS(int start,int end){
	if (start == end) return 0;
	int digit[4];
	static bool visit[N];
	memset(visit, false, sizeof(visit));
	queue<node> Q;
	node v;
	visit[start] = true;
	v.n = start, v.time = 0;
	Q.push(v);
	while (!Q.empty()){
		node x;
		x = Q.front();
		Q.pop();
		digit[0] = x.n % 10;
		x.n /= 10;
		digit[1] = x.n % 10;
		x.n /= 10;
		digit[2] = x.n % 10;
		x.n /= 10;
		digit[3] = x.n % 10;
		int tmp;
		node val;
		for (int i = 0; i<4; i++){
			tmp = digit[i];
			for (int j = 0; j <= 9; j++){
				if (tmp != j){
					if (i == 3 && j == 0) continue;
					digit[i] = j;
					val.n = digit[0] + digit[1] * 10 + digit[2] * 100 + digit[3] * 1000;
					if (!visit[val.n] && prime[val.n]){
						val.time = x.time + 1;
						Q.push(val);
						visit[val.n] = true;
					}
					if (val.n == end) return val.time;
				}
			}
			digit[i] = tmp;
		}
	}
	return -1;
}
int main(){
	int n,start,end,res;
	prim();
	scanf("%d", &n);
	while (n--){
		scanf("%d%d", &start, &end);
		res = BFS(start, end);
		if (res != -1)
			printf("%d\n", res);
		else
			printf("Impossible\n");
	}
	return 0;
}