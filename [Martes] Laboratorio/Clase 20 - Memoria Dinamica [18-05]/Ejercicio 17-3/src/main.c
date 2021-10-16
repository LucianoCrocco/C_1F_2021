/*
 * main.c
 * Realizar una función que reciba como parámetro un array de enteros, su tamaño, un valor entero y un índice.
 * La función se encargará de insertar el valor entero en el índice especificado. El array deberá reestructurarse dinámicamente.
 */
#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main (void){
	int* pVector;
	int arrayNumeros[5]={9,2,4,5,6};
	int numero;
	int index;

	pVector = (int*) calloc (sizeof(int),TAM);
	//O pVector = (int*) malloc (sizeof(int)*TAM);


	if(cargarVector(pVector, TAM, arrayNumeros) == 0){
		puts("\nError al cargar el vector de numeros\n");
	}

	if(mostrarVector(pVector, TAM) == 0){
			puts("\nError al mostrar el vector de numeros\n");
	}

	if(pedirEntero("\nIngrese el numero a insertar en el array: ", &numero) == 0){
		puts("\nError al cargar el numero\n");
	}

	if(pedirEnteroConRango(&index, "Ingrese el index donde se desea insertar el entero: ", "Error, ingrese un index valido", 0, 4, 3) == 0){
		puts("\nError al cargar el numero\n");
	}

	if(insertarEnVector(pVector, TAM, numero, index) == 0){
		puts("\nError al insertar el numero\n");
	}

	printf("\nNumero %d insertado en la cadena, cadena ampliada de %d a %d\n\n", numero, TAM, TAM+1);

	if(mostrarVector(pVector, TAM+1) == 0){
			puts("\nError al mostrar el vector de numeros despues de realizar el realloc\n");
	}

}

