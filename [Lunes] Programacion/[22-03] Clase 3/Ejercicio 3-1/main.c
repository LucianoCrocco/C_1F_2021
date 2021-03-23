/*
 * Luciano Crocco 1ºF
 *
 * Ejercicio 3-1
 *
 * Crear una función que permita determinar si un número es par o no.
 * La función retorna 1 en caso afirmativo y 0 en caso contrario. Probar en el main.
 *
 */

#include <stdio_ext.h>
#include <stdlib.h>


int checkPar (int x);

int main (){

	int x;
	int resultado;

	setbuf(stdout,NULL);

	printf("Ingrese un numero para determinar si es par o no: ");
	scanf("%d",&x);
	resultado = checkPar(x);

	if(resultado == 1){
		printf("El numero %d es par", x);
	} else {
		printf("El numero %d NO es par", x);
	}

	return EXIT_SUECCESS;
}

int checkPar (int x){
	int resultado;

	resultado = 0;

	if(x % 2 == 0){
		resultado = 1;
	}

	return resultado;
}
