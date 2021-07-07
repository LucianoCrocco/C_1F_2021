/*
 * Utilidades.h
 *
 *  Created on: 2 may. 2021
 *      Author: luciano
 */

#ifndef UTILIDADES_H_
#define UTILIDADES_H_


/************************************************************************************************************/
/**************************************************UTILIDADES************************************************/
/************************************************************************************************************/

/**
 * @brief Funcion que desplega las opciones del menu.
 *
 * @return retorna un dato de tipo int con la opcion ingresada.
 */
int menu(void);
void saltoDeLinea(int cantidad);

/************************************************************************************************************/
/***********************************************PEDIR FUNCIONES**********************************************/
/************************************************************************************************************/

/**
 * @brief Funcion que permite el ingreso de un dato de tipo enterno (int) con rangos predeterminados.
 *
 * @param mensaje Es un string que muestra un mensaje.
 * @return Retorna el dato int ingresado.
 */
int pedirEnteroConRango(char mensaje[], char mensajeError[], int minimo, int maximo);

/**
 * @brief Funcion que permite el ingreso de un dato de tipo enterno (int).
 *
 * @param mensaje Es un string que muestra un mensaje.
 * @return Retorna el dato int ingresado.
 */
int pedirEntero(char mensaje[]);

/**
 * @brief Funcion que permite el ingreso de un dato de tipo flotante.
 *
 * @param mensaje Es un string que muestra un mensaje.
 * @return Retorna el dato float ingresado.
 */
float pedirFloat(char mensaje[]);


#endif /* UTILIDADES_H_ */
