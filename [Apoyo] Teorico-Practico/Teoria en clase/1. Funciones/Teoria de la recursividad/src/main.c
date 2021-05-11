/******************************************************************************

Luciano Crocco

¿Porqué no usarlas?

	-> Creación de múltiples variables en memoria.

	-> Consumen demasiada memoria en la pila.

	->	Si son mal programadas pueden desbordar la memoria (StackOverFlow)

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int calcularFactorial(int numero);

int main (void){

	int x;
	unsigned int resultado;

	resultado = 1;

	printf("Ingrese un numero para calcular el factorial: ");
	scanf("%d",&x);

	resultado = calcularFactorial(x);

	printf("El factorial de %d es: %d", x, resultado);



	return EXIT_SUCCESS;

}

int calcularFactorial(int numero){
	int resultado;

	if(numero == 0){

		resultado = 1;

	} else {

		resultado = numero * calcularFactorial(numero - 1);

	}

	return resultado;
}
