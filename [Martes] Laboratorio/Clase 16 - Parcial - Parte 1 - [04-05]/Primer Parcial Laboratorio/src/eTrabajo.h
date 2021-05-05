/*
 * eTrabajo.h
 *
 *  Created on: 4 may. 2021
 *      Author: luciano
 */

#ifndef ETRABAJO_H_
#define ETRABAJO_H_

#include <stdio_ext.h>
#include <stdlib.h>
#include "Utilidades.h"


#define STRING_LENGHT 100
#define VACIO 0
#define OCUPADO -1

typedef struct {

	int dia;
	int mes;
	int anio;

}eFecha;

typedef struct{

	int id;
	char marcaBicicleta[STRING_LENGHT];
	int rodadoBicicleta;
	int idServicio;
	eFecha fecha;
	int isEmpty;

}eTrabajo;

void inicializarIsEmptyTrabajos(eTrabajo lista[], int lenghtArray);

int comprobarEspaciosVaciosEstructuraTrabajo(eTrabajo lista[], int lenghtArray);
int comprobarEspaciosOcupadosEstructuraTrabajo(eTrabajo lista[], int lenghtArray);

int comprobarIndexOcupadoTrabajo(eTrabajo lista[], int lenghtArray, int numero);

eFecha pedirFecha(eTrabajo miTrabajo);

//PARTE 3:
void bajaListaEstructuraTrabajo(eTrabajo lista[], int lenghtArray);

//PARTE 4:
void mostrarListadoTrabajos(eTrabajo  lista[], int lenghtArray);
void mostrarUnElementoTrabajos(eTrabajo unElemento);
void ordenarTrabajosPorAnioYMarca(eTrabajo  lista[], int lenghtArray);



#endif /* ETRABAJO_H_ */
