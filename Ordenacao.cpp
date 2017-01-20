
// DOUGLAS HENRIQUE.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define TAM_VET 10										// tamanho do vetor.



void gerarAleatorio(int *vet) {
	
	srand(time(NULL));									// gerar numeros aleatorios a cada vez que executar o o programa baseado nos segundos desde 1970.
	
	for(int i = 0; i < TAM_VET; i++) 	
		vet[i] = rand() % 100;							// gerando numeros aleatorios menor que 100.
}



void printar(int *vet) {								// método printando na tela.

	for(int i = 0; i < TAM_VET; i++) 		
		printf("%d ", vet[i]);
}



// CODIGO PRINCIPAL **** Bubble Sorte ****
// link de funcionamento: https://www.youtube.com/watch?v=llX2SpDkQDc
void bubbleSort(int *vet) {				

	int aux;											// var aux para guardar valor de vet[j].
	
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
	
	int aux;											// var aux para guardar valor de vet[j].	
	
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
	
	int aux, menorAux;									// var aux para guardar valor menorAux e var menorAux para salvar o menor valor.
	
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
// link de explicação: https://www.youtube.com/watch?v=RZbg5oT5Fgw
void merge(int *vet, int inicio, int meio, int fim) {
	int *temp, p1, p2, tamanho;
	bool fim1 = false, fim2 = false;
	
	tamanho = fim - inicio + 1;
	
	p1 = inicio;
	p2 = meio + 1;
	
	temp = (int*) malloc(tamanho * sizeof(int));
	if(temp != NULL) {
		for(int i = 0; i < tamanho; i++) {
			if(!fim1 && !fim2) {
				if(vet[p1] < vet[p2])
					temp[i] = vet[p1++];
				else
					temp[i] = vet[p2++];
					
				if(p1 > meio) fim1 = true;
				if(p2 > fim)  fim2 = true;			
			} else {
				if(!fim1)
					temp[i] = vet[p1++];
				else
					temp[i] = vet[p2++];	
			}
		}
		
		for(int i = 0, j = inicio; i < tamanho; i++, j++)
			vet[j] = temp[i];
	}
	free(temp);
}

void mergeSort(int *vet, int inicio, int fim) {
	
	int meio;
	
	if(inicio < fim) {
		meio = floor((inicio + fim) / 2);
		mergeSort(vet, inicio, meio);
		mergeSort(vet, meio+1, fim);
		merge(vet, inicio, meio, fim);
	}
}



main() {
	
	int op = 0;
	
	int vet[TAM_VET];									// vetor.
	
	gerarAleatorio(vet);								// chamando metodo gerar numerosAleatorios.
	
	printf ("\nDesordenado: \n\n");
	printar(vet);										// chamando metodo printar, para mostrar o vetor.
	
	printf("\n\nEscolha uma opcao para Ordenar: \n\n");	// menu para o usuario escolher que tipo de ordenação deseja.
	puts("1. Bubble Sort");
	puts("2. Insertion Sort");
	puts("3. Selection Sort");
	puts("4. Merge Sort");
	scanf("%d", &op);
	
	switch(op) {
		case 1: puts("\n\tBubble Sort");
				bubbleSort(vet);    break;				// chamando metodo de ordenação Bubble Sort;
				
		case 2: puts("\n\tInsertion Sort");
				insertionSort(vet); break;				// chamando metodo de ordenação Insertion Sort;
				
		case 3: puts("\n\tSelection Sort");
				selectionSort(vet); break;				// chamando metodo de ordenação Selection Sort;
				
		case 4: puts("\n\tMerge Sort");
				mergeSort(vet, 0, TAM_VET-1); break;	// chamando metodo de ordenação Merge Sort;
	}

	printf ("\nOrdenado: \n\n");	
	printar(vet);										// chamando metodo printar, para mostrar o vetor.	
	
}
