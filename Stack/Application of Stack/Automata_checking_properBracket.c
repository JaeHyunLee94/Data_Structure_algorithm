/*
ex) ()()<> this is valid

ex) (()>    this is unvalid
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
char STACK[MAX_SIZE];
int top=-1;

void push(char s){
	if(top>=MAX_SIZE){
		fprintf_s(stderr,"full stack!!");
		return ;
	}
	else{
		STACK[++top]=s;
	}

}
char pop(){
	if(top==-1){
		fprintf_s(stderr,"empty stack!!");
	}

	else{
		return STACK[top--];
	}
}


int main(void) {
	char str_in[MAX_SIZE];
	printf_s("input string: ");
	scanf_s("%s",str_in,sizeof(str_in));
	getchar();
	int error_code=0;
	for(size_t i=0;i<strlen(str_in);i++){
		if(str_in[i]=='('||str_in[i]=='{'||str_in[i]=='['){
			push(str_in[i]);
		}
		else if(str_in[i]==')'&&STACK[top]=='('){
			pop();
		}
		else if(str_in[i]=='}'&&STACK[top]=='{'){
			pop();
		}
		else if(str_in[i]==']'&&STACK[top]=='['){
			pop();
		}
		else{
			error_code=1;
			break;
		}
			
		
	}
	if(top!=-1) error_code=1;

	error_code==0? printf_s("nice string!\n") :  printf_s("bad string!\n");

	

	system("pause");

	return 0;
}
