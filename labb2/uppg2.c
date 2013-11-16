#include <stdio.h>
#include <math.h>

int main() {
	int radius;
	float pi=3.1415;
	printf("Cirkelns radie: ");
	scanf("%d", &radius);
	printf("Cirklens omkrets: %f\n", pow(radius, 2) * pi);


	return 0;
}
