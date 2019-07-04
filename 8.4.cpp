#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#include<malloc.h>
#define MAXV 20
#define INF 32767
typedef int Vertex;
typedef struct ANode{
	int adjvex;
	struct ANode *nextarc;
	int weight; 
}ArcNode;
typedef struct{
	Vertex data;
	int count;
	ArcNode *firstarc;
}VNode;
typedef struct{
	VNode adjlist[MAXV];
	int n,e; 
}AdjGraph; 

void GreateAdj(AdjGraph *&G,int A[MAXV][MAXV],int n,int e){

	int i,j;ArcNode *p;

	G=(AdjGraph * )malloc(sizeof(AdjGraph));
	for(i=0;i<n;i++){
			G->adjlist[i].firstarc=NULL;
	}
	for(i=0;i<n;i++){
		for(j=n-1;j>=0;j--){
	
			if(A[i][j]!=0&&A[i][j]!=INF){
				p=(ArcNode * )malloc(sizeof(ArcNode));
				p->adjvex=j;
				p->weight=A[i][j];
				p->nextarc=G->adjlist[i].firstarc;
				G->adjlist[i].firstarc=p;
			}
		}
	}
	G->n=n;G->e=n;
}
void DispAdj(AdjGraph *G)//����ڽӱ�G
{
	int i;
	ArcNode *p;
	for (i=0;i<G->n;i++)
	{
		p=G->adjlist[i].firstarc;
		printf("%3d: ",i);
	while (p!=NULL)
	{
		printf("%3d[%d]��",p->adjvex,p->weight);
		p=p->nextarc;
	}
		printf("��\n");
}
}


void ToSort(AdjGraph *G){
	int i,j;
	int St[MAXV],top=-1;
	ArcNode *p;
	for(i=0;i<G->n;i++){
		G->adjlist[i].count=0;
	}
	for(i=0;i<G->n;i++){
		p=G->adjlist[i].firstarc;
		while(p!=NULL){
			G->adjlist[p->adjvex].count++;
			p=p->nextarc;
		}		 
	}
	for(i=0;i<G->n;i++){
		if(G->adjlist[i].count==0){
			top++;
			St[top]=i; 
		}
	}
	while(top>-1){
		i=St[top];
		top--;
		printf("%d",i);
		p=G->adjlist[i].firstarc;
		while(p!=NULL){
			j=p->adjvex;
			G->adjlist[j].count--;
			if(G->adjlist[j].count==0){
				top++;
				St[top]=j;
			}
			p=p->nextarc;
 		}
	}
}


void dfs(int cnt)
{
    if(cnt==n)
    {
        for(int i=0;i<n;i++)
            printf("%c",ans[i]+'a');
        printf("\n");
    }
    else for(int i=0;i<26;i++)if(mark[i]&&!vis[i]&&ok(i,cnt))
    {
        vis[i]=1;
        ans[cnt]=i;
        dfs(cnt+1);
        vis[i]=0;
    }
}

bool ok(AdjGraph *G, int i,int cnt)//�����ans[0,cnt-1]������һ����Ӧ��i����ų��ֵ���ĸ,��ô����false
{
    for(int j=0;j<cnt;j++)
        if(gragh[i][ans[j]]) return false;
    return true;
}


int main(){
	AdjGraph *G;
	
	int n;//��Ч��ĸ��
int vis[maxn];//�Ƿ����
int ans[maxn];//������
int cnt;//��ǰdfs����
bool mark[maxn];//��ǵ�ǰ��ĸ�����ڱ�����
	
	int A[MAXV][MAXV]={
	{0,0,0,1,0,1,0},
	{0,0,1,0,0,0,0},
	{0,0,0,1,1,0,0},
	{0,0,0,0,1,1,0},
	{0,0,0,0,0,0,1},
	{0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0}};
	int n=7, e=9;
	GreateAdj(G,A,n,e);//�������̡̳���ͼ8.1(a)���ڽӾ���
	printf("ͼG���ڽӾ���:\n");
	DispAdj(G);//����ڽӾ���g
	ToSort(G);
	return 0;
} 

