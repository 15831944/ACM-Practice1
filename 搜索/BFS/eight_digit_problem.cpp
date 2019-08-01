#include<cstdio>
#include<queue>
using namespace std;

struct node{
    int checker_board[3][3];
    int mark_pos;
};
queue<node> Q;
node init_node,final_node;

//输入初始棋盘和目标棋盘的状态
void init(){
    printf("输入初始棋盘的状态:\n");
   for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            scanf("%d", &init_node.checker_board[i][j]);
    init_node.mark_pos=-1;//第一次还没有进行移动，所以不会导致回退到之前的状态
    printf("输入目标棋盘的状态:\n");
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            scanf("%d", &final_node.checker_board[i][j]);
    final_node.mark_pos=-1;
    Q.push(init_node);
}

int cal(node tmp,int pos){
    int cnt=0;
    if(tmp.checker_board[pos/3][pos%3]){
        for(int i=0;i<pos;i++){
            if(tmp.checker_board[i/3][i%3]!=0&&tmp.checker_board[i/3][i%3]<tmp.checker_board[pos/3][pos%3]){
                cnt++;
            }
        }
    }
    return cnt;
}

//对初始状态和目标状态的奇偶排列进行判断
bool init_check(){
    int res1=0,res2=0;
    for(int i=0;i<9;i++){
        res1+=cal(init_node,i);
        res2+=cal(final_node,i);
    }
    printf("初始状态与目标状态的逆序数为:res1=%d res2=%d\n",res1,res2);
    bool flag1=false,flag2=false;
    if(res1%2==0) flag1=true;
    if(res2%2==0) flag2=true;
    if(flag1 ^ flag2==0) return true;
    else return false;
}

//找出空格的位置
void loction(node tmp,int &x,int &y){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            if(tmp.checker_board[i][j]==0){
                x=i,y=j;
                return;
            }
        }
}

//检测是否达到了目标状态
bool check_state(node tmp){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(tmp.checker_board[i][j]!=final_node.checker_board[i][j])
                return false;
    return true;
}

//将空格与相邻左、上、右、下进行移动
void mobile_pos(node move_node){
    int x,y;
    node tmp;
    loction(move_node,x,y);
    int rollback = move_node.mark_pos;
    //mark_pos的0 1 2 3分别代表左、上 、右、 下
    if(x!=0&&rollback!= 1){//空格只要不在第一行就能向上移动
        tmp = move_node;
        tmp.checker_board[x][y]=tmp.checker_board[x-1][y];
        tmp.checker_board[x-1][y]=0;
        tmp.mark_pos=3;//下一次移动这个状态时不能再向下移动否则会回退到当前状态
        Q.push(tmp);
    }
    if(x!=2&&rollback!=3){
        tmp=move_node;
        tmp.checker_board[x][y]=tmp.checker_board[x+1][y];
        tmp.checker_board[x+1][y]=0;
        tmp.mark_pos=1;
        Q.push(tmp);
    }
    if (y!=0&&rollback!=0){
        tmp=move_node;
        tmp.checker_board[x][y]=tmp.checker_board[x][y-1];
        tmp.checker_board[x][y-1]=0;
        tmp.mark_pos=2;
        Q.push(tmp);
    }
    if (y!=2&&rollback!=2){
        tmp = move_node;
        tmp.checker_board[x][y]=tmp.checker_board[x][y+1];
        tmp.checker_board[x][y+1]=0;
        tmp.mark_pos=0;
        Q.push(tmp);
    }
}
void display(node tmp){
    putchar('\n');
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            printf("%d ",tmp.checker_board[i][j]);
        putchar('\n');
    }
}

int BFS(int &cnt){
    node move_node;
    while(1){
        move_node=Q.front();
        display(move_node);
        if (check_state(move_node)) return cnt;
        if (cnt == 1000) return -1;
        mobile_pos(move_node);
        Q.pop();
        cnt++;
    }
}

//清空队列
void clear_queue(){
    while(!Q.empty())
        Q.pop();
}

int main(){
    bool res;
    char flag='y';
    while(flag=='Y'||flag=='y'){
        clear_queue();
        init();
        res=init_check();
        if(res){
            int cnt=0;
            if(BFS(cnt)!=-1)
                printf("该八数码问题最少需要%d步才可到达目标状态\n",cnt);
            else
                printf("该八数码在规定1000步内无解\n");
        }
        else printf("该八数码无解,因为初始状态与目标状态奇偶排列不同\n");
        printf("是继续否进行测试？[Y/y]or[N/n]\n");
        scanf(" %c",&flag);
    }
    return 0;
}
/*一个状态表示成一维的形式，求出除0之外所有数字的逆序数之和，也就是每个数字前面比它大的数字的个数的和，称为这个状态的逆序。
若两个状态的逆序奇偶性相同，则可相互到达，否则不可相互到达。*/
