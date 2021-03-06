#include <iostream>
#include<algorithm>
using namespace std;
struct object{
    int a, b;
    bool flag;
    bool operator<(const object &x)const{
        return a < x.a;
    }
};
int main(){
    ios::sync_with_stdio(false);
    object node[210];
    int k, n;
    cin >> k;
    while (k--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> node[i].a >> node[i].b;
            node[i].flag = false;
            if (node[i].a > node[i].b)
                swap(node[i].a, node[i].b);
        }
        sort(node+1, node+1 + n);
        int time=0,end;
        for (int i = 1; i <= n; i++){
            if (!node[i].flag){
                time++;
                node[i].flag = true;
                end = node[i].b;
            }
            if (end & 1) end++;
            for (int j = i + 1; j <= n; j++){
                if (!node[j].flag&&node[j].a>end){
                    end = node[j].b;
                    node[j].flag = true;
                    if (end & 1) end++;
                }
            }
        }
        cout << time *10 << endl;
    }
    return 0;
}
