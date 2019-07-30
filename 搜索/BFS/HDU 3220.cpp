#include<cstdio>
#include<queue>
using namespace std;
//储存立方体的32条邻接边
int edge[32][2]={{1,2},{1,3},{1,5},{1,9},
				        {2,4},{2,6},{2,10},
				        {3,4},{3,7},{3,11},
				        	  {4,8},{4,12},
				        {5,6},{5,7},{5,13},
							  {6,8},{6,14},
						      {7,8},{7,15},
							  	  	{8,16},
						{9,10},{9,11},{9,13},
							   {10,12},{10,14},
							   {11,12},{11,15},
							           {12,16},
								{13,14},{13,15},
										{14,16},
										{15,16}};
int val[131080];//最大的状态值为2^17-1个状态
struct cube{
    int num,cnt;
};
int calState(int *a){
    int state=0;
    for(int i=1;i<=16;i++){
        if(a[i])
            state |=(1<<i);//按位与初始状态值
    }
    return state;
}

void bfs(int x){
    queue <cube>Q;
    cube c,tmp;
    c.num=x,c.cnt=0;
    Q.push(c);
    while(!Q.empty()){
        tmp=c=Q.front();
        Q.pop();
        for(int i=0;i<32;i++){
            tmp=c;
            int p1=tmp.num&(1<<edge[i][0]);//取出当前顶点的这一位值
            int p2=tmp.num&(1<<edge[i][1]);
            if(p1!=p2){//如果2顶点状态相反，则按位异或交换
                tmp.num^=(1<<edge[i][0]);
                tmp.num^=(1<<edge[i][1]);
                if(!val[tmp.num]&&tmp.cnt<3){//某一状态没有扩展过切步数<3时放入队列
                    tmp.cnt++;
                    Q.push(tmp);
                    val[tmp.num]=tmp.cnt;
                }
            }
        }
    }
}

int main(){
    int T,a[17]={-1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},b[17],state1,state2,cnt=1;
    state1=calState(a);
    bfs(state1);
    scanf("%d",&T);
    while(T--){
        for(int i=1;i<=16;i++)
            scanf("%d",&b[i]);
        state2=calState(b);
        if(state2==state1){
            printf("Case #%d: 0\n",cnt);
            cnt++;
            continue;
        }
        if(!val[state2])
            printf("Case #%d: more\n",cnt);
        else
            printf("Case #%d: %d\n",cnt,val[state2]);
        cnt++;
    }
    return 0;
}
