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
#include "eBicicleta.h"
#include "eAuxiliar.h"

#define VACIO 0
#define OCUPADO -1

/**
 * @brief Genera un ID a partir del index y del numero con el cual quiero comenzar ese ID. Lo hace sumando index + numero.
 *
 * @param indexGenerado Recibe el INDEX que tiene ese elemento en la estructura
 * @param numeroInicializador Recibe el numero con el cual queremos comenzar a contar nuestros ID's
 * @return Retorna el ID generado.
 */
int generar_ID(int indexGenerado, int numeroInicializador);
//PARTE 1


int altaDatosTrabajos(eTrabajo listaTrabajos[], int lenghtTrabajos, eServicio listaServicios[], int lenghtServicios, eBicicleta listaBicicletas[], int lenghtBicicletas);

//PARTE 2

int modificarTrabajos(eTrabajo listaTrabajos[], int lenghtTrabajos, eServicio listaServicios[], int lenghtServicios, eBicicleta listaBicicletas[], int lenghtBicicletas);


int modificarDatosTrabajos(eTrabajo listaTrabajos[], int index,int lenghtTrabajos, eServicio listaServicios[], int lenghtServicios, eBicicleta listaBicicletas[], int lenghtBicicletas);
//PARTE 4
void ordenarTrabajosPorAnioOMarca(eTrabajo listaTrabajo[], int lenghtTrabajo, eBicicleta listaBicicletas[], int lenghtBicicletas);

eBicicleta buscarIDYAsignarBicicleta(eBicicleta listaBicicletas[], int lenghtBicicletas, int idBicicleta);

//PARTE 6
/**
 * @brief Hace un print del total en pesos de los trabajos
 *
 * @param listaTrabajos Recibe el array de trabajos.
 * @param lenghtTrabajos Recibe el tamanio de ese array trabajos
 * @param listaServicios Recibe el array de Servicios
 * @param lenghtServicios Recibe el tamanio de ese array servicios
 */
void printTotalEnPesosTrabajos(eTrabajo listaTrabajos[], int lenghtTrabajos, eServicio listaServicios[], int lenghtServicios);

/**
 * @brief Calcula el total en pesos de todos los trabajos realizados.
 *
 * @param listaTrabajos Recibe el array de trabajos.
 * @param lenghtTrabajos Recibe el tamanio de ese array trabajos
 * @param listaServicios Recibe el array de Servicios
 * @param lenghtServicios Recibe el tamanio de ese array servicios
 * @return Retorna el valor en float del total.
 */
float calcularTotalEnPesosTrabajos(eTrabajo listaTrabajos[], int lenghtTrabajos, eServicio listaServicios[], int lenghtServicios);

//PARTE G
void ordenarTrabajosPorMarca(eTrabajo listaTrabajo[], int lenghtTrabajo, eBicicleta listaBicicletas[], int lenghtBicicletas);

//PARTE H
void inicializarAuxiliarComoServicio(eServicio listaServicios[], int lenghtServicios, eAuxiliar listaAuxiliar[]);
void calcularServiciosConMasTrabajos(eTrabajo listaTrabajos[], int lenghtTrabajos, eServicio listaServicios[], int lenghtServicios);
void contadorDeMaximosServicios(eTrabajo listaTrabajos[], int lenghtTrabajos, eAuxiliar listaAuxiliar[], int lenghtServicios);
void printMasServiciosUtilizados(eAuxiliar lista[], eServicio listaServicios[], int lenghtServicios, int maximo);

//PARTE I
void mostrarListadoServiciosYBicicletas(eTrabajo listaTrabajos[], int lenghtTrabajos, eServicio listaServicios[], int lenghtServicios, eBicicleta listaBicicletas[], int lenghtBicicletas);
int mostrarUnElementoBicicletaServicio(eTrabajo listaTrabajos[], int lenghtTrabajos, eBicicleta listaBicicletas[], int lenghtBicicletas, eServicio unElemento);

#endif /* NEXOESTRUCTURAS_H_ */
