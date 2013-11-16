#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IN 256

int main() {
	char* host = malloc(MAX_IN);
	char* date = malloc(MAX_IN);
	char* location = malloc(MAX_IN);
	char* invited = malloc(MAX_IN);
	char* time = malloc(MAX_IN);
	char* hours = malloc(MAX_IN);
	int i;

	// Kolla så att minnet inte är slut
	if(host == NULL || date == NULL || location == NULL || invited == NULL) {
		printf("Out of memory\n");
		return 1;
	}

	printf("Vem står för inbjudan? ");
	fgets(host, MAX_IN, stdin);

	/* Kolla så att det är ett "namn" vi fått in
	 * Bo är nog kortaste namnet som finns
	 */
	if(strlen(host) < 2) {
		printf("Invalid input\n");
		return 1;
	}

	printf("Vilket datum? ");
	fgets(date, MAX_IN, stdin);

	// Minsta datumet bör vara "1 maj"
	if(strlen(date) < 5 || !isdigit(date[0])) {
		printf("Invalid input\n");
		return 1;
	}

	printf("Vilket klockslag börjar festen? ");
	fgets(time, MAX_IN, stdin);

	// Se till så att allt är siffror
	for(i = 0; i < strlen(time)-1; ++i) {
		if(!isdigit(time[i])) {
			printf("Invalid input\n");
			return 1;
		}
	}

	printf("Hur många timmar håller festen på? ");
	fgets(hours, MAX_IN, stdin);

	// Kolla så att allt är siffror
	for(i = 0; i < strlen(hours)-1; ++i) {
		if(!isdigit(hours[i])) {
			printf("Invalid input\n");
			return 1;
		}
	}

	printf("Var? ");
	fgets(location, MAX_IN, stdin);

	/* Vi kan inte veta vad folk kallar sina mötespunkter för
	 * men vi kan anta att de kallar dem något,
	 * så se till att vi får in något i alla fall.
	 */
	if(strlen(location) == 0) {
		printf("Invalid input\n");
		return 1;
	}

	printf("Vem ska bjudas? ");
	fgets(invited, MAX_IN, stdin);

	if(strlen(invited) < 2) {
		printf("Invalid input\n");
		return 1;
	}

	// Ta bort alla newlines
	host[strlen(host) - 1] = '\0';
	date[strlen(date) - 1] = '\0';
	location[strlen(location) - 1] = '\0';
	invited[strlen(invited) - 1] = '\0';
	time[strlen(time) - 1] = '\0';
	hours[strlen(hours) - 1] = '\0';

	printf("\n------------------------\n");
	printf("Hej %s!\n\nDu är välkommen på fest den %s kl %s i %s.\n", invited, date, time, location);
	printf("Festen varar tills klockan %d.\n", (atoi(time)+atoi(hours)) % 24);
	printf("Hälsningar\n%s\n", host);


	// Se till att vi frigör allt minne
	free(host);
	host = NULL;

	free(date);
	date = NULL;

	free(location);
	location = NULL;

	free(invited);
	invited = NULL;

	free(time);
	time = NULL;

	free(hours);
	hours = NULL;

	return 0;
}
