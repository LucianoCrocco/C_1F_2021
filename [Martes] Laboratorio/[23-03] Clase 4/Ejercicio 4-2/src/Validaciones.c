/*
 * Validaciones.c
 *
 *  Created on: 23 mar. 2021
 *      Author: luciano
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#include "Validaciones.h"

int validarChar(char opcion){

	int retorno;

	retorno = -1;

	if(opcion == 'F' || opcion =='C'){
		retorno = 1;
	}

	return retorno;
}

int validarTemperatura(float temperatura, float minimo, float maximo){
	int retorno;

	retorno = 1;

	if(temperatura<minimo || temperatura > maximo){
		retorno = -1;
	}

	return retorno;
}
