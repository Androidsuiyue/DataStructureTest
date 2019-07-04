#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int ElemType;
typedef struct BTNode{
	ElemType data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}*B;
void DispBTree(B b){
	if(b!=NULL){
		printf("%c",b->data);
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
B CreateBT(char *pre,char *in,int n,int &flag){
	B b;
	char *p;
	int k;
	if(n<=0){
		return NULL;
	}
	b=(B)malloc(sizeof(BTNode));
	b->data=*pre;
	for(p=in;p<in+n;p++){
		if(*p==*pre){
			break;
		}
	}
	k=p-in;
	if(n<=k){
		flag=0;
		return NULL;
	}else{
		printf("中序遍历%d  当前结点%d\n",k,n);
		b->lchild=CreateBT(pre+1,in,k,flag);
		b->rchild=CreateBT(pre+k+1,p+1,n-k-1,flag);
		return b; 
	}	
}
int main(){
	B b;
	int h=1;
	char pre[]="DGBAECF";
	char in[]="FAAECDB";
    do{
	printf("先序遍历\n");
	scanf("%s",&pre);
	int preLength=strlen(pre);
	printf("中序遍历\n");
   	scanf("%s",&in);
    int inLength=strlen(in);
    if(preLength!=inLength){
    	printf("输入错误\n"); 	
	}else{
		int flag=1;
     	b=CreateBT(pre,in,preLength,flag);
    	if(flag==1){
    		printf("b:");
			DispBTree(b);
			printf("\n");
		}else{
			printf("无法构建\n");
		}
	}
	printf("1 再来  2退出\n");
	scanf("%d",&h);
	}while(h==1);			
}



