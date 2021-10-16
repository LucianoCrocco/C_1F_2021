/*
 * Funcion.c
 *
 *  Created on: 23 mar. 2021
 *      Author: luciano
 */


#include <stdio_ext.h>
#include <stdlib.h>
#include "Validaciones.h"
#include "Funciones.h"
#include <ctype.h>



char pedirOpcion (char mensaje[], char mensajeError[]){

	char opcion;
	int validacion;

	validacion = -1;

	printf("%s", mensaje);
	__fpurge(stdin);
	scanf("%c",&opcion);
	opcion = toupper(opcion);


	validacion = validarChar(opcion);

	while(validacion == -1){
		printf("%s", mensajeError);
		__fpurge(stdin);
		scanf("%c",&opcion);
		opcion = toupper(opcion);

		validacion = validarChar(opcion);
	}

	return opcion;
}

float pedirTemperatura(char mensaje[], char mensajeError[], float minimo, float maximo){
	float temperatura;
	int validacion;

	validacion = -1;

	printf("%s", mensaje);
	scanf("%f",&temperatura);

	validacion = validarTemperatura(temperatura, minimo, maximo);

	while(validacion == -1){
		printf("%s %s",mensajeError, mensaje);
		scanf("%f",&temperatura);
		validacion = validarTemperatura(temperatura, minimo, maximo);
	}

	return temperatura;
}

float trasnformarTemperatura(char opcion, float temperatura){

	float retorno;

	switch(opcion){
		case 'F':
			retorno = (temperatura - 32) / 1.8;
			//F = (ºC · 1,8) + 32
			break;
		case 'C':
			retorno = (temperatura * 1.8) + 32;
			break;
	}
	return retorno;
}

void mostrarResultado(char mensaje [], char tipoDeEscala[],float temperatura, float temperaturaInvertida){
	printf("%s, ingreso una temperatura de %.2fº. La misma temperatura ingresada en %s es de %.2f", mensaje, temperatura, tipoDeEscala, temperaturaInvertida);
}
