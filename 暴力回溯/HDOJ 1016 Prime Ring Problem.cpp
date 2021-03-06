#include<cstdio>
#include<cstring>
int a[50];
bool visit[50],prime[50];
void prim(){
    for (int i = 1; i < 50; i++)
        prime[i] = true;
    prime[1] = false;
    for (int i = 2; i <25; i++){
        if (prime[i])
        for (int j = 2 * i; j < 50; j += i)
            prime[j] = false;
    }
}
void DFS(int n,int num){
    if (num == n + 1&&prime[a[1]+a[n]]){
        printf("%d", a[1]);
        for (int i = 2; i <= n; i++)
            printf(" %d", a[i]);
        putchar('\n');
    }
    else{
        for (int i = 2; i <= n;i++)
        if (!visit[i]&&prime[i+a[num-1]]){
            visit[i] = true;
            a[num] = i;
            DFS(n, num + 1);
            visit[i] = false;
        }
    }
}
int main(){
    int n,cnt=1;
    prim();
    a[1] = 1;
    while (scanf("%d", &n) != EOF){
        printf("Case %d:\n", cnt);
        DFS(n, 2);
        putchar('\n');
        cnt++;
    }
    return 0;
}
