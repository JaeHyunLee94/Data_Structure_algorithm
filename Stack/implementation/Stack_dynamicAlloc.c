#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct element {
	int value;

}element;

element* STACK = NULL;
int top = 0;
int capacity = 0;

void Expand_Stack() {
	element* tmp = STACK;
	capacity *= 2;
	
	STACK=(element*)realloc(STACK, capacity*sizeof(element) );

}

void push(element val) {
	if (top == capacity) {
		Expand_Stack();
		STACK[top++] = val;
	}
	else {
		STACK[top++] = val;
	}
}

element pop() {
	if (top == 0) {
		fprintf(stderr, "Stack empty!!");
		return ;
	}
	else {
		return STACK[--top];
	}
}

_Bool isEmpty() {
	return top == 0;
}



void print_Stack() {

	printf_s("STACK information!: \n");
	printf_s("-------------------------------\n");
	for (int i = 0; i < top; i++) {
		printf_s("Stack[%d]: %d\n", i, STACK[i].value);
	}
	printf_s("-------------------------------\n");
}




int main(void) {
	int key = 0;
	element val = { 0 };
	int push_or_pop = 0;
	printf_s("enter capacity: ");
	scanf_s("%d", &capacity);

	STACK = (element*)malloc(sizeof(element)*capacity);

	while (push_or_pop != 4) {
		printf_s("push: 0, pop: 1,  print Stack: 2,print_capacity: 3 Quit: 4\n");
		scanf_s("%d", &push_or_pop);

		switch (push_or_pop)
		{
		case 0:
			printf_s("input values: ");
			scanf_s("%d", &key);
			printf_s("\n");
			getchar();
			val.value = key;
			push(val);
			break;
		case 1:
			printf_s("poped value: %d\n", pop().value);
			break;
		case 2:
			print_Stack();
			break;
		case 3:
			printf_s("capacity: %d\n", capacity);
			break;
		case 4:
			break;
		default:
			break;
		}

	}



	system("pause");

	return 0;
}