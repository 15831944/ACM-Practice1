/*ע:
����Ϊʲô,x+n,x+2n�ܱ�ʾ���뱻�ԵĹ�ϵ?
��Ϊ��Ŀ��˵����n�ֶ�����Ϊ 1-n ʹ��x+n �Լ�x+2*n �� ���Ա�֤��Ӧ�ı�Ų�����1--n�ķ�Χ�ڣ�Ҳ�ͱ�֤����Ӱ�쵽�޹صĶ����ˡ�
��Ȼ Ҳ������ x+3n �Լ� x+4n����ʾ���뱻�ԡ���������������͵ÿ��ĸ����ˡ���*/
#include<cstdio>
int vertex[150010],N;

void init(){
    for(int i=1;i<=150009;i++)
        vertex[i]=i;
}

int find(int x){
    if(vertex[x]!=x)
        return vertex[x]=find(vertex[x]);
    else
        return x;
}

void union0(int x,int y){
    int u=find(x);
    int v=find(y);
    vertex[u]=v;
}

bool judge1(int x,int y){//�жϡ����������ͬ�ࡡ���Ƿ����滰
    if (x>N || y>N || x<=0 ||y<=0) return false;
    if(find(x+N)==find(y)||find(x+2*N)==find(y))//����������ԵĶ��������ͬ�ࡡ�򡡳ԣ��Ķ��������ͬ�࣬���أ����ٻ���
        return false;
    return true;
}

bool judge2(int x,int y){//�жϡ������ԣ������Ƿ����滰
    if (x>N || y>N || x<=0 ||y<=0 || x==y) return false;//���� ֻ���������� x==y ���Ҹо� ����,������ж�������return false�� ����0 N�����ı߽籾��Ҳ�����а�
    if(find(x)==find(y)||find(x+2*N)==find(y))//�������ͬ�࣬�򣬣���ԣ��Ķ�����ͬ�࣬�򷵻أ����Ǽٻ���
        return false;
    return true;
}

int main(){
    int K,D,x,y,ans=0;
    init();
    scanf("%d%d",&N,&K);
    while(K--){
        scanf("%d%d%d",&D,&x,&y);
        //�����Ŀ �����Ǽٶ�ǰ��˵�Ķ������ ��ȥ��Ժ���Ļ�����ʵҲ���Լٶ�����˵������� ȥ��ǰ��˵�Ļ������ٻ�����Ŀ�ǲ�����
        if(D==1){
            if(judge1(x,y)){
                //Ҫע��ͬʱ����������ȫ���غ�
                union0(x,y);//���������Եĺ����Ǳ��ԵĵĶ�����һ����ͨ����,��Щx+n x+2n���� ������Ĺ�ϵ�� ������������жϺ�������
                union0(x+N,y+N);
                union0(x+2*N,y+2*N);
            }
            else
                ans++;
        }
        else{
            if(judge2(x,y)){
                union0(x+N,y);//������ԵĶ�������
                union0(x+2*N,y+N);//���ԵĶ�����ԣ��Ķ�������
                union0(x,y+2*N);//����ԣ��Ķ�������
            }
            else
                ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
