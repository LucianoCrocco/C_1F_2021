/*
 * Luciano Crocco
 * Ejercicio 5-2
 *
 * Pedir el ingreso de 10 números enteros entre -1000 y 1000. Determinar:
	Cantidad de positivos y negativos.
	Sumatoria de los pares.
	El mayor de los impares.
	Listado de los números ingresados.
	Listado de los números pares.
	Listado de los números de las posiciones impares.
	Se deberán utilizar funciones y vectores.

 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#define TAMANIO 10

int main (void){

	int listaNumeros[TAMANIO];

	setbuf(stdout,NULL);

	cargarNumeros(listaNumeros, TAMANIO, -1000, 1000);

	//A - Cantidad de positivos y negativos
	printf("A\n");
	printContadorNumerosNegativos(listaNumeros, TAMANIO);
	printContadorNumerosPositivos(listaNumeros, TAMANIO);
	printf("\n");

	//B - Sumatoria de los pares.
	printf("B\n");
	printSumarNumerosPares(listaNumeros, TAMANIO);
	printf("\n");

	//C - El mayor de los impares.
	printf("C\n");
	printNumeroImparMasGrande(listaNumeros, TAMANIO);
	printf("\n");

	//D - Listado de los números ingresados.
	printf("D\n");
	mostrarNumeros(listaNumeros, TAMANIO);
	printf("\n");

	//E - Listado de los números pares.
	printf("E\n");
	printNumerosPares(listaNumeros, TAMANIO);
	printf("\n");

	//F - Listado de los números de las posiciones impares.
	printf("F\n");
	printNumerosPosImpares(listaNumeros, TAMANIO);
	printf("\n");



	return EXIT_SUCCESS;
}
