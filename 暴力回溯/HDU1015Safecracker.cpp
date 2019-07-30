#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char a[26], b[5];
int target;
bool visit[26],flag;
bool solve(int v, int w, int x, int y, int z){
    if (v - w*w + x*x*x - y*y*y*y + z*z*z*z*z == target)
        return true;
    else
        return false;
}
bool DFS(int len,int num){
    if (num == 5){
        if (solve(b[0] - 64, b[1] - 64, b[2] - 64, b[3] - 64, b[4] - 64)){
            flag=true;
            return true;
        }
        else return false;
    }
    else{
        for (int i = 0; i < len; i++){
            if (!visit[i]){
                visit[i] = true;
                b[num] = a[i];
                if (DFS(len, num + 1)) return true;
                visit[i] = false;
            }
        }
    }
    if(flag) return true;
    else return false;
}
int main(){
    int len;
    while (scanf("%d %s", &target, a), target || strcmp(a, "END")){
        len = strlen(a);
        memset(visit, false, sizeof(visit)*len);
        flag=false;
        sort(a, a + len,greater<char>());
        if (DFS(len, 0)) puts(b);
        else puts("no solution");
    }
    return 0;
}

