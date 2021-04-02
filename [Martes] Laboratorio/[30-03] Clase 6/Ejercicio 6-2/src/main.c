/*
 * Luciano Crocco 1ºF
 * Ejercicio 6-2
 *
 * Realizar un programa que permita el ingreso de 10 números enteros (positivos y negativos). Necesito generar un listado de los números positivos de manera creciente y negativos de manera decreciente. (Como máximo 4 for)
 */



#include <stdio.h>
#include <stdlib.h>
#define TAMANIO 10

void mostrarNumeros(int listaNumeros[], int tamanio);
void ordenarNumeros(int listaNumeros[], int tamanio);

int main (void){

	int listaNumeros[TAMANIO];
	int i;

	setbuf(stdout,NULL);

	for(i=0;i<TAMANIO;i++){
		printf("Ingrese el %dº numero: ", i+1);
		scanf("%d",&listaNumeros[i]);
	}

	printf("------ Lista de numeros sin ordenar ------\n");
	mostrarNumeros(listaNumeros, TAMANIO);

	ordenarNumeros(listaNumeros, TAMANIO);


	printf("------ Lista de numeros ordenados ------\n");
	mostrarNumeros(listaNumeros,TAMANIO);




	return EXIT_SUCCESS;
}

void mostrarNumeros(int listaNumeros[], int tamanio){

	int i;


	for(i=0;i<tamanio;i++){
		printf("Numero: %d\n", listaNumeros[i]);
	}
}

void ordenarNumeros(int listaNumeros[], int tamanio){
	int i;
	int j;
	int aux;

	for(i=0;i<TAMANIO-1;i++){
		for(j=i+1;j<TAMANIO;j++){
			if(listaNumeros[i] > listaNumeros[j]){
				if(listaNumeros[i] >= 0){
					aux = listaNumeros[i];
					listaNumeros[i] = listaNumeros[j];
					listaNumeros[j] = aux;
				}
			}
			if(listaNumeros[i] > listaNumeros[j]){
				if(listaNumeros[i] < 0){
					aux = listaNumeros[i];
					listaNumeros[i] = listaNumeros[j];
					listaNumeros[j] = aux;
				}
			}
		}
	}
}
