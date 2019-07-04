#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef int ElemType;
typedef struct BTNode{
	ElemType data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}*B;
//创建二叉树
void CreateBTree(B &b,char *str){
	BTNode *St[100],*p;
	int top =-1,k,j=0;
	char ch;
	b=NULL;
	ch=str[j];
	while(ch!='\0'){
		switch(ch){
			case '(':
				top++;
				St[top]=p;
				k=1;
				break;	
			case ')':
				top--;
				break;
			case ',':
				k=2;
				break;
			default:
				p=(B)malloc(sizeof(BTNode));
				int i=ch-'0';
				p->data=i;				
				p->lchild=p->rchild=NULL;
				if(b==NULL){
					b=p;
				}else{
					switch(k)
					{
						case 1:
							St[top]->lchild=p;
							break;
						case 2:
							St[top]->rchild=p;
							break;
					}
				}
		}
		j++;
		ch=str[j];
	}
}
//销毁二叉树
void DestroyBTree(B &b){
	if(b!=NULL){
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b); 
	} 
} 
//查找结点
B FindNode(B b,ElemType x){
	B p;
	if(b==NULL){
		return NULL;
	}else if(b->data==x){
		return b;
	}else{
		p=FindNode(b->lchild,x);
		if(p!=NULL){
			return p;
		}else{
			return FindNode(b->rchild,x);
		}
	}
	
}
//找左右孩子结点
B LchildNode(B p){
	return p->lchild;
} 
B RchildNode(B p){
	return p->rchild;
}
//二叉树的高度 
int BTHeight(B b){
	int lchildh,rchildh;
	if(b==NULL){
		return(0);
	}else{
		lchildh=BTHeight(b->lchild);
		rchildh=BTHeight(b->rchild);
		return(lchildh>rchildh)?(lchildh+1):(rchildh+1);
	}
}
void DispBTree(B b){
	if(b!=NULL){
		printf("%d",b->data);
		if(b->lchild!=NULL||b->rchild!=NULL){
			printf("(");
			DispBTree(b->lchild);
			if(b->rchild!=NULL){
				printf(",");
			}
			DispBTree(b->rchild);
			printf(")");
		}
	}	
}
//先序遍历
void PreOrder(B b){
	if(b!=NULL){
		printf("%d ",b->data);
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}
//中序遍历
void InOrder(B b){
	if(b!=NULL){
		InOrder(b->lchild);
		printf("%d ",b->data);
		InOrder(b->rchild);
	}
}
//后序遍历 
void PostOrder(B b){
	if(b!=NULL){
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		printf("%d ",b->data);
	}
}
//输出所有叶子节点
void DisLeaf(B b){
	if(b!=NULL){
		if(b->lchild==NULL&&b->rchild==NULL){
			printf("%d ",b->data);
		}
		DisLeaf(b->lchild);
		DisLeaf(b->rchild); 
	}
} 

//查找二叉树中的最大、最小值，结点写出它们所在的层数
//min为二叉树的根节点，deepNumber层数置初值1 
void MinLevel(B b,ElemType &min,ElemType &mindeepNumber,int h){
	if (b==NULL){
		return; 
	}else{
		if(b->data<=min){//这层中的树比min值小，赋值 
		int i=b->data;
	 		min=i;
	 		mindeepNumber=h;	
		}	
	 	MinLevel(b->lchild,min,mindeepNumber,h+1);
	 	MinLevel(b->rchild,min,mindeepNumber,h+1);		
	}
}

//查找二叉树中的最大、最小值，结点写出它们所在的层数
//max为二叉树的根节点，deepNumber层数置初值1 
void MaxLevel(B b,ElemType &max,ElemType &maxdeepNumber,int h){
	int l;
	if (b==NULL){
		return; 
	}else{
		if(b->data>=max){//这层中的树比man值大，赋值 
		int i=b->data;
	 		max=i;
	 		maxdeepNumber=h;	
		}	
	 	MaxLevel(b->lchild,max,maxdeepNumber,h+1);
	 	MaxLevel(b->rchild,max,maxdeepNumber,h+1);		
	}
}
int main(){
	B b;
	int h=1;
	ElemType min,mindeepNumber,max,maxdeepNumber;
	CreateBTree(b,"8(6(3(,2),5(4,7))");
	printf("b:");
	DispBTree(b);
	printf("\n");
	printf("先序遍历:");
	PreOrder(b);
	printf("\n");
	printf("中序遍历:");
	InOrder(b);
	printf("\n");
	printf("后序遍历:");
	PostOrder(b);
	printf("\n");
	printf("高度:");
	printf("%d",BTHeight(b));
	printf("\n");
	printf("所有叶子节点:");
	DisLeaf(b);
	min=b->data;
	max=b->data;
	MinLevel(b,min,mindeepNumber,h);
	h=1;
	MaxLevel(b,max,maxdeepNumber,h);
	printf("\n最小值所在层数  %d",mindeepNumber);
	printf("\n最小值 %d",min);
	printf("\n最大值所在层数  %d",maxdeepNumber);
	printf("\n最大值 %d",max);
		
}



