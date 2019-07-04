#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct{
	ElemType data[5];
	int top;
}SqStack,*S;

void InitStack(S &s){   //初始化栈 
	s=(S)malloc(sizeof(SqStack));
	s->top=-1;
}
bool StackEmpty(S &s){  //判断栈是否为空 
	return(s->top==-1);
}
bool Push(S &s,ElemType e){ //进栈 
	if(s->top==5-1){
		return false;
	}
	s->top++;                //栈顶指针增1 
	s->data[s->top]=e;      //元素e放在栈顶指针chu 
	return true; 
}

bool Pop(S &s,ElemType &e){ //出栈 通过取值符得到 
	if(s->top==-1){
		return false;
	}
	e=s->data[s->top];
	s->top--;
	return true;
} 

bool GetTop(S s,ElemType &e){  //取栈顶元素 
	if(s->top==-1){
		return false;
	}
	e=s->data[s->top];
	return true;
}
//第一数组表示进栈顺序，第二个数组表示出栈顺序，size表示数组长度，根据进栈和出栈返回一个栈，栈为空表示出栈顺序正确。
S CheckStackOrder(int a[],int b[],int size) {  
	ElemType e;
	S s;
	bool flag;
	int temp=0, i=0,z=0;
	InitStack(s);
	for(i=0;i<size;i++ ){
		temp=b[i];
		printf("%d \n",temp);
		//从栈顶取出一个元素  
		flag=GetTop(s,e);
		while(e!=temp&&z<size){	//栈顶的元素和出栈的元素比较	
			//进栈一个元素
			flag= Push(s,a[z]);
			if(flag){
				printf("成功进栈 %d \n",a[z]);z++;
			}else{
				printf("失败 \n");	
			}
			//从栈顶取出一个元素 
	 		flag=GetTop(s,e); 
			printf("取出栈顶 %d  \n",e);	
       }
		if(e==temp){        //相等把栈顶的元素出栈 
			flag=Pop(s,e);
			printf("出栈 %d \n",e);	
		} 	
	}
	return s;	

}
int main(){
	ElemType e;
	S s;
	bool flag;
	int a[5]={1,2,3,4,5};//定义进栈顺序 
	int b[5]={3,4,5,2,1};//需要判断的出栈顺序 
	s=CheckStackOrder(a,b,5);
	//判断是否为空 
	flag=StackEmpty(s);
	if(flag){
		printf("空，顺序正确");
	}else{
		printf("不空哦，顺序不正确");	
	}
}






