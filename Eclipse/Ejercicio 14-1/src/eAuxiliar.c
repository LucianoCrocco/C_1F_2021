/*
 * eAuxiliar.c
 *
 *  Created on: 2 may. 2021
 *      Author: luciano
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "eNacionalidad.h"
#include "eTipoProducto.h"
#include "eProductos.h"
#include "eAuxiliar.h"
#include "Utilidades.h"

void inicializarAuxiliarComoTipo(eTipoProducto listaTipo[], eAuxiliar listaAuxiliar[], int lenghtTipo){
	int i;

	for(i=0;i<lenghtTipo;i++){
		listaAuxiliar[i].id=listaTipo[i].idTipo;
		listaAuxiliar[i].contador=0;
		listaAuxiliar[i].isEmpty=listaTipo[i].isEmpty;
	}
}


void inicializarAuxiliarComoNacionalidad(eNacionalidad listaNacionalidad[], eAuxiliar listaAuxiliar[], int lenghtNacionalidad){
	int i;

	for(i=0;i<lenghtNacionalidad;i++){
		listaAuxiliar[i].id=listaNacionalidad[i].idNacionalidad;
		listaAuxiliar[i].contador=0;
		listaAuxiliar[i].isEmpty=listaNacionalidad[i].isEmpty;
	}
}
