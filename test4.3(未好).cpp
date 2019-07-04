#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct {
	ElemType data[12];
	int front;
	int rear;
}SqQueue,*Q;
typedef struct{
	ElemType data[12];
	int top;
}SqStack ,*S;
void InitQueur(Q &qu){
	qu=(Q)malloc(sizeof(SqQueue));
	qu->front=qu->rear=-1;
}
void DestroyQueue(Q &qu){
	free(qu);
}
bool QueueEmpty(Q qu){
	return (qu->front==qu->rear);
}
bool enQueue(Q &qu,ElemType e){
	if((qu->rear+1)%12==qu->front){
		return false;
	}
	qu->rear=(qu->rear+1)%12;
	qu->data[qu->rear]=e;
	return true;
}
bool deQueue(Q &qu,ElemType &e){
	if(qu->rear==qu->front){
		return false;
	}
	qu->front=(qu->front+1)%12;
	e=qu->data[qu->front];
	return true;
}
void InitStack(S &s){
	s=(S)malloc(sizeof(SqStack));
	s->top=-1;
}
void DestroyStack(S &s){
	free(s);
}
bool StackEmpty(S s){
	return(s->top==-1);
}
bool Push(S &s,ElemType e){
	if(s->top==12-1){
		return false;
	}
	s->top++;
	s->data[s->top]=e;
	return true;
}
bool Pop(S &s,ElemType &e){
	if(s->top==-1){
		return false;
	}
	e=s->data[s->top];
	s->top--;
	return true;
}
bool GetTop(S &s,ElemType &e){
	if(s->top==-1){
		return false;
	}
	e=s->data[s->top];
	return true;
}
int main(){
	Q q1,q2;
	S s1;
	ElemType e=0;
	bool flag=false;
	int shuliang=0,paimian=0,i=0;
	int  a1[6]={2,4,1,2,5,6};
	int a2[6]={3,1,3,5,6,4};
	int temp[7]={0,0,0,0,0,0,0};
	InitQueur(q1);
	InitQueur(q2);
	InitStack(s1);
	//ÿ�����ϵ��Ʒ������ 
	for(i=0;i<6;i++){
		enQueue(q1,a1[i]);	
		enQueue(q2,a2[i]);
	}
	do{ 
		//����a1�ȳ���
		deQueue(q1,e);
		//�ƽ�ջ
		Push(s1,e);
		printf("q1���� %d \n",e);
		paimian=e; 
		shuliang =temp[paimian];//0����1 
		//�ж�ջ��û����ͬ����
		if(shuliang==1){
			printf("q1�ͷ� %d \n",paimian);
			//˵���Ѿ����ƣ��ͷ�
				//��ջ
				Pop(s1,e);
				//����q1��
				enQueue(q1,e);
				//�±�����
				temp[e]=0; 
			do{
				//��ջ
				Pop(s1,e);
				//����q1��
				enQueue(q1,e);
				//�±�����
				temp[e]=0;
			}while(paimian!=e);//�����Ⱦ��˳�
			 		
		}else{
			//˵��û���ƣ�
			temp[paimian]=1; 
		}
		//�Ƿ������
		flag=QueueEmpty(q1);
		//q2�� 
		if(flag==false){
			//q2�� 
			deQueue(q2,e);			
			//�ƽ�ջ
			Push(s1,e);
			printf("q2���� %d \n",e);
			//��� ջ��û����ͬ����
	 		paimian=e;
	 		shuliang =temp[paimian];//0����1 
			if(shuliang==1){
				printf("q2�ͷ� %d \n",paimian);
				//˵���Ѿ����ƣ��ͷ� 
				//��ջ
					Pop(s1,e);
					//����q1��
					enQueue(q2,e);
					printf("ȡ�� %d \n",e);
					//�±�����
					temp[e]=0;
				do{
					//��ջ
					Pop(s1,e);
					//����q1��
					enQueue(q2,e);
					printf("ȡ�� %d \n",e);
					//�±�����
					temp[e]=0; 
				}while(paimian!=e);//�����Ⱦ��˳�
				
				temp[paimian]=0; 
				
			}else{
				//˵��û���ƣ�
				temp[paimian]=1; 
			}
			//�Ƿ������
			flag=QueueEmpty(q2);
			if(flag==true){
				printf("q2ʤ������");	
				break;
			}
		}else{
			printf("q1ʤ������"); 
			break;
		}
	}while(flag==false);	
	printf("\n");
	printf("q1����");
	while(!QueueEmpty(q1)){
		deQueue(q1,e);
		printf(" %d  ",e);
	}printf("\n");
	printf("q2����");
	while(!QueueEmpty(q2)){
		deQueue(q2,e);
		printf(" %d  ",e);
	}
	printf("\n");
	printf("���ϵ���");
	while(!StackEmpty(s1)){
		Pop(s1,e);
		printf(" %d  ",e);
	}	 
}


