
// DOUGLAS HENRIQUE.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TAM_VET 10						// tamanho do vetor.



void gerarAleatorio(int *vet) {
	
	srand(time(NULL));				// gerar numeros aleatorios a cada vez que executar o o programa baseado nos segundos desde 1970.
	
	for(int i = 0; i < TAM_VET; i++) 	
		vet[i] = rand() % 100;			// gerando numeros aleatorios menor que 100.
}



void printar(int *vet) {				// método printando na tela.

	for(int i = 0; i < TAM_VET; i++) 		
		printf("%d ", vet[i]);
}



// CODIGO PRINCIPAL **** Bubble Sorte ****
// link de funcionamento: https://www.youtube.com/watch?v=llX2SpDkQDc
void bubbleSort(int *vet) {				

	int aux;							// var aux para guardar valor de vet[j].
	
	for(int i = TAM_VET - 1; i > 0; i--) 
		for(int j = 0; j < i; j++) 
			if(vet[j] > vet[j + 1]) { 
				aux = vet[j];
				vet[j] = vet[j + 1];
				vet[j + 1] = aux;
			}	
}



// CODIGO PRINCIPAL **** Insertion Sorte ****
// link de funcionamento: https://www.youtube.com/watch?v=-Z00it6Nkz8										
void insertionSort(int *vet) {				
	
	int aux;								// var aux para guardar valor de vet[j].	
	
	for(int i = 0; i < TAM_VET - 1; i++) 
		if(vet[i] > vet[i + 1])
			for(int j = i; j >= 0; j--) 
				if(vet[j] > vet[j + 1]) {
					aux = vet[j];
					vet[j] = vet[j + 1];
					vet[j + 1] = aux;
				}	
}



// CODIGO PRINCIPAL **** Selection Sorte ****
// link de funcionamento: https://www.youtube.com/watch?v=BSXIolKg5F8
void selectionSort(int *vet) {						
	
	int aux, menorAux;								// var aux para guardar valor menorAux e var menorAux para salvar o menor valor.
	
	for(int i = 0; i < TAM_VET; i++) {
		
		menorAux = vet[i];
		
		for(int j = i + 1; j < TAM_VET; j++) 
			if(menorAux > vet[j]) {
				aux = menorAux;
				menorAux = vet[j];
				vet[j] = aux;
			}
		
		vet[i] = menorAux;
	}	
}



// CODIGO PRINCIPAL **** Merge Sorte ****
// link de funcionamento: https://www.youtube.com/watch?v=cDNqk4tdvqQ
// TODO

main() {
	
	int vet[TAM_VET];					// vetor.
	
	gerarAleatorio(vet);				// chamando metodo gerar numerosAleatorios.
	
	printf ("\nDesordenado: \n\n");
	printar(vet);						// chamando metodo printar, para mostrar o vetor.
										
	bubbleSort(vet);					// chamando metodo de ordenação Bubble Sort.
	
	printf ("\n\n\nOrdenado: \n\n");	
	printar(vet);						// chamando metodo printar, para mostrar o vetor.		
}
