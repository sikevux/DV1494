#include <stdio.h>
#include <stdlib.h>

int main() {
	static const int maxdata = sizeof(int)*2;
	char* indata = malloc(maxdata);
	int tries = 0;

	do {
		if(tries == 0) {
			printf("Mata in året du är född: ");
		} else {
			printf("Det där blev nog fel, försök igen: ");
		}

		fgets(indata, maxdata, stdin);

		if(1900 <= atoi(indata) && atoi(indata) <= 2013) {
			break;
		} else {
			tries++;
		}
	} while((2013 <= atoi(indata) || atoi(indata) <= 1900) && tries < 5);

	if(tries < 5) {
		printf("Grattis du matade in ett godkänt årtal\n");
	} else {
		printf("Tyvärr lyckades du inte mata in ett godkänt årtal\n");
	}

	free(indata);
	indata = NULL;

	return 0;
}
