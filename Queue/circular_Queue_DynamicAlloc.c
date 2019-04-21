#include <stdio.h>
#include <stdlib.h>

int *circular_Queue = NULL;
int front = -1;
int rear = -1;
int capacity = 5;

void Queue_full() {
	int* new_Queue = (int*)malloc(2 * capacity * sizeof(int));
	int i = (front + 1) % capacity;
	int j = 0;
	for (; i != rear; i = (i + 1) % capacity,j++) {
		new_Queue[j] = circular_Queue[i];
	}
	new_Queue[j] = circular_Queue[i];
	free(circular_Queue);
	circular_Queue = new_Queue;
	front = -1;
	rear = capacity - 2;
	capacity = 2 * capacity;

}

int Dequeue() {
	if ((front)%capacity == (rear)%capacity) {
		return;
	}
	else {
		int tmp = rear;
		rear = (rear - 1) % capacity;
		return circular_Queue[tmp];
	}
	
}
void Enqueue(int val) {
	if ((rear + 2) % capacity == (front+1) % capacity) {
		Queue_full();
		rear = (rear + 1) % capacity;
		circular_Queue[rear] = val;
	}
	else {
		rear = (rear + 1) % capacity;
		circular_Queue[rear] = val;
	}
}

void print_Queue() {
	if (front == rear) {
		printf_s("\n---empty Queue!!!-------\n");
	}
	printf_s("\n-----------Queue-------------\n");
	int i = (front + 1) % capacity;
	for (; i != rear; i = (i + 1) % capacity) {
		printf_s("[%d]->", circular_Queue[i]);
	}
	printf_s("[%d]->\n", circular_Queue[i]);
	printf_s("Capacity: <%d>\n", capacity);
}




int main(void){

	printf_s("input first capacity: ");
	scanf_s("%d", &capacity);
	circular_Queue = (int*)malloc(sizeof(int)*capacity);
	int e_or_d;
	int val;

	do {
		printf_s("input enQueue:0 or Dequeue:1 exit:2  ");
		scanf_s("%d", &e_or_d);
		if (e_or_d == 0) {
			printf_s("input enqueue val: ");
			scanf_s("%d", &val);
			Enqueue(val);
		}
		else if (e_or_d == 1) {
			Dequeue();
		}
		
		if (front != rear) { 
			print_Queue();
			
		}
		else {
			printf_s("\nempty Queue!!\n");
		}

		
	} while (e_or_d != 2);
	


	system("pause");


	return 0;
}