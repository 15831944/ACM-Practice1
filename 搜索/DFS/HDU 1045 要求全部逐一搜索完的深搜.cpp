#include<cstdio>
char map[6][6];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int n,max_cnt;

bool judge(int x,int y){
    int xx,yy;
    for(int i=0;i<4;i++){
        xx=x,yy=y;
        while(xx>0&&xx<=n&&yy>0&&yy<=n){
            xx+=dir[i][0];
            yy+=dir[i][1];
            if(map[xx][yy]=='Y'){
                return false;
            }
            if(map[xx][yy]=='X'){
                break;
            }

        }
    }
    return true;
}

void dfs(int row,int col,int cnt){
    if(cnt>max_cnt)
        max_cnt=cnt;
    for(int i=row;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==row&&j<col)
                continue;
            if(map[i][j]=='.'&&judge(i,j)){
                map[i][j]='Y';
                if(j<n)
                    dfs(i,j+1,cnt+1);
                else
                    dfs(i+1,1,cnt+1);
                map[i][j]='.';
            }
        }
    }
}

int main(){
    while(scanf("%d",&n)&&n){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf(" %c",&map[i][j]);
            }
        }
        max_cnt=-1;
        dfs(1,1,0);
        printf("%d\n",max_cnt);
    }
    return 0;
}
