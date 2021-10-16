/*
 * Luciano Crocco
 * Ejercicio 5-1
 *
 * Pedir el ingreso de 5 números. Mostrarlos y calcular la sumatoria de los mismos.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#define TAMANIO 5

int main (void){

	int listaNumeros[TAMANIO];
	int suma;

	setbuf(stdout,NULL);

	cargarNumeros(listaNumeros, TAMANIO);

	mostrarNumeros(listaNumeros, TAMANIO);

	suma = sumarNumeros(listaNumeros, TAMANIO);
	printf("La suma de todos los numeros es de: %d", suma);


	return EXIT_SUCCESS;
}

