#include <stdio.h>
#include <stdlib.h>

int main() {
	/* VARNING!
	 * Man beräknar inte fastighetsskatt på detta vis!
	 */

	static const int maxdata = sizeof(int) * 2;
	static const int taxrate1 = 2;
	static const int taxlevel1 = 450000;
	static const int taxrate2 = 4;
	static const int taxlevel2 = 600000;
	static const int taxrate3 = 6;
	static const int taxlevel3 = 750000;
	static const int taxrate4 = 8;

	int taxvalue;
	float tax = 0;

	char* indata = malloc(maxdata);

	if(indata == NULL) {
		printf("Out of memory");
		return 1;
	}

	printf("Mata in taxeringsvärdet på din fastighet: ");
	fgets(indata, maxdata, stdin);
	taxvalue = atoi(indata);

	if(taxvalue > taxlevel3) {
		tax += ((taxvalue - taxlevel3)/100.0) * taxrate4;
		taxvalue -= (taxvalue - taxlevel3);
	}

	if(taxvalue > taxlevel2) {
		tax  += ((taxvalue - taxlevel2)/100.0) * taxrate3;
		taxvalue -= (taxvalue - taxlevel2);
	}

	if(taxvalue > taxlevel1) {
		tax += ((taxvalue - taxlevel1)/100.0) * taxrate2;
		taxvalue -= (taxvalue - taxlevel1);
	}

	if(taxvalue <= taxlevel1) {
		tax += (taxvalue/100) * taxrate1;
	}

	printf("Du borde betala %.0f i skatt\n", tax);

	free(indata);
	indata = NULL;

	return 0;
}
