/*
 * main.c
 *
 *  Created on: 23 mar. 2021
 *      Author: luciano
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include "Funciones.h"

int main (void){


	int i;
	int x;
	unsigned int resultado;

	resultado = 1;

	setbuf(stdout,NULL);

	printf("Ingrese un numero para calcular el factorial(Sin funcion): ");
	scanf("%d",&x);

	if(x == 1 || x == 0){
		resultado = 1;
	} else{
		for(i=x;i>1;i--){
			resultado = resultado * (i);
		}
	}

	printf("(Sin funcion) El factorial de %d es: %d", x, resultado);


	int factorial;
	int numero;

	numero = 5;

	factorial = calcularFactorial(numero);
	printf("\n(Con funcion)El factorial de %d es: %d", numero, factorial);


	return EXIT_SUCCESS;

}
