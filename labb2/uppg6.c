#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_LEN 256

char *decimal_to_binary(int n) {
	int c, d, count;
	char *pointer;

	count = 0;
	pointer = (char*)malloc(MAX_LEN);

	if(pointer == NULL) {
		exit(EXIT_FAILURE);
	}

	for(c = sizeof n * CHAR_BIT -1; c >= 0; --c) {
		d = n >> c;
		if(d & 1) {
			*(pointer+count) = 1 + '0';
		} else {
			*(pointer+count) = 0 + '0';
		}

		count++;
	}

	*(pointer+count) = '\0';

	return  pointer;
}

int main() {
	char* buffer = malloc(MAX_LEN);
	char* number = malloc(MAX_LEN);
	int num;
	char* pointer;

	if(number == NULL || buffer == NULL) {
		printf("Out of memory\n");
		return 1;
	}

	printf("Mata in ett tal du vill konvertera: ");
	fgets(number, MAX_LEN, stdin);

	if(strlen(number) == 0) {
		printf("Invalid input\n");
		return 1;
	}

	number[strlen(number) - 1] = '\0';
	num = atoi(number);
	pointer = decimal_to_binary(num);

	printf("Bin\tOct\tDec\n");
	printf("%s\t%o\t%d\n", pointer, num, num);

	free(pointer);

	return 0;
}
