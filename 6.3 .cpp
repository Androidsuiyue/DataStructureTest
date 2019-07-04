#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char ElemType;
typedef struct{
	ElemType data[12];
	int top;
}SqStack ,*S;
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

int main(){
	S s1;
	ElemType e;
	InitStack(s1);
	char str[30];
	int i=0,j=0,len=0;
	printf("ÇëÊäÈë×Ö·û´® \n");
	gets(str);
	len=strlen(str);
	char zimu;
	printf("\n");
	for(int j=0;j<len;j++){
		//×ÖÄ¸½øÕ»
		if(str[j]==' '){		
			while(!StackEmpty(s1)){
				Pop(s1,e);
				printf("%c",e);
			}
			printf(" ");
		}else{
			e=str[j];
			Push(s1,e);
		} 
	}
	while(!StackEmpty(s1)){
		Pop(s1,e);
		printf("%c",e);
	}	
	return 0;	
}




