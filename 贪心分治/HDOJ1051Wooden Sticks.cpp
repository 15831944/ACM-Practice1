#include<cstdio>
#include<algorithm>
using namespace std;
struct stick{
    int l, w;
    bool flag;
    bool operator<(const stick &a)const{
        if (l < a.l) return true;
        else if (l==a.l)
        if (w < a.w) return true;
        return false;
    }
};
int main(){
    stick array[5001];
    int k, n,minutes,note;
    scanf("%d", &k);
    while (k--){
        minutes = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++){
            scanf("%d%d", &array[i].l, &array[i].w);
            array[i].flag = false;
        }
        sort(array, array + n);
        for (int i = 0; i < n; i++){
            if (!array[i].flag){
                minutes++;
                array[i].flag = true;
                note = i;
                for (int j = i + 1; j < n;j++)
                if (!array[j].flag&&array[j].w >= array[note].w){
                    array[j].flag = true;
                    note = j;
                }
            }
        }
        printf("%d\n", minutes);
    }
    return 0;
}
