#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int val;
	struct NODE* next_node;
}NODE;

NODE* alloc_node(int val) {
	NODE* tmp = (NODE*)malloc(sizeof(NODE));
	tmp->val = val;
	tmp->next_node = NULL;
	return tmp;
}

NODE* add_NODE(NODE* start,int value) {
	if (start == NULL) {
		start = alloc_node(value);
	}
	else {
		NODE* tmp = start;
		for (; tmp->next_node != NULL; tmp = tmp->next_node);
		tmp->next_node = alloc_node(value);
	}
	return start;
}

NODE* delete_NODE(NODE* start) {
	if (start == NULL) {
		return NULL;
	}
	else if (start->next_node == NULL) {
		free(start);
		return NULL;
	}
	else {
		NODE* tmp = start;
		for (; tmp->next_node->next_node!= NULL; tmp = tmp->next_node);
		free(tmp->next_node);
		tmp->next_node = NULL;
	}
	return start;
	
}
NODE* delete_i_NODE(NODE* start, int index) {
	if (start == NULL) {
		return NULL;
	}
	else {
		
		NODE* tmp = start;
		if (index == 0) {
			start = start->next_node;
			free(tmp);
			return start;
		}
		else if (index == 1 && start->next_node == NULL) {
			printf_s("out of bound index!!");
			return start;
		}
		else {

			for (int i = 1; i < index; tmp = tmp->next_node, i++) {

		
				if (i == index-1 && tmp->next_node->next_node == NULL) {
					printf_s("out of bound index!!");
					return start;
				}
				else if (tmp->next_node->next_node == NULL) {
					printf_s("out of bound index!!");
					return start;
				}
				
				
			}
			NODE* tmp2 = tmp->next_node;
			tmp->next_node = tmp->next_node->next_node;
			free(tmp2);
		}

	}
	return start;

}
NODE* add_i_NODE(NODE* start, int index, int val) {
	if (start == NULL) {
		return NULL;
	}
	else {
		NODE* tmp = start;
		if (index == 0) {
			start = start->next_node;
			free(tmp);
			return start;
		}
		else if (index == 1 && start->next_node == NULL) {
			printf_s("out of bound index!!");
			return start;
		}
		for (int i = 1; i < index; tmp = tmp->next_node,i++) {
			if (i == index - 1 && tmp->next_node->next_node == NULL) {
				printf_s("out of bound index!!");
				return start;
			}
			else if (tmp->next_node->next_node == NULL) {
				printf_s("out of bound index!!");
				return start;
			}

		}
		NODE* tmp2 = alloc_node(val);
		tmp2->next_node = tmp->next_node;
		tmp->next_node = tmp2;
	}
	return start;
	

}

void print_NODE(NODE* start) {
	printf_s("\n--------------------NODE----------------------\n");
	if (start == NULL) {
		printf_s("NODE empty!!!\n");
		return;
	}
	NODE* tmp = start;
	for (; tmp->next_node != NULL; tmp = tmp->next_node) {
		printf_s("[%d]->", tmp->val);
	}
	printf_s("[%d]->", tmp->val);
	printf_s("\n----------------------------------------------\n");
	return;
}



int main(void){

	int code, value, i;
	NODE* start = NULL;

	
	do {
		printf_s("input code: [0:add_last] [1: delete_last] [2: add ith node] [3: delete ith node] [4: exit] ");
		scanf_s("%d", &code);
		if (code == 0) {
			printf_s("input value: ");
			scanf_s("%d", &value);
			start=add_NODE(start, value);

		}
		else if (code == 1) {
			start=delete_NODE(start);
		}
		else if (code == 2) {
			printf_s("input index and value: ");
			scanf_s("%d %d", &i, &value);
			start = add_i_NODE(start, i, value);
		}
		else if (code == 3) {
			printf_s("input index: ");
			scanf_s("%d", &i);
			start=delete_i_NODE(start, i);
		}
		print_NODE(start);
	} while (code != 4);
	


	system("pause");


	return 0;
}