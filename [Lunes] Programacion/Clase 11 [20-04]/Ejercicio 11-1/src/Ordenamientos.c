/*
 * Ordenamientos.c
 *
 *  Created on: 24 abr. 2021
 *      Author: luciano
 */

#ifndef ORDENAMIENTOS_C_
#define ORDENAMIENTOS_C_

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Estructuras.h"

//								CASE 5
void insertionSortNumbPrecio(eProductos lista[], int lenghtArray){
	int i;
	int j;
	eProductos aux;


	for(i=1;i<lenghtArray;i++){
		aux = lista[i];
		j=i-1;
		while(j>=0 && aux.precio < lista[j].precio){
			lista[j+1] = lista[j];
			j--;
		}
		lista[j+1]= aux; //insercion
	}
}

//								CASE 6
void insertionSortNumbDescripcion(eProductos lista[], int lenghtArray){
	int i;
	int j;
	eProductos aux;


	for(i=1;i<lenghtArray;i++){
		aux = lista[i];
		j=i-1;
		while(j>=0 && strcmp(aux.descripcion,lista[j].descripcion) < 0){
			lista[j+1] = lista[j];
			j--;
		}
		lista[j+1]= aux; //insercion
	}
}

#endif /* ORDENAMIENTOS_C_ */
