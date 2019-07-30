#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct ticket{
    int start;
    int end0;
    int per_num;
    int val;
    bool operator < (const ticket &a)const{
        if(start==a.start)
            return end0<a.end0;
        return start<a.start;
    }
}ticket0[25];
//station用来模拟 公交车行驶路上车上的实时人数
int station[9],capacity,ticket_num,max_money;

void DFS(int n,int money){
    //printf("%d\n",money);
    if(money>max_money)
        max_money=money;
    for(int i=n;i<=ticket_num;i++){
        if(max_money>money+ticket0[i].val)//剪枝 如果当前的利润+上后面所有订单的利润都没有之前获得的多，就不进行深度遍历
            return;
        if(station[ticket0[i].start]+ticket0[i].per_num<=capacity){
            for(int j=ticket0[i].start;j<ticket0[i].end0;j++)
                station[j]+=ticket0[i].per_num;
            //printf("n=%d i=%d %d %d\n",n,i,money,ticket0[i].per_num*(ticket0[i].end0-ticket0[i].start));
            DFS(i+1,money+ticket0[i].per_num*(ticket0[i].end0-ticket0[i].start));//注意这里是i+1,因为模拟时公交车永远都在通向终点站
            for(int j=ticket0[i].start;j<ticket0[i].end0;j++)
                station[j]-=ticket0[i].per_num;
        }
    }
}

int main(){
    int city_num;
    while(scanf("%d%d%d",&capacity,&city_num,&ticket_num)&&capacity||city_num||ticket_num){
        memset(station,0,4*(city_num+1));
        max_money=-1;
        for(int i=1;i<=ticket_num;i++){
            scanf("%d%d%d",&ticket0[i].start,&ticket0[i].end0,&ticket0[i].per_num);
        }
        sort(ticket0+1,ticket0+1+ticket_num);
        int sum=0;
        for(int i=ticket_num;i>=1;i--){//这里是为了剪枝
            sum+=ticket0[i].per_num*(ticket0[i].end0-ticket0[i].start);
            ticket0[i].val=sum;
        }
        DFS(1,0);
        printf("%d\n",max_money);
    }
    return 0;
}
