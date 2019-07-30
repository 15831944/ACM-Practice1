#include<cstdio>//http://blog.sina.com.cn/s/blog_a16dd6d10101585j.html  ��������Ϊstl��queueЧ��̫�ͣ����³�ʱ������Լ���дһ��queue��ά��
#include<cstring>
#include<queue>
using namespace std;
struct snake{
    int x[8],y[8];
    int cnt;
}body;
int dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};//˳ʱ�뷽�� �������·ֱ��Ӧ�����±�0,1,2,3
char map[25][25];
bool visit[25][25][1<<14],n,m,l;

bool judgeGo(int x,int y){
    if(x<1||x>n||y<1||y>m||map[x][y]=='1')
        return false;
    for(int i=1;i<l;i++){//�ж������Ƿ����ͷ�γ��ϰ�
        if(x==body.x[i]&&y==body.y[i])
            return false;
    }
    return true;
}

int judgeDir(int x1,int y1,int x2,int y2){
    if(x1==x2&&y1-y2==1) return 0;//���ǰһ�������������
    if(x1-x2==1&&y1==y2) return 1;//�ϲ�
    if(x1==x2&&y1-y2==-1) return 2;//�Ҳ�
    if(x1-x2==-1&&y1==y2) return 3;//�²�
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
                    dir0=judgeDir(btmp.x[k],btmp.y[k],btmp.x[k+1],btmp.y[k+1]);//�ж������ÿһ�����������һ�ڵ����λ��
                    state|=(dir0<<(k*2));//�����ڷ���״̬
                }
                if(!visit[xx][yy][state]){//�ж��������״̬֮ǰ�Ƿ��й���չ
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
