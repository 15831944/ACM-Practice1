#include <stdio.h>
#define N 32002
//注意树状数组的结构永远是恒定的就是那固定的一种结构
//这里是只保留x的二进制位最低位的1 比如对于10 1010 -10 为按位取反+1结果0101+1=0110   1010&0110=0010结果就是只保留最低位的1
#define LOWBIT(x) ((x)&(-(x)))

int a[N],num[N];
//构造这颗子树时也是使用更新，而且对于区间长度为n时，所对应的树状数组中子树的个数最大为log (n),因此循环的次数最大也就为log(n)
void update(int *a,int p,int d){
    //p+=LOWBIT(p) 这里是找到p的父子树结点 依次更新父子树结点
	for(; p&&p<N; p+=LOWBIT(p)) a[p]+=d;
	//这里在构造这个树桩数组时，对于树状数组中的每个结点而言它所保存的累积和并不一定就包括前面所有实际数组元素之和,有可能也只是某一课子树所累加的个别元素的和,真正在求解区间和时，应该是通过x-lowbit(x)连续求解多棵子树的累积和
}
//求解区间和事实上这个没有绝对的时间界,取决于所求的区间是多大，某一个好的区间序列，有可能只需要o(1)就可求解出来，就是这个树状数组中的代号为二进制只有一个1，这个树状数组是前面所有子树的父节点,最坏的情况是区间长度最大为8时，求解前7个元素的累积和，连续求解了3棵子树，最坏循环3次
int sum(int *a,int p){
	int s = 0;
	// p-=LOWBIT(p) 这里是求解p以前的数组和,有可能是由多棵子树所构成的 eg:求解区间0~7的元素的和累积和 对于 7 0111 7-lowbit(7)=0110(6) 结果是树状数组中代号6的那颗子树的累积和 而6-lowbit(6)=0100(4) 得到结果为 为树状数组中代号为4的那颗子树
	for(; p; p-=LOWBIT(p)) s += a[p];//直到减到 像 2 4 8 16这样只有一个二进制1的 相减后结果就为0,因为这些代号的子树就已经累计和包括了前面所有的元素
	return s;
}

int main(){
	int n,i,x,y;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&x,&y);
		num[sum(a,x+1)]++;
		update(a,x+1,1);
	}
	for(i=0;i<n;i++) printf("%d\n",num[i]);
	return 0;
}

