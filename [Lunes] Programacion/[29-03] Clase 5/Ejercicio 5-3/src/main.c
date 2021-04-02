/*
 * Luciano Crocco
 * Ejercicio 5-3
 *
 *Realizar un programa que permita el ingreso de 10 números enteros distintos de cero.
 *Realizar La carga deberá ser aleatoria (todos los elementos se inicializaran en cero por default. Determinar el promedio de los positivos, y del menor de los negativos la suma de los antecesores.
 *Realizar Utilizar funciones y vectores.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#define TAMANIO 3

int main (void){

	int listaNumeros[TAMANIO];
	int posicion;
	int numero;
	int opcion;


	setbuf(stdout,NULL);

	//A
	inicializarArray(listaNumeros, TAMANIO, 0);



	do{
		printf("¿Desea ingresar un numero? 1.Si --- 2.No: ");
		scanf("%d",&opcion);
		posicion=pedirPosicion("Ingrese la posicion en la cual desea cargar el numero, hay", "Error... la posicion ingresada NO es valida.", listaNumeros, TAMANIO);

		numero=pedirEntero("Ingrese el numero que quiere ingresar en esa posicion: ", "Error... el numero ingresado NO es valido.",0 , 0);

		cargarNumeroArray(listaNumeros, TAMANIO, numero, posicion);

	}while(opcion!=2);

	//B
	printSumaPositivos(listaNumeros, TAMANIO);

	//C
	printsumaNegAntecesores(listaNumeros, TAMANIO);







	return EXIT_SUCCESS;
}
