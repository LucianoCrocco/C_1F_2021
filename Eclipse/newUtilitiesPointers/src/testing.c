/*
 * testing.c
 *
 *  Created on: 14 may. 2021
 *      Author: luciano
 */


#include <stdio_ext.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "testing.h"

/************************************************************************************************************/
/***************************************************VIEJAS***************************************************/
/************************************************************************************************************/
int pedirFloat(char* mensaje, float* pResultado){

	int rtn;
	rtn = 1;
	if(mensaje != NULL){
		printf("%s",mensaje);
		scanf("%f", pResultado);
	} else {
		return 0;
	}

	return rtn;

}

int pedirFloatConRango(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos){
	float numero;
	int rtn;

	rtn = 0;

	if(mensaje !=NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
		printf("%s",mensaje);
		scanf("%f",&numero);
		while((numero < minimo || numero > maximo) && reintentos >= 0){
			printf("\n%s, reintentos restantes: %d\n\n",mensajeError, reintentos);
			printf("%s",mensaje);
			scanf("%f",&numero);
		}
	} else {
		return 0;
	}

	if((numero >= minimo && numero <= maximo) && reintentos >= 0){
		rtn = 1;
		*pResultado = numero;
	}
	return rtn;

}

int pedirEntero(char* mensaje, int* pResultado){
	int rtn;
	rtn = 1;
	if(mensaje != NULL){
		printf("%s",mensaje);
		scanf("%d", pResultado);
	} else {
		return 0;
	}

	return rtn;

}

int pedirEnteroConRango(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
	int numero;
	int rtn;

	rtn = 0;

	if(mensaje !=NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
		printf("%s",mensaje);
		scanf("%d",&numero);
		while((numero < minimo || numero > maximo) && reintentos >= 0){
			printf("\n%s, reintentos restantes: %d\n\n",mensajeError, reintentos);
			printf("%s",mensaje);
			scanf("%d",&numero);
		}
	} else {
		return 0;
	}

	if((numero >= minimo && numero <= maximo) && reintentos >= 0){
		rtn = 1;
		*pResultado = numero;
	}

	return rtn;
}


/************************************************************************************************************/
/***************************************************NUEVAS***************************************************/
/************************************************************************************************************/

int get_Char (char* pResult, char* msg, char* errorMsg, char min, char max, int retries){

	int rtn;
	char buffer;

	rtn = 0;

	if(pResult != NULL && msg != NULL && errorMsg != NULL && min <= max && retries >= 0){
		do{
			printf("%s", msg);
			__fpurge(stdin);
			scanf("%c", &buffer);
			if(buffer >= min && buffer <= max){
				*pResult = buffer;
				rtn = 1;
				break;
			} else {
				printf("%s\n", errorMsg);
				printf("Reintentos disponibles: %d\n\n", retries);
				retries--;
			}

		}while(retries >= 0);
	} else {
		puts("NO entro al if\n");
	}

	return rtn;
}

int get_String(char* pResult, char* msg, char* errorMsg, int retries, int lenght){
	int rtn;
	char bufferString[lenght*4];

	rtn = 0;

	if(pResult != NULL && msg != NULL && errorMsg != NULL && retries >= 0 && lenght > 0){
		do{
			printf("%s", msg);
			__fpurge(stdin);
			scanf("%[^\n]", bufferString);
			if(strlen(bufferString) > lenght-1){
				printf("%s %d\n", errorMsg, lenght-1);
				printf("Reintentos disponibles: %d\n\n", retries);
				retries--;
			} else {
				strcpy(pResult, bufferString);
				rtn = 1;
				break;
			}

		}while(retries >= 0);
	}
	return rtn;
}

/************************************************************************************************************/
/**************************************************TESTING***************************************************/
/************************************************************************************************************/
/*
int get_NumberInteger(int* pResult, char* msg, char* errorMsg, int retries){
	int rtn;
	char bufferString[STRING_LENGHT_NUMBERS];

	rtn = 0;

	if(pResult != NULL && msg != NULL && errorMsg != NULL && retries >=0){
		do{
			printf("%s", msg);
			__fpurge(stdin);
			scanf("%[^\n]", bufferString);
			if(validate_Integer(bufferString)){
				rtn = 1;
			} else {
				printf("SE DESBORDO LA PILA\n\n");
			}
		}while(retries >= 0);
	}

	return rtn;
}

int validate_Integer(char* number){
	int rtn;

	int max;
	int min;
	int elMaximoDelNumero;
	int pila;
	char bufferString[STRING_LENGHT_NUMBERS];

	rtn = 0;
	max = INT_MAX;
	min = INT_MIN;

	printf("Maximo: %d\n", max);
	printf("Minimo: %d\n", min);
	if(number != NULL){
		pila=sprintf(bufferString, "%d", max);
		elMaximoDelNumero=strlen(number);
		if(elMaximoDelNumero < pila){
			rtn = 1;
		} else {
			if(elMaximoDelNumero == pila){
				printf("-");
			}
		}
		printf("\n\n%d\n", elMaximoDelNumero);
		printf("%d\n\n", pila);
	}

	return rtn;
}*/
/*
int validate_OverflowInteger(char* number, int option){
	int i;
	int j;
	int stack;
	char buffer[STRING_LENGHT_NUMBERS];
	int rtn;
	rtn = 0;

	i=0;
	j=0;

	switch (option){
	case 1:
		stack = sprintf(buffer, "%d", INT_MIN);
		for(i=0;i<stack;i++){
			j=i;
			if(number[i] != '\0'){
				if(number[i] == '-' || number[i] == '+'){
					continue;
				} else{
					if(number[i] > stack[i]){

					}
				}
			} else {
				rtn = 1;
				break;
			}
		}

		while(number[i] != '\0'){
			if(number[i] == '-' || number[i] == '+'){
				i++;
				j=i-1;
			} else{
				if(number[i] > stack[i]){
					rtn = 0;
					break;
				} else {
					i++;
					j++;
				}
			}
		}
		break;
	case 2:
			while(number[i] != '\0'){
			if(number[i] == '-' || number[i] == '+'){
				i++;
				//j++;
				j=i-1;
			} else{
				if(number[i] > stack[i]){
					rtn = 0;
					break;
				} else {
					i++;
					j++;
				}
			}
		}
		break;
	}
}*/
//int get_RangeInteger(int max, int min, int option){}
