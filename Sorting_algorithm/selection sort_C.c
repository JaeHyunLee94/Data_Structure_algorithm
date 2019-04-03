#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#define num 20
int i;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void selection_sort(int* arr){
	int max=0; int index=0; int j;
	for(i=0;i<num;i++){
		max=0; index=0;
		for(j=i;j<num;j++){
			if(max<=*(arr+j)){
				max=*(arr+j); index=j;
			}
		}		
		*(arr+index)=*(arr+i);
		*(arr+i)=max; 
		
	}
	 
};

int main(int argc, char *argv[]) {
	srand(time(NULL)); int a[num];
	
	for(i=0;i<num;i++){
		a[i]=rand()%100;
	}
	
	for(i=0;i<num;i++){
		printf("%d ",a[i]);
	}
	printf("\n ");
	
	selection_sort(a);
	for(i=0;i<num;i++){
		printf("%d ",a[i]);
	}
	 
	 
	
	
	
	return 0;
}

