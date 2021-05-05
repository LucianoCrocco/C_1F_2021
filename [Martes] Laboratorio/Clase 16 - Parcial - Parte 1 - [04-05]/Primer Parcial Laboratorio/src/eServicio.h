/*
 * eServicio.h
 *
 *  Created on: 4 may. 2021
 *      Author: luciano
 */

#ifndef ESERVICIO_H_
#define ESERVICIO_H_

#include <stdio_ext.h>
#include <stdlib.h>
#include "Utilidades.h"

#define STRING_LENGHT 25
#define VACIO 0
#define OCUPADO -1

typedef struct {

	int id;
	char descripcion[STRING_LENGHT];
	float precio;

	int isEmpty;
}eServicio;

void inicializarIsEmptyServicios(eServicio lista[], int lenghtArray);
void hardocodearDatosUnaStructServicios(eServicio lista[]);

int comprobarEspaciosVaciosEstructuraServicios(eServicio lista[], int lenghtArray);
int comprobarEspaciosOcupadosEstructuraServicios(eServicio lista[], int lenghtArray);

//PARTE 5
void mostrarListadoServicios(eServicio  lista[], int lenghtArray);
void mostrarUnElementoServicios(eServicio unElemento);

int comprobarIndexOcupadoServicios(eServicio lista[], int lenghtArray, int numero);

#endif /* ESERVICIO_H_ */
