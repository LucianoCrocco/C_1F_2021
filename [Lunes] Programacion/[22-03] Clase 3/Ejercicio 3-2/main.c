/*
 * Luciano Crocco 1ºF
 * Ejercicio 3-2:
 * Crear una función que muestre por pantalla el número flotante  que recibe como parámetro.
 *
 */

#include <stdio_ext.h>
#include <stdlib.h>

void mostrarFlotante(float numeroUno);

int main(){

	float x;

	setbuf(stdout,NULL);

	printf("Ingrese un numero con decimales: ");
	scanf("%f",&x);
	mostrarFlotante(x);
	
	return EXIT_SUCCESS;
}

void mostrarFlotante(float numeroUno){
	printf("El numero flotante ingresado es: %f", numeroUno);
}
