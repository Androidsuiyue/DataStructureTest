#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=30;
const int maxm=500;
int n;//��Ч��ĸ��
int vis[maxn];//�Ƿ����
int ans[maxn];//������
int cnt;//��ǰdfs����
bool mark[maxn];//��ǵ�ǰ��ĸ�����ڱ�����
int gragh[6][6] = {
	{0,1,0,0,0,0},
	{0,0,1,0,0,0},
	{0,0,0,1,0,0},
	{0,0,0,0,0,0},
	{0,1,0,0,0,1},
	{0,0,0,1,0,0},};
bool ok(int i,int cnt)//�����ans[0,cnt-1]������һ����Ӧ��i����ų��ֵ���ĸ,��ô����false
{
    for(int j=0;j<cnt;j++)
        if(gragh[i][ans[j]]) return false;
    return true;
}
void dfs(int cnt)
{
    if(cnt==n)
    {
        for(int i=0;i<n;i++)
            printf("%d",ans[i]);
        printf("\n");
    }
    else { 
		for(int i=0;i<6;i++){ 
			if(mark[i]&&!vis[i]&&ok(i,cnt)){
        		vis[i]=1;
        		ans[cnt]=i;
        		dfs(cnt+1);
        		vis[i]=0;
    		}
    	} 
    } 
}
int main()
{
    n=7;
    memset(mark,0,sizeof(mark));
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)
        mark[i]=true;
    dfs(0);//��ʾ��ǰ���ڹ����0��λ��
    return 0;
}

