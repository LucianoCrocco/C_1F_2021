/*
 * Luciano Crocco 1ºF Ejercicio 15-5
 *
 * Escriba una función que reciba dos números enteros y los devuelva ordenados.
 * Es decir que en el primer parámetro debe devolver el menor valor y en el 2do. el mayor
 */
#include <stdio.h>
#include <stdlib.h>

int ordenar_Numeros(int* numeroUno, int* numeroDos);

int main (void){

	setbuf(stdout,NULL);
	int numeroUno=100;
	int* pEnteroUno = &numeroUno;
	int numeroDos=1;
	int* pEnteroDos = &numeroDos;

	if(ordenar_Numeros(pEnteroUno,pEnteroDos)){
		printf("Numeros ordenados, Nº1: %d ---- Nº2: %d", numeroUno, numeroDos);
	} else {
		puts("Error en la funcion ordenar numeros\n");
	}

	return EXIT_SUCCESS;
}

int ordenar_Numeros(int* numeroUno, int* numeroDos){
	int aux;

	if(numeroUno != NULL && numeroDos != NULL){
		if(*numeroUno > *numeroDos){
			aux = *numeroUno;
			*numeroUno = *numeroDos;
			*numeroDos = aux;
		}
	} else {
		return 0;
	}

	return 1;
}
