#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

int circular_Queue[MAX_SIZE];
int front=-1;
int rear=-1;

void Enqueue(int val){
	if((front+1)%MAX_SIZE==(rear+2)%MAX_SIZE){
		return;
	}
	else{
		rear=(rear+1)%MAX_SIZE;
		circular_Queue[rear]=val;
	}
}

int Dequeue(){
	if(front==rear){
		return;
	}
	else{
		front=(front+1)%MAX_SIZE;
		return circular_Queue[front];
	}
}
void print_Queue(){
	printf_s("\n--------------Queue------------\n");
	if(front==rear){
		printf_s("empty Queue!!!!\n");
		return;
	}
	int i = (front + 1) % MAX_SIZE;
	for(i=(front+1)%MAX_SIZE;i!=rear;i=(i+1)%MAX_SIZE){
		printf_s("[%d]->",circular_Queue[i]);
	}
	printf_s("[%d]->",circular_Queue[i]);
	
	printf_s("\n--------------------------\n");
}



int main(void){
	int code;
	int key;
	do{
		printf_s("input enqueue(0) or dequeue(1): ");
		scanf_s("%d",&code);

		if(code==0){
			printf_s("enqueue value: ");
			scanf_s("%d",&key);
			Enqueue(key);
			print_Queue();
		}
		else if(code==1){
			Dequeue();
			print_Queue();
		}
		
	}while(code!=2);
	


	system("pause");


	return 0;
}