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
/**
 * @brief Inicializa los datos por default de la estructura trabajos para que todos esten vacios, estandarizamos isEmpty como referencia a VACIO u OCUPADO
 *
 * @param lista Recibe el array de la estructura trabajos
 * @param lenghtArray Recibe la cantidad de elementos que puede contener el array trabajos
 */
void inicializarIsEmptyTrabajos(eTrabajo lista[], int lenghtArray);
//Testing
/**
 * @brief Hardcodeo de trabajos
 *
 * @param listaTrabajo Recibe el array de trabajos.
 */
void hardcodearStructTrabajo(eTrabajo listaTrabajo[]);

/**
 * @brief Comprueba si hay espacios VACIOS dentro de la estructura trabajos. Estandarizamos la comprobacion de los datos en isEmpty.
 *
 * @param lista Recibe el array de la estructura trabajos.
 * @param lenghtArray Recibe la cantidad de elementos que puede contener el array trabajos.
 * @return Retorna el indice del array en el cual hay un espacio VACIO, caso que no haya retorna -1.
 */
int comprobarEspaciosVaciosEstructuraTrabajo(eTrabajo lista[], int lenghtArray);

/**
 * @brief Comprueba si hay espacios OCUPADOS dentro de la estructura. Estandarizamos la comprobacion de los datos en isEmpty
 *
 * @param lista Recibe el array de la estructura trabajos.
 * @param lenghtArray Recibe la cantidad de elementos que puede contener el array trabajos.
 * @return Retorna el 1 si hay un espacio OCUPADO, caso que no haya retorna -1.
 */
int comprobarEspaciosOcupadosEstructuraTrabajo(eTrabajo lista[], int lenghtArray);

/**
 * @brief Comprueba si el index ingresado por el usuario pertenece a un ID dentro de la estructura trabajo.
 *
 * @param lista Recibe el array de la estructura trabajo.
 * @param lenghtArray Recibe la cantidad de elementos que puede contener el array trabajo.
 * @param numero Recibe el dato de tipo INT a buscar.
 * @return Rertorna el index si es verdadero o -1 si es falso.
 */
int comprobarIndexOcupadoTrabajo(eTrabajo lista[], int lenghtArray, int numero);

/**
 * @brief Pide una fecha para asignalrla a su estructura anidada.
 *
 * @param miTrabajo Recibe el elemento del array en el cual voy a cargar los datos
 * @return Retorna las fechas cargadas
 */
eFecha pedirFecha(eTrabajo miTrabajo);

//PARTE 3:

/**
 * @brief Se encarga de dar de baja los datos de la estructura seteando el index de OCUPADO a VACIO. La utilizo en el main
 *
 * @param lista Recibe el array de la estructura trabajos.
 * @param lenghtArray Recibe la cantidad de elementos que puede contener el array trabajos.
 * @return retorna 1 si fue posible, 0 si no se encontro el ID o se supero el maximo de reintentos.
 */
int bajaListaEstructuraTrabajo(eTrabajo lista[], int lenghtArray);

//PARTE 4:
/**
 * @brief Muestra el listado completo de la estrucutra trabajo.
 *
 * @param lista Recibe el array de la estructura trabajo.
 * @param lenghtArray Recibe la cantidad de elementos que puede contener el array de trabajo.
 */
void mostrarListadoTrabajos(eTrabajo  lista[], int lenghtArray);

/**
 * @brief Muestra un solo elemento de la estrucutura trabajo
 *
 * @param unElemento La posicion del array en particular del elemento trabajo que se desea mostrar
 */
void mostrarUnElementoTrabajos(eTrabajo unElemento);

/**
 * @brief Ordena los elementos del array de trabajo por anio, si el anio es el mismo lo ordena por marca.
 *
 * @param lista Recibe el array de la estructura trabajo.
 * @param lenghtArray Recibe la cantidad de elementos que puede contener el array de trabajo.
 */
void ordenarTrabajosPorAnioYMarca(eTrabajo lista[], int lenghtArray);



#endif /* ETRABAJO_H_ */
