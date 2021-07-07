/*
 * main.c
 *
 *  Created on: 23 jun. 2021
 *      Author: luciano
 */


#include <stdio.h>
#include "bibliotecaGen.h"
#include <stdlib.h>
#include <float.h>

int main (void){

	setbuf(stdout, NULL);
	//char nombre[15];
	//get_Name(nombre, "Ingrese el nombre: ", "Error... los caracteres no son alfabeticos o la capacidad de caracteres fue excedida, capacidad maxima: ", 5, 15);

	//printf("\n\n%s", nombre);
	/*int numero;

	get_Integer(&numero,"Ingrese numero: ", "Error... ", -1000000, 1000000, 5);

	printf("\n\n%d\n\n", numero);
*/
	float flot;
	get_Float(&flot, "Ingrese flotante: ", "Error... ", -1000000, 1000000, 5);
	printf("\n\n%f\n\n", flot);

	return EXIT_SUCCESS;
}
