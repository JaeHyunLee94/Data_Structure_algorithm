#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 20
int i;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void insertionsort(int* array){
	int j; int temp; int index=0;
	for(i=1;i<size;i++){ 
		index=0; temp=*(array+i);
	   for(j=0;j<i;j++){
	   	 if(*(array+i)>=*(array+j)){
	   	 	index=j;
	   	 	break;
			}
			index=i;//이미 정렬되어 있을 경우 
	   }

		for(j=i;j>index;j--){
			*(array+j)=*(array+j-1);
		}
		*(array+index)=temp;
	}
}
int main(int argc, char *argv[]) {
	srand(time(NULL)); int arr[size];
	printf("original array: ");
	for(i=0;i<size;i++){
		arr[i]=rand()%100;
		printf("%d ",arr[i]);
	}
	
	insertionsort(arr);
	printf("\nsorted array: ");
	
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
		
	
	return 0;
}
