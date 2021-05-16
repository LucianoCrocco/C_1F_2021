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

#define STRING_LENGHT_SERVICIO 25
#define VACIO 0
#define OCUPADO -1

typedef struct {

	int id;
	char descripcion[STRING_LENGHT_SERVICIO];
	float precio;

	int isEmpty;
}eServicio;
/**
 * @brief Inicializa los datos por default de la estructura trabajos para que todos esten vacios, estandarizamos isEmpty como referencia a VACIO u OCUPADO
 *
 * @param lista Recibe el array de la estructura servicio
 * @param lenghtArray Recibe la cantidad de elementos que puede contener el array servicio.
 */
void inicializarIsEmptyServicios(eServicio lista[], int lenghtArray);

/**
 * @brief Hardcodeo de servicio
 *
 * @param listaTrabajo Recibe el array de servicio.
 */
void hardocodearDatosUnaStructServicios(eServicio lista[]);
/**
 * @brief Comprueba si hay espacios VACIOS dentro de la estructura trabajos. Estandarizamos la comprobacion de los datos en isEmpty.
 *
 * @param lista Recibe el array de la estructura servicio.
 * @param lenghtArray Recibe la cantidad de elementos que puede contener el array servicio.
 * @return Retorna el indice del array en el cual hay un espacio VACIO, caso que no haya retorna -1.
 */
int comprobarEspaciosVaciosEstructuraServicios(eServicio lista[], int lenghtArray);
/**
 * @brief Comprueba si hay espacios OCUPADOS dentro de la estructura. Estandarizamos la comprobacion de los datos en isEmpty
 *
 * @param lista Recibe el array de la estructura servicio.
 * @param lenghtArray Recibe la cantidad de elementos que puede contener el array servicio.
 * @return Retorna el 1 si hay un espacio OCUPADO, caso que no haya retorna -1.
 */
int comprobarEspaciosOcupadosEstructuraServicios(eServicio lista[], int lenghtArray);

//PARTE 5
/**
 * @brief Muestra el listado completo de la estrucutra servicio.
 *
 * @param lista Recibe el array de la estructura servicio.
 * @param lenghtArray Recibe la cantidad de elementos que puede contener el array de servicio.
 */
void mostrarListadoServicios(eServicio  lista[], int lenghtArray);
/**
 * @brief Muestra un solo elemento de la estrucutura servicio
 *
 * @param unElemento La posicion del array en particular del elemento servicio que se desea mostrar
 */
void mostrarUnElementoServicios(eServicio unElemento);

/**
 * @brief Comprueba si el index ingresado por el usuario pertenece a un ID dentro de la estructura servicio.
 *
 * @param lista Recibe el array de la estructura servicio
 * @param lenghtArray Recibe la cantidad de elementos que puede contener el array servicio
 * @param numero Recibe el dato de tipo INT a buscar.
 * @return Rertorna el index si es verdadero o -1 si es falso.
 */
int comprobarIndexOcupadoServicios(eServicio lista[], int lenghtArray, int numero);

#endif /* ESERVICIO_H_ */
