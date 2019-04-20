#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_SIZE 100

typedef struct element {
	int value;

}element;

element STACK[MAX_SIZE] = { {0} };
int top = 0;

void push(element val) {
	if (top == MAX_SIZE) {
		fprintf(stderr, "Stack Full!!\n");
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
_Bool isFull() {
	return top == MAX_SIZE;
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

	while (push_or_pop!=3) {
		printf_s("push: 0, pop: 1,  print Stack: 2, Quit: 3\n");
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
			printf_s("poped value: %d\n",pop().value);
			break;
		case 2:
			print_Stack();
			break;
		case 3:
			break;
		default:
			break;
		}

	}
	


	system("pause");

	return 0;
}