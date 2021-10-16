/*
 * Luciano Crocco 1ºF Ejercicio 15-6
 *
 * Realizar una función que reciba como parámetros dos vectores.
 * La función deberá determinar si el segundo vector está contenido en el primero.
 */
#include <stdio.h>
#include <stdlib.h>

#define TAM_PRIMER_VECTOR 5
#define TAM_SEGUNDO_VECTOR 8

int contiene_Elementos(int* pVectorUno, int tamVectorUno, int* pVectorDos, int tamVectorDos);

int main (void){

	setbuf(stdout,NULL);

	int arrayNumeros_uno[TAM_PRIMER_VECTOR]={1,7,11,10,8};
	int* pVectorUno;
	pVectorUno = arrayNumeros_uno;

	int arrayNumeros_dos[TAM_SEGUNDO_VECTOR]={1,7,11,10,8,100,1001,10002};
	int* pVectorDos;
	pVectorDos = arrayNumeros_dos;

	if(contiene_Elementos(pVectorUno, TAM_PRIMER_VECTOR, pVectorDos, TAM_SEGUNDO_VECTOR) != 0){
		puts("El vector dos contiene al vector uno");
	} else {
		puts("El vector dos NO contiene al vector uno");
	}

	return EXIT_SUCCESS;
}

int contiene_Elementos(int* pVectorUno, int tamVectorUno, int* pVectorDos, int tamVectorDos){

	int i;
	int j;
	int contador = 0;

	for(i=0;i<tamVectorUno;i++){
		for(j=0;j<tamVectorDos;j++){
			if(pVectorUno[i]==pVectorDos[j]){
				contador++;
				break;
			}
		}
	}

	if(contador == tamVectorUno){
		return contador;
	} else {
		return 0;
	}
}
