/*
this program is one digit Calculator
this program is for studying application of Stack

please input one digit

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100



char input_str[MAX_SIZE]; //string for input

char STACK[MAX_SIZE]; //stack for convert input string to postfix
int STACK_TOP=0;

char post_str[MAX_SIZE]; //save postfix string
int post_str_index=0;

char CAL_STACK[MAX_SIZE]; //string for calculating value
int CAL_STACK_TOP=0;

//below is for Stack function

void push_STACK(char a){
	STACK[STACK_TOP++]=a;
}
char pop_STACK(){
	if(STACK_TOP==0){
		return 't';
	}
	else return STACK[--STACK_TOP];
}
void push_CAL_STACK(char a){
	CAL_STACK[CAL_STACK_TOP++]=a;
}

char pop_CAL_STACK(){
	if(CAL_STACK_TOP==0){
		return 't';
	}
	else return CAL_STACK[--CAL_STACK_TOP];
}
//get token precendence
int get_precedence(char a){

	if(a=='(') return 1;
	else if(a==')') return 2;
	else if(a=='+'||a=='-') return 12;
	else if(a=='*'||a=='/'||a=='%') return 13;
	else if(a=='\0') return 0;
	else return 3;
}
//convert infix to postfix
void convert_post(void){
	

	for(size_t i=0;i<=strlen(input_str);i++){
		
		if (input_str[i] == '(') { 

			push_STACK(input_str[i]);
		} // push (
		else if(input_str[i]==')'){
			
			char tmp=pop_STACK();
			while(tmp!='('){
				if(tmp=='t') break;
				post_str[post_str_index++]=tmp;
				tmp=pop_STACK();
			}
		}//pop until meet (
		else if (get_precedence(input_str[i]) == 3) {
			post_str[post_str_index++] = input_str[i];
		}//goto post_str if input_str[i] is operand
		else if(get_precedence(input_str[i])<=get_precedence(STACK[STACK_TOP-1])){

			char tmp=pop_STACK();
			post_str[post_str_index++]=tmp;
			while(get_precedence(input_str[i])<=get_precedence(STACK[STACK_TOP-1])&&STACK_TOP>=1){
				tmp=pop_STACK();
				post_str[post_str_index++]=tmp;
			}
			push_STACK(input_str[i]);
		} 
		else {
			push_STACK(input_str[i]);
		}
	}
}

// calculate the postfix string
int cal_Post(){
	for(int i=0 ; i<post_str_index;i++){
		if(get_precedence(post_str[i])==3){
			push_CAL_STACK(post_str[i]);
		}
		else{
			int op1=pop_CAL_STACK()-'0'; //if operator pop twice and calcutlate value and then push the value
			int op2=pop_CAL_STACK()-'0';
			int op3=0;
			if(post_str[i]=='*') op3=op2*op1;
			else if(post_str[i]=='/') op3=op2/op1;
			else if(post_str[i]=='%') op3=op2%op1;
			else if(post_str[i]=='+') op3=op2+op1;
			else if(post_str[i]=='-') op3=op2-op1;

			char tmp=op3+'0';
			push_CAL_STACK(tmp);
			
		}
	}
	return (int)(pop_CAL_STACK()-'0');

}




int main(void) {
	printf_s("input expression: ");
	scanf_s("%s",input_str,sizeof(input_str));
	getchar();
	convert_post();
	int a=cal_Post();
	printf_s("output value is %d \n", a);
	

	system("pause");

	return 0;
}