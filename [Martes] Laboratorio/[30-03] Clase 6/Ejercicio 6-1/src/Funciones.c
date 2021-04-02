/*
 * Funciones.c
 *
 *  Created on: 30 mar. 2021
 *      Author: luciano
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int pedirEntero(char mensaje[], char mensajeError[], int minimo, int maximo){
	int x;

	printf("%s",mensaje);
	scanf("%d",&x);
	if(maximo != minimo){
		while(x>maximo || x<minimo){
			printf("%s",mensajeError);
			printf("\n%s",mensaje);
			scanf("%d",&x);
		}
	}

	return x;
}

int intercambioDeValores(int numero, int numeroAIntercambiar){

	numero = numeroAIntercambiar;

	return numero;
}

