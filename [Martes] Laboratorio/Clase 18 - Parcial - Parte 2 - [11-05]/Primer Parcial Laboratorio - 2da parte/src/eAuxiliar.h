/*
 * eAuxiliar.h
 *
 *  Created on: 11 may. 2021
 *      Author: luciano
 */

#ifndef EAUXILIAR_H_
#define EAUXILIAR_H_

#include <stdio_ext.h>
#include <stdlib.h>
#include "Utilidades.h"

#define STRING_LENGHT 100
#define STRING_LENGHT_MARCA_BICI 25
#define VACIO 0
#define OCUPADO -1

typedef struct{

	int id;
	int contador;
	int isEmpty;


}eAuxiliar;

int calcularMaximoServicio(eAuxiliar listaAuxiliar[], int lenghtServicios);

#endif /* EAUXILIAR_H_ */
