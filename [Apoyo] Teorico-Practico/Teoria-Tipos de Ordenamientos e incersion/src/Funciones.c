/*
 * Funciones.c
 *
 *  Created on: 25 mar. 2021
 *      Author: luciano
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"


int simpleBubbleSortNumbs(int numbers[], int len){
	int i;
	int j;
	int aux;
	int contador;

	contador = 0;

	for(i=0;i<len-1;i++){
		for(j=i+1;j<len;j++){
			contador++;
			if(numbers[i] > numbers[j]){
				aux = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = numbers[i];
			}
		}
	}
	return contador;
}


int efficientBubbleSortNumbs(int number[], int len){
	int i;
	int aux;
	int contador;
	int flagNoEstaOrdenado;

	flagNoEstaOrdenado = 1;
	contador = 0;

	while(flagNoEstaOrdenado== 1){
		flagNoEstaOrdenado = 0;
		for(i=1;i<len;i++){
			contador ++;
			if(number[i] < number[i-1]){
				aux = number[i];
				number[i] = number[i-1];
				number[i-1] = number[i];
				flagNoEstaOrdenado = 1;
			}
		}
	}

	return contador;
}


int insertionSortNumb(int number[], int len){
	int i;
	int j;
	int aux;
	int contador;

	contador = 0;

	for(i=1;i<len;i++){
		aux = number[i];
		j=i-1;
		//contador++;
		while(j>=0 && aux < number[j]){
			number[j+1] = number[j];
			contador++;
			j--;
		}
		number[j+1]= aux; //insercion
	}

	return contador;
}

void printArray(int array[], int len, char mensaje[]){

	int i;

	if(array != NULL && len > 0){
		for(i=0;i<len;i++){
			printf("%s %d, es el numero: %d\n", mensaje, i, array[i]);
		}
	}

}
