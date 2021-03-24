/*
 * Luciano Crocco 1ºF
 * Ejercicio 3-4
 * Realizar un programa en donde se puedan utilizar los prototipos de la función Sumar en sus 4 combinaciones.
 *
 * int Sumar1(int, int);
 * int Sumar2(void);
 * void Sumar3(int, int);
 * void Sumar4(void);
 *
 */

#include <stdio_ext.h>
#include <stdlib.h>

int pedirEntero(char mensaje[], char mensajeError[], int minimo, int maximo);
char PedirCaracter(char mensaje[], char mensajeError[]);
float pedirFloat(char mensaje[], char mensajeError[], float minimo, float maximo);

int pedirEntero(char mensaje[], char mensajeError[], int minimo, int maximo){

	int x;

	printf("%s",mensaje);
	scanf("%d",&x);
	if(minimo != maximo && maximo != minimo){
		while(x>maximo || x<minimo){
			printf("%d es el minimo --- %d es el maximo", minimo, maximo);
			printf("%s",mensajeError);
			printf("\n%s",mensaje);
			scanf("%d",&x);
		}
	}
	return x;
}

float pedirFloat(char mensaje[], char mensajeError[], float minimo, float maximo){

	float x;

	printf("%s",mensaje);
	scanf("%f",&x);
	if(minimo != maximo && maximo != minimo){
		while(x>maximo || x<minimo){
			printf("%f es el minimo --- %f es el maximo", minimo, maximo);
			printf("%s",mensajeError);
			printf("\n%s",mensaje);
			scanf("%f",&x);
		}
	}
	return x;
}

char PedirCaracter(char mensaje[], char mensajeError[]){

	char x;

	printf("%s",mensaje);
	__fpurge(stdin);
	scanf("%c",&x);
	while(x==NULL){
		printf("%s",mensajeError);
		printf("\n%s",mensaje);
		__fpurge(stdin);
		scanf("%c",&x);
	}
	return x;
}
