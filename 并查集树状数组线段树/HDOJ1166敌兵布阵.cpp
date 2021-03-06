#include<cstdio>
#define N 50010
struct{
    int l, r;
    int sum;
}seg_tree[N<<2];
int a[N];
void Pushup(int l,int r,int rt){
    seg_tree[rt].sum = seg_tree[l].sum + seg_tree[r].sum;
}
void Build_segtree(int l, int r, int rt){
    seg_tree[rt].l = l, seg_tree[rt].r = r;
    if (l == r){
        seg_tree[rt].sum=a[l];
        return;
    }
    int mid = (l + r) >> 1;
    Build_segtree(l, mid, rt<<1);
    Build_segtree(mid + 1, r, rt<<1 | 1);
    Pushup(rt << 1, rt << 1 | 1, rt);
}
void update(int pos, int change,int rt){
    if (seg_tree[rt].l==seg_tree[rt].r){
        seg_tree[rt].sum += change;
        return;
    }
    int mid = (seg_tree[rt].l + seg_tree[rt].r) >> 1;
    if (pos <= mid) update(pos,  change,rt<<1);
    else update(pos, change,rt<<1|1);
    Pushup(rt << 1, rt << 1 | 1, rt);
}
int query(int cur_l, int cur_r, int rt){
    if (cur_l <= seg_tree[rt].l && seg_tree[rt].r <= cur_r){
        return seg_tree[rt].sum;
    }
    int mid = (seg_tree[rt].l + seg_tree[rt].r) >> 1;
    if (cur_r <= mid) return query(cur_l, cur_r, rt << 1);
    else if (cur_l > mid) return query(cur_l, cur_r, rt << 1 | 1);
    else return query(cur_l, cur_r, rt << 1) + query(cur_l, cur_r, rt << 1 | 1);
}
int main(){
    int T,n,pos,change,cur_l,cur_r,res,cnt=1;
    char cmd[6];
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d",a+i);
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
