#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
struct node{
    int l,r,cnt;
    node(){
        l=r=-1;
        cnt=0;
    }
}huff[maxn<<3];
int main(){
    int n,m,cnt=0,index,res[maxn];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        index=0;//cnt并没有重新赋值,一直在增加
        while(m){//按照哈夫曼编码的那种形式去模拟,记录每个数的二进制位的路径,0作为上一位二进制的左子树,1作为上一位二进制位的右子树
            if(m&1){
                if(huff[index].r==-1){//此位的路径上还没有记录
                    huff[index].r=++cnt;;//记录它的下一位的数组下标,这里是按照层序遍历,队列先进先出那种形式
                    index=cnt;//index当前标志记录下一位下标
                }
                else{//若此位相等
                    index=huff[index].r;//index的下一位就按当前的路径去记载,只要相等就一直增加这个值，当然这个值不一定会用到，如果恰好m等于这个路径上的数就会用到
                    huff[index].cnt++;//每次增加的是它的下一位的值,因为res[i]要记录这个下标,同时index又要变换,所以只好让cnt的增加提前一位方便res记录
                }
            }
            else{
                if(huff[index].l==-1){//同理
                    huff[index].l=++cnt;
                    index=cnt;
                }
                else{
                    index=huff[index].l;
                    huff[index].cnt++;
                }
            }
            m>>=1;
        }
        res[i]=index;
    }
    for(int i=0;i<n;i++)
        printf("%d\n",huff[res[i]].cnt);
    return 0;
}
