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

int sumar1(int, int);
int sumar2(void);
void sumar3(int, int);
void sumar4(void);

void mostrarSuma (char mensaje[], int resultado);

int main(void){
	int resultado;

	setbuf(stdout,NULL);

	resultado = sumar1(0,0);
	mostrarSuma("El resultado de la funcion suma1 es: ", resultado);

	resultado = sumar2();
	mostrarSuma("El resultado de la funcion suma2 es: ", resultado);

	sumar3(0, 0);

	sumar4();

	return EXIT_SUCCESS;
}


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

int sumar1(int x, int y){

	int resultado;

	x = pedirEntero("Ingrese el primer numero: ", "Error... ingrese un numero valido dentro de los parametros", 0, 0);
	y = pedirEntero("Ingrese el segundo numero: ", "Error... ingrese un numero valido dentro de los parametros", 0, 0);
	resultado = x + y;

	return resultado;
}

int sumar2(void){

	int x;
	int y;

	int resultado;

	x = pedirEntero("Ingrese el primer numero: ", "Error... ingrese un numero valido dentro de los parametros", 0, 0);
	y = pedirEntero("Ingrese el segundo numero: ", "Error... ingrese un numero valido dentro de los parametros", 0, 0);

	resultado = x + y;

	return resultado;
}

void mostrarSuma(char mensaje[], int resultado){

	if(mensaje != NULL){
		printf("%s %d\n\n", mensaje, resultado);
	}
}

void sumar3(int x, int y){
	int resultado;

	x = pedirEntero("Ingrese el primer numero: ", "Error... ingrese un numero valido dentro de los parametros", 0, 0);
	y = pedirEntero("Ingrese el segundo numero: ", "Error... ingrese un numero valido dentro de los parametros", 0, 0);

	resultado = x + y;

	mostrarSuma("El resultado de la funcion suma3 es: ", resultado);

}

void sumar4(void){
	int x;
	int y;
	int resultado;

	x = pedirEntero("Ingrese el primer numero: ", "Error... ingrese un numero valido dentro de los parametros", 0, 0);
	y = pedirEntero("Ingrese el segundo numero: ", "Error... ingrese un numero valido dentro de los parametros", 0, 0);

	resultado = x + y;

	mostrarSuma("El resultado de la funcion suma4 es: ", resultado);
}
