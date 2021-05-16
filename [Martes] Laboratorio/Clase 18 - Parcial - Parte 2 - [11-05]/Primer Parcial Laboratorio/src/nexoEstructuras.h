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

/**
 * @brief Genera un ID a partir del index y del numero con el cual quiero comenzar ese ID. Lo hace sumando index + numero.
 *
 * @param indexGenerado Recibe el INDEX que tiene ese elemento en la estructura
 * @param numeroInicializador Recibe el numero con el cual queremos comenzar a contar nuestros ID's
 * @return Retorna el ID generado.
 */
int generar_ID(int indexGenerado, int numeroInicializador);
//PARTE 1

/**
 * @brief Busca un index disponible, de ser posible hace la alta, de no ser posible no se cargan datos
 *
 * @param listaTrabajos Recibe el array de trabajos para buscar un index disponible y cargar los datos
 * @param lenghtTrabajos Recibe el tamanio de ese array trabajos
 * @param listaServicios Recibe el array de Servicios para mostarlos en pantalla a la hora de seleccionar un servicio.
 * @param lenghtServicios Recibe el tamanio de ese array servicios.
 * @return Retorna 1 si fue posible, 0 si no.
 */
int altaDatosTrabajos(eTrabajo listaTrabajos[], int lenghtTrabajos, eServicio listaServicios[], int lenghtServicios);

//PARTE 2
/**
 * @brief Le pide al usuario que ingrese el ID del trabajo a modificar, en caso de que exista ingresa a la funcion modificarDatosTrabajos, sino lo consigue despues de 3 intentos vuelve al main
 *
 * @param listaTrabajos Recibe el array de trabajos para buscar el index.
 * @param lenghtTrabajos Recibe el tamanio de ese array trabajos.
 * @param listaServicios Recibe el array de Servicios para pasarselo a la otra funcion.
 * @param lenghtServicios Recibe el tamanio de ese array servicios.
 * @return Retorna 0 si no encontro el ID, en caso de encontrarlo de retorna 1.
 */
int modificarTrabajos(eTrabajo listaTrabajos[], int lenghtTrabajos, eServicio listaServicios[], int lenghtServicios);

/**
 * @brief Funcion que se encarga de realizar el cambio de datos de un trabajo en particular.
 *
 * @param listaTrabajos Recibe el array de trabajos.
 * @param index Recibe el index del array de trabajos en el cual voy a modificar los datos.
 * @param lenghtTrabajos Recibe el tamanio de ese array trabajos.
 * @param listaServicios Recibe el array de Servicios para mostarlos en pantalla a la hora de seleccionar un nuevo servicio.
 * @param lenghtServicios Recibe el tamanio de ese array servicios.
 * @return Retorna 0 si no se realizaron modificaciones, 1 si se realizaron.
 */
int modificarDatosTrabajos(eTrabajo listaTrabajos[], int index,int lenghtTrabajos, eServicio listaServicios[], int lenghtServicios);


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

#endif /* NEXOESTRUCTURAS_H_ */
