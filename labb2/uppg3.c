#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NAME_SIZE 51

int main() {
	char *player1 = malloc(NAME_SIZE);
	char *player2 = malloc(NAME_SIZE);

	if(player1 == NULL || player2 == NULL) {
		printf("Out of memory\n");
		return 1;
	}

	int player1dice1, player1dice2, player2dice1, player2dice2;


	printf("Spelare 1: ");
	fgets(player1, NAME_SIZE, stdin);

	if((strlen(player1) > 0) && (player1[strlen(player1) - 1] == '\n')) {
		player1[strlen(player1) - 1] = '\0';
	}


	printf("Spelare 2: ");
	fgets(player2, NAME_SIZE, stdin);

	if((strlen(player2) > 0) && (player2[strlen(player2) - 1] == '\n')) {
		player2[strlen(player2) - 1] = '\0';
	}

	printf("\n");
	srand(time(NULL));

	player1dice1 = rand() % 6 + 1;
	player1dice2 = rand() % 6 + 1;
	player2dice1 = rand() % 6 + 1;
	player2dice2 = rand() % 6 + 1;

	printf("Tärningskast för %s: %d och %d\n", player1, player1dice1, player1dice2);
	printf("Tärningskast för %s: %d och %d\n", player2, player2dice1, player2dice2);

	printf("\n");

	printf("%s fick resultatet %d\n", player1, player1dice1 + player1dice2);
	printf("%s fick resultatet %d\n", player2, player2dice1 + player2dice2);

	free(player1);
	player1 = NULL;

	free(player2);
	player2 = NULL;

	return 0;
}
