#include<cstdio>//http://blog.sina.com.cn/s/blog_a16dd6d10101585j.html  可能是因为stl的queue效率太低，导致超时，最好自己能写一个queue并维护
#include<cstring>
#include<queue>
using namespace std;
struct snake{
    int x[8],y[8];
    int cnt;
}body;
int dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};//顺时针方向 左上右下分别对应数组下标0,1,2,3
char map[25][25];
bool visit[25][25][1<<14],n,m,l;

bool judgeGo(int x,int y){
    if(x<1||x>n||y<1||y>m||map[x][y]=='1')
        return false;
    for(int i=1;i<l;i++){//判断蛇身是否对蛇头形成障碍
        if(x==body.x[i]&&y==body.y[i])
            return false;
    }
    return true;
}

int judgeDir(int x1,int y1,int x2,int y2){
    if(x1==x2&&y1-y2==1) return 0;//相对前一个蛇身在其左侧
    if(x1-x2==1&&y1==y2) return 1;//上侧
    if(x1==x2&&y1-y2==-1) return 2;//右侧
    if(x1-x2==-1&&y1==y2) return 3;//下侧
}
int bfs(){
    queue<snake> Q;
    snake btmp;
    Q.push(body);
    int state,dir0;
    while(!Q.empty()){
        body=Q.front();
        Q.pop();
        //printf("%d %d\n",body.x[0],body.y[0]);
        if(btmp.x[0]==1&&btmp.y[0]==1) return btmp.cnt;
        for(int i=0;i<4;i++){
            state=0;
            btmp=body;
            int xx=btmp.x[0]+dir[i][0];
            int yy=btmp.y[0]+dir[i][1];
            if(judgeGo(xx,yy)){
                for(int j=l-1;j>=1;j--){
                    btmp.x[j]=btmp.x[j-1];
                    btmp.y[j]=btmp.y[j-1];
                }
                btmp.x[0]=xx,btmp.y[0]=yy;
                for(int k=0;k<l-1;k++){
                    dir0=judgeDir(btmp.x[k],btmp.y[k],btmp.x[k+1],btmp.y[k+1]);//判断蛇身的每一部分相对它上一节的相对位置
                    state|=(dir0<<(k*2));//保存期方向状态
                }
                if(!visit[xx][yy][state]){//判断这个蛇身状态之前是否有过扩展
                    btmp.cnt++;
                    Q.push(btmp);
                    visit[xx][yy][state]=true;
                }
            }
        }
    }
    return -1;
}

int main(){
    int k,x,y,state,dir0,cnt=1;
    while(scanf("%d%d%d",&n,&m,&l)&&n&&m&&l){
        state=0;
        memset(map,'0',sizeof(map));
        memset(visit,false,sizeof(visit));
        body.cnt=0;
        for(int i=0;i<l;i++)
            scanf("%d%d",&body.x[i],&body.y[i]);
        for(int i=0;i<l-1;i++){
            dir0=judgeDir(body.x[i],body.y[i],body.x[i+1],body.y[i+1]);
            state|=(dir0<<(i*2));
        }
        visit[body.x[0]][body.y[0]][state]=true;
        scanf("%d",&k);
        for(int i=0;i<k;i++){
            scanf("%d%d",&x,&y);
            map[x][y]='1';
        }
        printf("Case %d: %d\n",cnt++,bfs());

    }
    return 0;
}
