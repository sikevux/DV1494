#include <stdio.h>
#include <math.h>

int main() {
	float side1 = 20;
	float side2 = 30;
	float hypotenuse = 0;

	hypotenuse = sqrt((side1*side1)+(side2*side2));
	printf("Hypotenusan borde vara %f\n", hypotenuse);

	return 0;
}
