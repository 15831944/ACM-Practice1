#include<cstdio>//���͵����ֵ��С������
int main(){
	int a[10001], T, n, m,maxn,sum;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		sum = 0, maxn = -1;
		for (int i = 0; i < n; i++){
			scanf("%d", a + i);
			sum += a[i];
			if (a[i]>maxn)
				maxn = a[i];
		}
			int mid,every_eaten,cnt;
			while (maxn < sum){//�����ֵ���ܺͽ��ж���
				every_eaten = 0, cnt = 0;
				mid = (maxn + sum) / 2;
				for (int i = 0; i < n;i++)
				if (every_eaten + a[i] <= mid)//�����midС,������ۼӱ���ɿ���
					every_eaten += a[i];
				else{//�������mid�����׼�������Ϊÿ����ɿ�����һ����Сֵ
					cnt++;
					every_eaten = a[i];//���Ұѵ��³���mid��a[i]��Ϊ����һ��Ҫ�Ե�
				}
				cnt++;//�Ѳ����������һ��Ҳ��Ϊһ����ɿ�������
				if (cnt <= m)//�������С�ڹ涨������˵��,ÿ��Ե��ɿ�������
					sum = mid;
				else
					maxn = mid+1;//ÿ��Ե��ɿ�����С
			}
			printf("%d\n", sum);
	}
	return 0;
}
