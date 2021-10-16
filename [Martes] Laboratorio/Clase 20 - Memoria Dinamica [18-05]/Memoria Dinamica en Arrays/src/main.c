/******************************************************************************

Luciano Crocco 1ºF

Memoria dinamica en Vectores/Arrays. Uso de Malloc, Calloc, Realloc y free

Realloc REASIGNA espacio en memoria, previamente tendria que haber asignado

El free se utiliza para liberar espacio en el HEAP.

*******************************************************************************/
#include <stdio_ext.h>
#include <stdlib.h>

#define TAMANIO 5

int main()
{
	int* pVector;
	int* auxiliar;
	int i;

	//pVector = (int*) malloc(sizeof(int)*TAMANIO);
	pVector = (int*) calloc(sizeof(int),TAMANIO);

	if(pVector != NULL){
		printf("Cargo 5\n");
		for(i=0;i<TAMANIO;i++){
			*(pVector+i)= i+1;
		}

		for(i=0;i<TAMANIO;i++){
			printf("%d\n", *(pVector+i));
		}

		auxiliar = (int *) realloc(pVector, sizeof(int)*(TAMANIO+5));
		//auxiliar y pVector apuntan al mismo lugar de memoria, si libero uno pierdo la referencia con el otro
		if(auxiliar != NULL){
			pVector = auxiliar;

			printf("Cargo 5 mas\n");
			for(i=TAMANIO;i<TAMANIO*2;i++){
				*(pVector+i)= i+1;
			}

			for(i=0;i<TAMANIO*2;i++){
				printf("%d\n", *(pVector+i));
			}
		}

		//auxiliar y pVector apuntan al mismo lugar de memoria, si libero uno pierdo la referencia con el otro
		auxiliar = (int *) realloc(pVector, sizeof(int)*(TAMANIO-1)); //Realloc REASIGNA espacio en memoria, previamente tendria que haber asignado
		if(auxiliar != NULL){
			pVector = auxiliar;
			printf("Achico a 4 elementos totales\n");
			for(i=0;i<TAMANIO-1;i++){
				printf("%d\n", *(pVector+i));
			}

		}

	}


    return EXIT_SUCCESS;
}

