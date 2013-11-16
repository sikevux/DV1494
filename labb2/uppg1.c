#include <stdio.h>

int main() {
	char name[20];
	printf("Ditt förnamn: ");
	scanf("%s", &name);
	printf("Hej %s!\n", name);

	return 0;
}
