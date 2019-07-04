#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int i=0,j=0,
	LeftPart=0,RightPart=0,FoolNumber=0;
	char a[]={'(','(','(',')','(','(','B',')','(',')',')','(',')',')',')',')'};
	int b=strlen(a);
	for(i=0;i<b;i++){
		if('('==a[i]){
			LeftPart++;
			if(LeftPart<=RightPart){
				printf("不匹配");
				return 0; 
			} 
		}else if(')'==a[i]){
			RightPart++;
			if(LeftPart<RightPart){
				printf("不匹配");
				return 0; 
			} 
		}else if('B'==a[i]){
			FoolNumber=LeftPart-RightPart;
		}else{
			printf("没有礼物");
		}
	}
	if(LeftPart==RightPart){	
		printf("%d",FoolNumber); 
	}else{
		printf("不匹配");
	}	
}




 
