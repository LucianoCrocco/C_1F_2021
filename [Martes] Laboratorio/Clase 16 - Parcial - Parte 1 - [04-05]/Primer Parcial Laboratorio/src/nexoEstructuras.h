/*
 * nexoEstructuras.h
 *
 *  Created on: 4 may. 2021
 *      Author: luciano
 */

#ifndef NEXOESTRUCTURAS_H_
#define NEXOESTRUCTURAS_H_

#include <stdio_ext.h>
#include <stdlib.h>
#include "Utilidades.h"
#include "eTrabajo.h"
#include "eServicio.h"

#define VACIO 0
#define OCUPADO -1
#define STRING_LENGHT 100


int generar_ID(int indexGenerado, int numeroInicializador);
void altaEstructuraTrabajo(eTrabajo listaTrabajos[], int lenghtTrabajos, eServicio listaServicios[], int lenghtServicios);
void cargarDatosTrabajos(eTrabajo listaTrabajos[], int lenghtTrabajos, int index, eServicio listaServicios[], int lenghtServicios);

//PARTE 2
void modificarTrabajos(eTrabajo listaTrabajos[], int lenghtTrabajos, eServicio listaServicios[], int lenghtServicios);
void modificarDatosTrabajos(eTrabajo listaTrabajos[], int index,int lenghtTrabajos, eServicio listaServicios[], int lenghtServicios);


//PARTE 6
void printTotalEnPesosTrabajos(eTrabajo listaTrabajos[], int lenghtTrabajos, eServicio listaServicios[], int lenghtServicios);
float calcularTotalEnPesosTrabajos(eTrabajo listaTrabajos[], int lenghtTrabajos, eServicio listaServicios[], int lenghtServicios);

#endif /* NEXOESTRUCTURAS_H_ */
