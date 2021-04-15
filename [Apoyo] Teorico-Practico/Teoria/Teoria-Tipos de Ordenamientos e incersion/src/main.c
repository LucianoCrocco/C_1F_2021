/*
 * Realizar ordenamientos por burbuja, burbuja mas eficiente y metodo de incercion.
 * Mirar los apuntes de arrays y ver video UTN.
 * 	-> Para hacerlo hacerlo con un return, que retorno la cantidad de veces que itero el programa.
 *
 * 	 * LAS FUNCIONES SON PARA PROBAR LAS ITERACIONES, SI LAS QUIERO USAR PARA UNA BIBLIOTECA TENGO QUE CAMBIARLAS PARA HACERLAS GENERICAS (retorno -1 x ej, void , comprobaciones de NULL, sacar contadores, etc)
 * 	 El menu esta hecho como el CULO.
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

#define QTY_NUMBERS 7

int main(void){

	int opcion;
	int opcionBurbujeo;
	int iteraciones;


	int numerosDesordenados[QTY_NUMBERS]={20,10,70,0,101,47,5};
	int numerosOrdenados[QTY_NUMBERS]={0,5,10,20,47,70,101};

	setbuf(stdout,NULL);

	printf("Iteraciones con numeros ordenados: 1 || Iteraciones con numeros desordenados: 2 || Salir: 3 ->  ");
	scanf("%d",&opcion);

	do{
		switch(opcion){
			case 1:
				printf("\n\nIteraciones con el metodo de burbujeo: 1 || Iteraciones con el metodo de burbujeo eficiente:  2 || Iteraciones con el metodo de insercion: 3 || case 4: Salir ->  ");
				scanf("%d",&opcionBurbujeo);
				do{
					switch(opcionBurbujeo){
						case 1:
							iteraciones = simpleBubbleSortNumbs(numerosOrdenados, QTY_NUMBERS);
							printArray(numerosOrdenados, QTY_NUMBERS, "El numero de en la posicion ");
							printf("La cantidad de iteraciones con el metodo de burbujeo y los numeros ordenados es de: %d", iteraciones);
							system("clear");
							break;
						case 2:
							iteraciones = efficientBubbleSortNumbs(numerosOrdenados, QTY_NUMBERS);
							printArray(numerosOrdenados, QTY_NUMBERS, "El numero de en la posicion ");
							printf("La cantidad de iteraciones con el metodo de burbujeo EFICIENTE y los numeros ordenados es de: %d", iteraciones);
							break;
						case 3:
							iteraciones = insertionSortNumb(numerosOrdenados, QTY_NUMBERS);
							printArray(numerosOrdenados, QTY_NUMBERS, "El numero de en la posicion ");
							printf("La cantidad de iteraciones con el metodo insercion y los numeros ordenados es de: %d", iteraciones);
							break;
					}
					break;
				}while(opcionBurbujeo != 4);
				break;


			case 2:
				printf("\n\nIteraciones con el metodo de burbujeo: 1 || Iteraciones con el metodo de burbujeo eficiente:  2 || Iteraciones con el metodo de insercion: 3 || case 4: Salir ->  ");
				scanf("%d",&opcionBurbujeo);

				do{
					switch(opcionBurbujeo){
					case 1:
						iteraciones = simpleBubbleSortNumbs(numerosDesordenados, QTY_NUMBERS);
						printArray(numerosOrdenados, QTY_NUMBERS, "El numero de en la posicion ");
						printf("La cantidad de iteraciones con el metodo de burbujeo y los numeros desordenados es de: %d", iteraciones);
						break;
					case 2:
						iteraciones = efficientBubbleSortNumbs(numerosDesordenados, QTY_NUMBERS);
						printArray(numerosOrdenados, QTY_NUMBERS, "El numero de en la posicion ");
						printf("La cantidad de iteraciones con el metodo de burbujeo EFICIENTE y los numeros desordenados es de: %d", iteraciones);
						break;
					case 3:
						iteraciones = insertionSortNumb(numerosDesordenados, QTY_NUMBERS);
						printArray(numerosOrdenados, QTY_NUMBERS, "El numero de en la posicion ");
						printf("La cantidad de iteraciones con el metodo insercion y los numeros desordenados es de: %d", iteraciones);
						break;
					}
					break;
				}while(opcionBurbujeo != 4);
				break;
		}

	}while(opcion != 3);


	return EXIT_SUCCESS;
}
