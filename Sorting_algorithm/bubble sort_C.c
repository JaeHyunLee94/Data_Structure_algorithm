#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 20
int i;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void bubblesort(int* array){
	for(i=0;i<size;i++){
		int temp=0; int j;
		for(j=0;j<size-i-1;j++){
			if(*(array+j)<=*(array+j+1)){
				temp=*(array+j);
				*(array+j)=*(array+j+1);
				*(array+j+1)=temp;
				
			}
		}
	}
	
}
int main(int argc, char *argv[]) {
	srand(time(NULL)); int arr[size];
	printf("original array: ");
	for(i=0;i<size;i++){
		arr[i]=rand()%100;
		printf("%d ",arr[i]);
	}
	
	bubblesort(arr);
	printf("\nsorted array: ");
	
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
		
	
	return 0;
}
