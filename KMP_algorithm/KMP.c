#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100
int faliure[MAXSIZE];

void faliure_func(char* s) {
	faliure[0] = -1;

	for (int i = 1; i < (int)strlen(s); i++) {
		faliure[i] = -1;
		for (int j = faliure[i - 1]+1;; j = faliure[j] + 1) {
			if (s[i] == s[j]) {
				faliure[i] = j ;
				break;
			}
			else if (j == 0) break;
		}

	}
}

int p_match(char* str, char *pattern) {
	int j = 0;
	int i = 0;
	while (i < (int)strlen(str) && j < (int)strlen(pattern)) {
		if (str[i] == pattern[j]) {
			i++; j++;
		}
		else if(j==0) i++;
		else {
			j = faliure[j - 1] + 1;
		}
		
	}

	return j == strlen(pattern) ? i-strlen(pattern) : -1;

}


int main(void) {
	
	char s[MAXSIZE];
	char p[MAXSIZE];

	int size_s, size_p;
	printf_s("input object string: ");
	scanf_s("%s", s,sizeof(s));

	printf_s("input pattern string: ");
	scanf_s("%s", p, sizeof(s));
	size_s = strlen(s);
	size_p = strlen(p);

	faliure_func(p);

	printf_s("find index: %d", p_match(s, p));



	


	system("pause");

	return 0;
}
