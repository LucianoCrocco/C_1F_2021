/*
 * array.c
 *
 *  Created on: 29 may. 2021
 *      Author: luciano
 */

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int pedirEntero(char* mensaje, int* pResultado){
	int rtn;
	rtn = 1;
	if(mensaje != NULL){
		printf("%s",mensaje);
		scanf("%d", pResultado);
	} else {
		return 0;
	}

	return rtn;

}

int cargarVector (int* pVector, int tamanio, int* arrayNumeros){
	int i;
	if(pVector != NULL && tamanio >= 0){
		for(i=0;i<tamanio;i++){
			*(pVector+i) = arrayNumeros[i];
		}
	} else {
		return 0;
	}
	return 1;
}

int mostrarVector(int* pVector, int tamanio){
	int i;
	if(pVector != NULL && tamanio >= 0){
		for(i=0;i<tamanio;i++){
			printf("Numero en posicion %d: %d\n", i, *(pVector+i));
		}
	} else {
		return 0;
	}
	return 1;
}

int reemplazarEnVector(int* pVector, int tamanio, int numero){
	int i;
	int j;
	int aux;
	int flag;

	j=-1;
	flag = 0;

	if(pVector != NULL && tamanio >= 0){
		for(i=0;i<tamanio;i++){
			if(*(pVector+i)==numero && flag == 0){
				j=i;
				flag++;
			} else{
				if(j>=0){
					aux=*(pVector+i);
					*(pVector+j) = aux;
					j++;
				}
			}
		}
	} else {
		return 0;
	}

	pVector = (int*) realloc (pVector, sizeof(int)*(TAM-1));

	return 1;
}
