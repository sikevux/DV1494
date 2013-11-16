#include <stdio.h>

int main() {
	int toconvert = 1026;
	int pound = 0;
	int shilling = 0;
	int pence = 0;

	pound = (int) toconvert/(12*20);
	shilling = (int) (toconvert  % (12*20))/12;
	pence = (int) (toconvert % (12*20)) % 12;

	printf("Du borde ha %d pund, %d shilling och %d pence\n", pound, shilling, pence);

	return 0;
}
