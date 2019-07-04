#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct{
	ElemType data[5];
	int top;
}SqStack,*S;

void InitStack(S &s){   //��ʼ��ջ 
	s=(S)malloc(sizeof(SqStack));
	s->top=-1;
}
bool StackEmpty(S &s){  //�ж�ջ�Ƿ�Ϊ�� 
	return(s->top==-1);
}
bool Push(S &s,ElemType e){ //��ջ 
	if(s->top==5-1){
		return false;
	}
	s->top++;                //ջ��ָ����1 
	s->data[s->top]=e;      //Ԫ��e����ջ��ָ��chu 
	return true; 
}

bool Pop(S &s,ElemType &e){ //��ջ ͨ��ȡֵ���õ� 
	if(s->top==-1){
		return false;
	}
	e=s->data[s->top];
	s->top--;
	return true;
} 

bool GetTop(S s,ElemType &e){  //ȡջ��Ԫ�� 
	if(s->top==-1){
		return false;
	}
	e=s->data[s->top];
	return true;
}
//��һ�����ʾ��ջ˳�򣬵ڶ��������ʾ��ջ˳��size��ʾ���鳤�ȣ����ݽ�ջ�ͳ�ջ����һ��ջ��ջΪ�ձ�ʾ��ջ˳����ȷ��
S CheckStackOrder(int a[],int b[],int size) {  
	ElemType e;
	S s;
	bool flag;
	int temp=0, i=0,z=0;
	InitStack(s);
	for(i=0;i<size;i++ ){
		temp=b[i];
		printf("%d \n",temp);
		//��ջ��ȡ��һ��Ԫ��  
		flag=GetTop(s,e);
		while(e!=temp&&z<size){	//ջ����Ԫ�غͳ�ջ��Ԫ�رȽ�	
			//��ջһ��Ԫ��
			flag= Push(s,a[z]);
			if(flag){
				printf("�ɹ���ջ %d \n",a[z]);z++;
			}else{
				printf("ʧ�� \n");	
			}
			//��ջ��ȡ��һ��Ԫ�� 
	 		flag=GetTop(s,e); 
			printf("ȡ��ջ�� %d  \n",e);	
       }
		if(e==temp){        //��Ȱ�ջ����Ԫ�س�ջ 
			flag=Pop(s,e);
			printf("��ջ %d \n",e);	
		} 	
	}
	return s;	

}
int main(){
	ElemType e;
	S s;
	bool flag;
	int a[5]={1,2,3,4,5};//�����ջ˳�� 
	int b[5]={3,4,5,2,1};//��Ҫ�жϵĳ�ջ˳�� 
	s=CheckStackOrder(a,b,5);
	//�ж��Ƿ�Ϊ�� 
	flag=StackEmpty(s);
	if(flag){
		printf("�գ�˳����ȷ");
	}else{
		printf("����Ŷ��˳����ȷ");	
	}
}






