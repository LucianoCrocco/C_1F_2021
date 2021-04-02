/*
 * main.c
 *
 *  Created on: 29 mar. 2021
 *      Author: luciano
 */

#include <stdio.h>
#include <stdlib.h>

#define TAMANIO_LISTA 5

int main (void){

	int listaNumeros[TAMANIO_LISTA]={};//={5,2}; //Son espacios finitos, con {} podemos harcodear y si dejamos espacios vacios el lenguaje setea el resto en 0
	//Inicializo en 0 pq es un ilogico, por ahora.
	int i;

	setbuf(stdout,NULL);


/*
	printf("%d", &listaNumeros); //-> Direccion de memoria numerica del vector
	printf("\n");
	printf("%p", listaNumeros); //-> Direccion de memoria hexagecimal del vector
	printf("\n");

	for(i=0;i<TAMANIO_LISTA;i++){
		printf("%d\n",&listaNumeros[i]); -> La direccion de memoria de cada vector
	}
*/
	int posicion;
	char respuesta;

	for(i=0;i<TAMANIO_LISTA;i++){ //Inicializo el programa
		listaNumeros[i] = -1;
	}
	// Tipos de cargas, secuencial y aleatoria:

	// Carga Aleatoria
	do {
		printf("Ingrese una posicion 1-5: ");
		scanf("%d",&posicion);
		printf("Ingrese un numero: ");
		scanf("%d",&listaNumeros[posicion-1]);

		printf("Desea ingresar otro numero? Y o N: ");
		__fpurge(stdin);
		scanf("%c",&respuesta);
	}while(respuesta != 'N');

	for(i=0;i<TAMANIO_LISTA;i++){
		if(listaNumeros[i] != -1){
			printf("El numero en el vector %d es: %d",i,listaNumeros[i]);
		}
	}


/*
	//Secuencial:
	for(i=0;i<TAMANIO_LISTA;i++){
		printf("Ingrese un numero en el vector [%d]: ", i);
		scanf("%d",&listaNumeros[i]);
	}

	printf("\n");

	for(i=0;i<TAMANIO_LISTA;i++){
		printf("El numero del vector %d es %d\n", i, listaNumeros[i]);
	}
*/

	return EXIT_SUCCESS;
}
