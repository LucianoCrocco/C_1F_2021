/*
 * Funciones.c
 *
 *  Created on: 29 mar. 2021
 *      Author: luciano
 */
#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

void cargarNumeros(int arrayNumeros[], int tamanio){

	int i;

	for(i=0;i<tamanio;i++){
		printf("Ingrese el %dº numero: ", i+1);
		scanf("%d",&arrayNumeros[i]);
	}
}

int sumarNumeros(int arrayNumeros[], int tamanio){
	int i;
	int acumulador;

	acumulador = 0;

	for(i=0;i<tamanio;i++){
		acumulador += arrayNumeros[i];
	}

	return acumulador;
}

void mostrarNumeros(int arrayNumeros[], int tamanio){

	int i;

	for(i=0;i<tamanio;i++){
		printf("El numero del vector %d es: %d \n", i, arrayNumeros[i]);
	}
}
