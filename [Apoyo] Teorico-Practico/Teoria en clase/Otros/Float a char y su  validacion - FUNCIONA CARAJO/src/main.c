/*
 * main.c
 *
 *  Created on: 2 abr. 2021
 *      Author: luciano
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validarEsFloat(char numero[], int len);
void printStringOfNUmbers(char numero[]);

int main (void){

	int validacion;
	int numero;
	float numero2;
	char pasarNumero[100];
	char pasarNumero2[100];

	numero = 200;
	numero2 = 10.3213;

	setbuf(stdout,NULL);
	sprintf(pasarNumero, "%d", numero);
	sprintf(pasarNumero2,"%f", numero2);



	validacion=validarEsFloat(pasarNumero, 100);
	if(validacion == 1){
		printf("Es Float\n");
	} else {
		printf("No es float\n");
	}
	printStringOfNUmbers(pasarNumero);

	printf("\n ------ LINEA SEPARADORA ------ \n\n");

	validacion=validarEsFloat(pasarNumero2, 100);
		if(validacion == 1){
			printf("Es Float\n");
		} else {
			printf("No es float\n");
		}
		printStringOfNUmbers(pasarNumero2);


	return EXIT_SUCCESS;
}

int validarEsFloat(char numero[], int len){
	int i;

	int flag;

	for(i=0;i<len;i++){
		if((numero[i] >= '0' && numero[i] <= '9')|| numero[i] != '\0' || numero[i] == '.'){
			flag = 1;
		} else {
			flag = -1;
			}
	}

	return flag;
}

void printStringOfNUmbers(char numero[]){

	int i;

	for(i=0;i<100;i++){
		if(numero[i] == '\0'){
			break;
		} else {
			printf("Posicion %d Numero: %c\n", i, numero[i]);
		}
	}

}
