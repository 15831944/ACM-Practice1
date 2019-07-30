#include<cstdio>
char map[25][25];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int row,col,cnt;
void dfs(int x,int y){
     int xx,yy;
     for(int i=0;i<4;i++){
         xx=x+dir[i][0];
         yy=y+dir[i][1];
         if(xx>=1&&xx<=row&&yy>=1&&yy<=col&&map[xx][yy]=='.'){
            map[xx][yy]='#';
            cnt++;
            dfs(xx,yy);
         }
     }
}
int main(){
    int x,y;
    while(scanf("%d%d",&col,&row)&&row||col){
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                scanf(" %c",&map[i][j]);
                if(map[i][j]=='@'){
                    x=i,y=j;
                    map[i][j]='#';
                }
            }
        }
        cnt=1;
        dfs(x,y);
        printf("%d\n",cnt);
    }
    return 0;
}
