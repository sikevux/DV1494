#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 50

int main() {
	int side1, side2, len, i;
	char* buffer = malloc(MAX_SIZE);
	float hypot;

	if(buffer == NULL) {
		printf("Out of memory\n");
		return 1;
	}

	printf("Sida 1: ");
	fgets(buffer, MAX_SIZE, stdin);

	len = strlen(buffer) - 1;
	for(i = 0; i < len; ++i) {
		if(!isdigit(buffer[i])) {
			printf("Invalid input\n");
			return 1;
		}
	}

	side1 = atoi(buffer);

	printf("Sida 2: ");
	fgets(buffer, MAX_SIZE, stdin);

	len = strlen(buffer) - 1;
	for(i = 0; i < len; ++i) {
		if(!isdigit(buffer[i])) {
			printf("Invalid input\n");
			return 1;
		}
	}

	side2 = atoi(buffer);

	hypot = sqrt(pow(side1, 2) + pow(side2, 2));

	printf("Givet att sidorna är %d och %d\n", side1, side2);
	printf("så blir hypotenusan %f\n", hypot);
	return 0;

}
