#include<cstdio>
#define N 50010
//理解看这个代码理解就好，不要再去看别人博客了
struct{
    int l, r;
    int sum;
}seg_tree[N<<2];
void Pushup(int l,int r,int rt){
    seg_tree[rt].sum = seg_tree[l].sum + seg_tree[r].sum;//根节点的值代表区间(l,r)的和
}
void Build_segtree(int l, int r, int rt){//建立线段树
    seg_tree[rt].l = l, seg_tree[rt].r = r;
    if (l == r){//直到划分到叶子结点将待输入数据存入
        scanf("%d", &seg_tree[rt].sum);
        return;
    }
    int mid = (l + r) >> 1;//找到下一个区间二分的中点
    Build_segtree(l, mid, rt<<1);//左区间
    Build_segtree(mid + 1, r, rt<<1 | 1);//右区间
    Pushup(rt << 1, rt << 1 | 1, rt);//合并区间的和
}
void update(int pos, int change,int rt){//更新线段树
    if (seg_tree[rt].l==seg_tree[rt].r){//从叶子结点开始更新
        seg_tree[rt].sum += change;
        return;
    }
    int mid = (seg_tree[rt].l + seg_tree[rt].r) >> 1;
    if (pos <= mid) update(pos,  change,rt<<1);
    else update(pos, change,rt<<1|1);
    Pushup(rt << 1, rt << 1 | 1, rt);//再依次更新父结点
}
int query(int cur_l, int cur_r, int rt){//查询任意区间的和
    if (cur_l <= seg_tree[rt].l && seg_tree[rt].r <= cur_r){//当现在区间被待查找区间包含时
        return seg_tree[rt].sum;
    }
    int mid = (seg_tree[rt].l + seg_tree[rt].r) >> 1;
    if (cur_r <= mid) return query(cur_l, cur_r, rt << 1);//待查找区间在二分中点左边,递归左子树
    else if (cur_l > mid) return query(cur_l, cur_r, rt << 1 | 1);//待查找区间在二分中点右边,递归右子树
    else return query(cur_l, cur_r, rt << 1) + query(cur_l, cur_r, rt << 1 | 1);//二分中点在待查找区间内,即左右子树都被包含在待查找区间内
}
int main(){
    int T,n,pos,change,cur_l,cur_r,res,cnt=1;
    char cmd[6];
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        Build_segtree(1, n, 1);
        printf("Case %d:\n", cnt);
        cnt++;
        while (scanf("%s",cmd)&&*cmd!='E'){
            getchar();
            switch (*cmd){
            case 'A':
                scanf("%d%d", &pos, &change);
                update(pos, change, 1); break;
            case 'S':
                scanf("%d%d", &pos, &change);
                update(pos, -change, 1); break;
            case 'Q':
                scanf("%d%d", &cur_l, &cur_r);
                printf("%d\n", query(cur_l, cur_r, 1));
            }
        }
    }
    return 0;
}
