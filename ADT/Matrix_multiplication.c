#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct tuple {
	int row, column, val;
}tuple;


typedef struct Matrix{
	int total_row, total_column, total_val;
	tuple mat_info[MAX];
}Matrix;


void make_Matrix(Matrix* a) {
	int tmp = 0;
	int iter = 0;
	for (int i = 0; i < a->total_row; i++) {
		for (int j = 0; j <a->total_column; j++) {
			scanf_s("%d", &tmp);
			if (tmp) {
				a->mat_info[iter].row = i;
				a->mat_info[iter].column = j;
				a->mat_info[iter].val = tmp;
				a->total_val++;
				iter++;
			}

		}
		getchar();
	}
}
void print_matrix(Matrix* a) {
	int iter = 0;
	printf_s("\n ----------------Matrix-------------- \n");
	for (int i = 0; i < a->total_row; i++) {
		for (int j = 0; j < a->total_column; j++) {
			if (i == a->mat_info[iter].row&&j == a->mat_info[iter].column) {
				printf_s("%d ", a->mat_info[iter].val);
				iter++;
			}
			else printf_s("0 ");
		}
		printf_s("\n");
	}
	printf_s("-------------------------------------------\n");
}

void fast_transpose(Matrix* a,Matrix * transP) {
	transP->total_row = a->total_column;
	transP->total_column = a->total_row;
	transP->total_val= a->total_val;
	int n = a->total_val;

	int start_pos[MAX] = { 0 };
	int row_term[MAX] = { 0 };
	start_pos[0] = 0;

	for (int i = 0; i < n; i++) {
		row_term[a->mat_info[i].column]++;
	}
	for (int i = 1; i < a->total_column; i++) {
		start_pos[i] = row_term[i - 1] + start_pos[i - 1];
	}

	for (int i = 0; i < n; i++) {
		transP->mat_info[start_pos[a->mat_info[i].column]].column = a->mat_info[i].row;
		transP->mat_info[start_pos[a->mat_info[i].column]].row = a->mat_info[i].column;
		transP->mat_info[start_pos[a->mat_info[i].column]].val = a->mat_info[i].val;
		start_pos[a->mat_info[i].column]++;
	}

}
Matrix mat_mult(Matrix* a, Matrix* b_t) {
	Matrix c;
	c.total_row = a->total_row;
	c.total_column = b_t->total_row;
	c.total_val = 0;
	int total_a = a->total_val;
	int total_bt = b_t->total_val;

	a->mat_info[total_a ].row = a->mat_info[total_a-1].row + 1;
	b_t->mat_info[total_bt].row = b_t->mat_info[total_bt-1].row + 1;

	int row = a->mat_info[0].row;
	int column = b_t->mat_info[0].row;
	int i = 0; int j = 0;
	int sum = 0;
	while (row <= a->mat_info[total_a-1].row&&column <= b_t->mat_info[total_bt-1].row) {
		int tmpi = i;
		int tmpj = j;
		
		for (; a->mat_info[i].row<= row; i++) {
			
			for (; b_t->mat_info[j].row <= column; ) {
				if (a->mat_info[i].column == b_t->mat_info[j].column) {
					sum = sum + (a->mat_info[i].val)*(b_t->mat_info[j].val);
					j++;
					break;
				}
				else if (a->mat_info[i + 1].row == row &&b_t->mat_info[j+1].row != column ) {
					j = tmpj;
					break;
				}
				j++;
			}
		}

		if (sum) {
			c.mat_info[c.total_val].row = row;
			c.mat_info[c.total_val].column = column;
			c.mat_info[c.total_val].val = sum;
			c.total_val++;
		}
		if (j!=total_bt) {
			column = b_t->mat_info[j].row;
			i = tmpi;
			sum = 0;
		}
		else if (i == total_a) break;
		else {

			row = a->mat_info[i].row;
			column = b_t->mat_info[0].row;
			j = 0;
			sum = 0;
		}
	}
	
	return c;
	
}


int main(void){

	while (1) {

		Matrix A = { 0,0,0};
		Matrix B = { 0,0,0};
		Matrix B_t= { 0,0,0};
		int row_A, column_A, row_B, column_B;

		printf_s("------------\ninput A's row and column: ");
		scanf_s("%d %d", &row_A, &column_A);
		getchar();
		printf_s("input the array: \n------------\n");
		A.total_column = column_A;
		A.total_row = row_A;
		make_Matrix(&A);


		printf_s("------------\ninput B's row and column: ");
		scanf_s("%d %d", &row_B, &column_B);
		getchar();
		printf_s("input the array: \n-------------\n");
		B.total_column = column_B;
		B.total_row = row_B;
		make_Matrix(&B);


		fast_transpose(&B, &B_t);
		printf_s("\ntranspose B: \n");
		print_matrix(&B_t);

		Matrix c = mat_mult(&A, &B_t);
		printf_s("\nmultupied matrix: \n");
		print_matrix(&c);


	}

	

	return 0;
}