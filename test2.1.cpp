#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LinkNode
{
	ElemType data;
	struct LinkNode *next;
}LinkNode,*L;//声明结构体变量 LinkNode和指针变量L; 
int CreateList(L &list,ElemType a[],int n)//采用尾插法创建链表 
{
	L s,r;
	list=(L)malloc(sizeof(LinkNode));
	r=list;
	for(int i=0;i<n;i++){
		s=(L)malloc(sizeof(LinkNode));
		s->data=a[i];  
		r->next=s;
		r=s; 
	}
	r->next=NULL;
}
void printList(L list)//显示链表 
{
	L p=list->next;
	while(p)
	{
		printf("%d,",p->data);
		p=p->next;
	}
	printf("\n");
}
void Intersection(L &la,L &lb,L &lc)//将交集保存在la链表中
{
	L p=la->next,q=lb->next,out,tempL;  
	lc=tempL=la;
	while(p && q)
	{
		if(p->data==q->data)
		{
			tempL->next=p;
			tempL=p;
			p=p->next;
			q=q->next;
		}
		else if(p->data < q->data)
			p=p->next;
		else
			q=q->next;
	}
	tempL->next=NULL;
	while(p)
	{
		out=p;
		p=p->next;
		delete out;
	}
	while(q)
	{
		out=q;
		q=q->next;
		delete out;
	}
	delete lb;
}
int main()
{
	L la,lb,lc;
	ElemType num;
	int count=0,flag;
	printf("la链表放入1，2，3，4元素");
	int a[]={1,2,3,4}; 
	CreateList(la,a,4);
	printf("\nla链表:");
	printList(la);
	
	printf("lb链表放入3,4,5,6元素");
	int b[]={3,4,5,6}; 
	CreateList(lb,b,4);
	printf("\nlb链表:");
	printList(lb);
	Intersection(la,lb,lc);
	printf("\n求交集后的la链表:");
	printList(la);
	return 0;
}

