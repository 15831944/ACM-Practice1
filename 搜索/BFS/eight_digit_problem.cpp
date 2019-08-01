#include<cstdio>
#include<queue>
using namespace std;

struct node{
    int checker_board[3][3];
    int mark_pos;
};
queue<node> Q;
node init_node,final_node;

//�����ʼ���̺�Ŀ�����̵�״̬
void init(){
    printf("�����ʼ���̵�״̬:\n");
   for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            scanf("%d", &init_node.checker_board[i][j]);
    init_node.mark_pos=-1;//��һ�λ�û�н����ƶ������Բ��ᵼ�»��˵�֮ǰ��״̬
    printf("����Ŀ�����̵�״̬:\n");
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

//�Գ�ʼ״̬��Ŀ��״̬����ż���н����ж�
bool init_check(){
    int res1=0,res2=0;
    for(int i=0;i<9;i++){
        res1+=cal(init_node,i);
        res2+=cal(final_node,i);
    }
    printf("��ʼ״̬��Ŀ��״̬��������Ϊ:res1=%d res2=%d\n",res1,res2);
    bool flag1=false,flag2=false;
    if(res1%2==0) flag1=true;
    if(res2%2==0) flag2=true;
    if(flag1 ^ flag2==0) return true;
    else return false;
}

//�ҳ��ո��λ��
void loction(node tmp,int &x,int &y){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            if(tmp.checker_board[i][j]==0){
                x=i,y=j;
                return;
            }
        }
}

//����Ƿ�ﵽ��Ŀ��״̬
bool check_state(node tmp){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(tmp.checker_board[i][j]!=final_node.checker_board[i][j])
                return false;
    return true;
}

//���ո����������ϡ��ҡ��½����ƶ�
void mobile_pos(node move_node){
    int x,y;
    node tmp;
    loction(move_node,x,y);
    int rollback = move_node.mark_pos;
    //mark_pos��0 1 2 3�ֱ�������� ���ҡ� ��
    if(x!=0&&rollback!= 1){//�ո�ֻҪ���ڵ�һ�о��������ƶ�
        tmp = move_node;
        tmp.checker_board[x][y]=tmp.checker_board[x-1][y];
        tmp.checker_board[x-1][y]=0;
        tmp.mark_pos=3;//��һ���ƶ����״̬ʱ�����������ƶ��������˵���ǰ״̬
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

//��ն���
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
                printf("�ð���������������Ҫ%d���ſɵ���Ŀ��״̬\n",cnt);
            else
                printf("�ð������ڹ涨1000�����޽�\n");
        }
        else printf("�ð������޽�,��Ϊ��ʼ״̬��Ŀ��״̬��ż���в�ͬ\n");
        printf("�Ǽ�������в��ԣ�[Y/y]or[N/n]\n");
        scanf(" %c",&flag);
    }
    return 0;
}
/*һ��״̬��ʾ��һά����ʽ�������0֮���������ֵ�������֮�ͣ�Ҳ����ÿ������ǰ�����������ֵĸ����ĺͣ���Ϊ���״̬������
������״̬��������ż����ͬ������໥������򲻿��໥���*/
