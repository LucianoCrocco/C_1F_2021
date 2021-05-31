/*
 * main.c
 *
 *  Created on: 29 may. 2021
 *      Author: luciano
 */
#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main (void){
	int* pVector;
	int arrayNumeros[5]={9,2,4,5,6};
	int numero;

	pVector = (int*) calloc (sizeof(int),TAM);
	//O pVector = (int*) malloc (sizeof(int)*TAM);


	if(cargarVector(pVector, TAM, arrayNumeros) == 0){
		puts("\nError al cargar el vector de numeros\n");
	}

	if(mostrarVector(pVector, TAM) == 0){
			puts("\nError al mostrar el vector de numeros\n");
	}

	if(pedirEntero("\nIngrese el numero a eliminar en el array: ", &numero) == 0){
		puts("\nError al cargar el numero\n");
	}

	if(reemplazarEnVector(pVector, TAM, numero) == 0){
		puts("\nError al reemplazar el numero\n");
	}

	printf("\nNumero %d eliminado de la cadena, cadena reducida de %d a %d\n\n", numero, TAM, TAM-1);

	if(mostrarVector(pVector, TAM-1) == 0){
			puts("\nError al mostrar el vector de numeros despues de realizar el realloc\n");
	}

}

