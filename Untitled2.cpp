#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=30;
const int maxm=500;
int n;//有效字母数
int vis[maxn];//是否访问
int ans[maxn];//答案数组
int cnt;//当前dfs计数
bool mark[maxn];//标记当前字母出现在变量中
int gragh[7][7] = {
		{0,0,0,1,0,1,0},
	{0,0,1,0,0,0,0},
	{0,0,0,1,1,0,0},
	{0,0,0,0,1,1,0},
	{0,0,0,0,0,0,1},
	{0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0}
		  };//g
bool ok(int i,int cnt)//如果在ans[0,cnt-1]出现了一个本应在i后面才出现的字母,那么返回false
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
    else 
	for(int i=0;i<n;i++)
	if(mark[i]&&!vis[i]&&ok(i,cnt))
    {
        vis[i]=1;
        ans[cnt]=i;
        dfs(cnt+1);
        vis[i]=0;
    }
}
int main()
{
    int n=7;//有效字母数
    int e=9;//边数 
	int vis[maxn];//是否访问
	int ans[maxn];//答案数组
	int cnt;//当前dfs计数
	bool mark[maxn];//标记当前字母出现在变量中
	int A[MAXV][MAXV]={
	{0,0,0,1,0,1,0},
	{0,0,1,0,0,0,0},
	{0,0,0,1,1,0,0},
	{0,0,0,0,1,1,0},
	{0,0,0,0,0,0,1},
	{0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0}};	
    memset(mark,0,sizeof(mark));
    memset(vis,0,sizeof(vis));
    AdjGraph *G;
    int n=7, e=9;
	GreateAdj(G,A,n,e);
    
    
    
    for(int i=0;i<n;i++)
        mark[i]=true;
    dfs(0);//表示当前正在构造第0个位置
    return 0;
}

