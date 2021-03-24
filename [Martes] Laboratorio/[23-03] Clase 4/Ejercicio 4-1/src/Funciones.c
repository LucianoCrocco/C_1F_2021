/*
 * Funciones.c
 *
 *  Created on: 23 mar. 2021
 *      Author: luciano
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"


int calcularFactorial (int numero){
	int resultado;

	if(numero == 0 || numero == 1){
		resultado = 1;
	} else {
		resultado = numero * calcularFactorial(numero-1);

	}

	return resultado;
}
