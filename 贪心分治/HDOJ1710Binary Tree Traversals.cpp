#include<cstdio>
#include<stack>
using namespace std;
int pre[1010], in[1010];
stack<int> S;
void pos(int start1, int last1, int start2, int last2){
    int i, j;
    S.push(pre[start1]);
    for (i = start2; in[i] != pre[start1]; i++);
    j = start1 + i - start2;
    if (j + 1 <= last1&&i + 1 <= last2)
        pos(j + 1, last1, i + 1, last2);
    if (start1 + 1 <= j&&start2 <= i - 1)
        pos(start1 + 1, j, start2, i - 1);
}
int main(){
    int n;
    while (scanf("%d", &n) != EOF){
        for (int i = 0; i < n; i++)
            scanf("%d", pre + i);
        for (int i = 0; i < n; i++)
            scanf("%d", in + i);
        pos(0, n - 1, 0, n - 1);
        printf("%d", S.top());
        S.pop();
        while (!S.empty()){
            printf(" %d", S.top());
            S.pop();
        }
        putchar('\n');
    }
    return 0;
}

