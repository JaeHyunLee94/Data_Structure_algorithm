#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct element{
	int value;
}Element;

Element Queue[MAX_SIZE];
int front=-1;
int rear=-1;

void Enqueue(Element tmp){
	if(rear==MAX_SIZE-1){
		printf_s("queue Full! \n");
		return ;
	}
	else{
		Queue[++rear]=tmp;
	}
}

Element Dequeue(){
	if(front==rear){
		printf_s("queue empty!\n");
	}
	else{
		return Queue[++front];
	}
}

void print_Queue(){
	printf_s("current Queue: ");
	for(int i=front+1;i<=rear;i++){
		printf_s("[%d]->",Queue[i].value);
	}
	printf_s("\n");
}


int main(void){

	int eord;
	printf_s("Enqueue: 0 Dequeue: 1: exit: 2\ninput code: ");
	scanf_s("%d",&eord);

	while(eord!=2){
		if(eord==0){
			Element v;
			printf_s("input value: ");
			scanf_s("%d",&(v.value));
			Enqueue(v);
		}
		else if(eord==1){
			printf_s("dequed value: %d\n",(Dequeue().value));
		}

		print_Queue();
		printf_s("Enqueue: 0 Dequeue: 1: exit: 2\ninput code: ");
		scanf_s("%d",&eord);
	}






	system("pause");


	return 0;
}