D Substring http://172.22.112.249/exam/index.php/problem/exam_read/id/1363/exam_id/161

˼·��
������һ�¸��Ӷ�O(T*|S|log|S|26)�����������ڳ���̫���ˣ�TLE��
����һ��Ӧ�ÿ��԰�26���ַ�ѹ��һ�£�˵�����ܹ���
л�������Ӧ�������Ž⣬���Ӷ�O(T|S|*26)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int vis[256];
int main(){
    char s[2005];
    while(scanf("%s",s+1)!=EOF){
        memset(vis,0,sizeof vis);
        int cnt=0;
        int len=strlen(s+1);
        int ans=0x3f3f3f3f;
        for(int i=1;i<=len;i++){
            if(vis[s[i]]==0){
                cnt++;
            } vis[s[i]]=i;
            if(cnt==26){
                int dis=INT_MIN;
                for(int j='a';j<='z';j++){
                    dis=max(dis , i-vis[j]+1);
                }
                ans = min( ans , dis);
            }
        }
        if(cnt<26)ans=0;
        cout<<ans<<endl;
    }
    return 0;
}
--------------------- 
���ߣ�mMingfunnyTree 
��Դ��CSDN 
ԭ�ģ�https://blog.csdn.net/mMingfunnyTree/article/details/80696847 
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�