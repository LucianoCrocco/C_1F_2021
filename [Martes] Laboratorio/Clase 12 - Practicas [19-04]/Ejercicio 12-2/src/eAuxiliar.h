/*
 * eAuxiliar.h
 *
 *  Created on: 2 may. 2021
 *      Author: luciano
 */

#ifndef EAUXILIAR_H_
#define EAUXILIAR_H_

#define VACIO 0
#define OCUPADO -1
#define STRING_LENGHT 100

#include "eNacionalidad.h"
#include "eTipoProducto.h"
#include "eProductos.h"
#include "Utilidades.h"

typedef struct{

	int id;
	int contador;
	int isEmpty;

}eAuxiliar;

void inicializarAuxiliarComoTipo(eTipoProducto listaTipo[], eAuxiliar listaAuxiliar[], int lenghtTipo);
void inicializarAuxiliarComoNacionalidad(eNacionalidad listaNacionalidad[], eAuxiliar listaAuxiliar[], int lenghtNacionalidad);

#endif /* EAUXILIAR_H_ */
