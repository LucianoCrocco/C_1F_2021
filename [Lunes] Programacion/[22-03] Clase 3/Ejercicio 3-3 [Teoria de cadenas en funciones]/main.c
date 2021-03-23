/*
 *
 * Luciano Crocco 1ºF
 * Ejercicio 3-3:
 * Crear una función que pida el ingreso de un entero y lo retorne.
 *

 */

#include <stdio_ext.h>
#include <stdlib.h>

int pedirEntero(char mensaje[], char mensajeError[], int minimo, int maximo);

int main(void){
	int unNumero;

	setbuf(stdout,NULL);

	unNumero = pedirEntero("Ingrese un numero del 0 a 100: ", 0, 100,"Error... los valores validos estan entre entre 0 y 100");
	printf("Se ingreso el numero %d en la funcion pedirNumero", unNumero);

	return EXIT_SUCCESS;
}

int pedirEntero(char mensaje[], char mensajeError[], int minimo, int maximo){
	int x;

	printf("%s",mensaje);
	scanf("%d",&x);
	while(x>100 || x<0){
	    printf("%s",mensajeError);
	    printf("\n%s",mensaje);
	    scanf("%d",&x);
	}

	return x;
}
