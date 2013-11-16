#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	static const int maxdata = sizeof(int) * 2;
	char* inputholder = malloc(maxdata);

	if(inputholder == NULL) {
		printf("Out of memory\n");
		return 1;
	}

	int a,b,c;
	float s,area;

	printf("Du kommer nu ombes att mata in längden för tre sidor av en triangel\n");

	printf("Sida 1: ");
	fgets(inputholder, maxdata, stdin);
	a = atoi(inputholder);

	printf("Sida 2: ");
	fgets(inputholder, maxdata, stdin);
	b = atoi(inputholder);

	printf("Sida 3: ");
	fgets(inputholder, maxdata, stdin);
	c = atoi(inputholder);

	if(a+b>c && a+c>b && b+c>a) {
		s=(a+b+c)/2;
		area=sqrt(s * (s-a) * (s-b) * (s-c));
		printf("Arean är: %f", area);
	} else {
		printf("Sidorna kan inte utgöra en triangel\n");
		return 1;
	}

	return 0;
}
