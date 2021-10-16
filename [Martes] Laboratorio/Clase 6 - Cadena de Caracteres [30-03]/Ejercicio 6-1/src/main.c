/*
 *  Luciano Crocco 1ºF
 *  Ejercicio 6-1
 *      Disponemos de dos variables numéricas (a y b).
 *      Realizar un algoritmo que permita el intercambio de valores de dichas variables.
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main (void){
	int a;
	int b;
	int aux;

	setbuf(stdout,NULL);
	a = pedirEntero("Ingrese el primer numero: ", "Error...Ingrese un numero valido", 0, 0);
	b = pedirEntero("Ingrese el segundo numero: ", "Error...Ingrese un numero valido", 0, 0);

	aux = a;
	//a = intercambioDeValores(a,b);
	//b = intercambioDeValores(b,aux);
	a = b;
	b = aux;

	printf("El primer numero ahora es: %d\n", a);
	printf("El segundo numero ahora es: %d\n", b);


	return EXIT_SUCCESS;

}


