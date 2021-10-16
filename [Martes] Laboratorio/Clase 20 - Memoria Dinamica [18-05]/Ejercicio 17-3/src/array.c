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


int insertarEnVector(int* pVector, int tamanio, int numero, int index){
	int aux;
	int newAux;
	int i;
	int flag = 0;

	if(pVector != NULL && tamanio >= 0){
		for(i=0;i<tamanio+1;i++){
			if(i==index){
				pVector = (int*) realloc (pVector, sizeof(int)*(TAM+1));
				aux = pVector[i];
				pVector[index] = numero;
				flag++;
			} else {
				if(flag != 0){
					newAux = pVector[i];
					pVector[i] = aux;
					aux = newAux;
				}
			}
		}
	} else {
		return 0;
	}

	return 1;
}


int pedirEnteroConRango(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
	int numero;
	int rtn;

	rtn = 0;

	if(mensaje !=NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
		printf("%s",mensaje);
		scanf("%d",&numero);
		while((numero < minimo || numero > maximo) && reintentos >= 0){
			printf("\n%s, reintentos restantes: %d\n\n",mensajeError, reintentos);
			printf("%s",mensaje);
			scanf("%d",&numero);
		}
	} else {
		return 0;
	}

	if((numero >= minimo && numero <= maximo) && reintentos >= 0){
		rtn = 1;
		*pResultado = numero;
	}

	return rtn;
}
