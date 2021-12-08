#include <stdio.h>
#include <math.h>

#define DIM 8

int fRange (int lB, int uP); //Funzione per l'acquisizione di un valore in un determinato range

void fBin(int vet[], int dim); //Funzione per la conversione di numeri da decimale a binario

int main () {
	
	int primoAdd[DIM+1];
	int secAdd[DIM+1];
	int somma[DIM+1];
	int carry[] = {0,0,0,0,0,0,0,0,0};
	int scelta;
	int i;
	
	do {
		printf ("INSERIRE PRIMO NUMERO\n");
		fBin(primoAdd, DIM);
	
		printf ("INSERIRE SECONDO NUMERO\n");
		fBin(secAdd, DIM);
	
		for (i = 0; i <= DIM; i++) {
		
			somma[i] = primoAdd[i] + secAdd[i] + carry[i];
		
			switch (somma[i]) {
			
				case 0:
				
					somma[i] = 0;
					carry[i+1] = 0;
				
					break;
				case 1:	
			
					somma[i] = 1;
					carry[i+1] = 0;
				
					break;
				case 2:
				
					somma[i] = 0;
					carry[i+1] = 1;
				
					break;
				case 3:
				
					somma[i] = 1;
					carry[i+1] = 1;
				
			}//switch
		}//for
	
		printf ("Risultato: ");
		for (i = DIM; i >= 0; i--) {
		
			printf ("%d", somma[i]);
		}	
		do {
			printf ("\nEseguire una nuova somma? [1 = si' 0 = no]  ");
			scanf("%d", &scelta);
		}
		while (scelta != 0 && scelta != 1);
	}
	while (scelta == 1);

	
}//main


int fRange (int lB, int uP) {
	
	int num;
	
	do {	
		scanf ("%d", &num);
		
	}
	while (num < lB || num > uP);
	
	return num;
}//fRange

void fBin(int vet[], int dim) {
	
	int n, i;
	
	n = fRange(0, pow(2,dim)-1);
		
	for (i = 0; i < dim+1; i++) {
		
		if (n%2 == 0) {	
			vet[i] = 0;
		}
		else {	
			vet[i] = 1;
		}	
		n /= 2;
	}//for
	
	return;
	
}//fBin
