/*
 * Utilidades.h
 *
 *  Created on: 24 abr. 2021
 *      Author: luciano
 */

#ifndef UTILIDADES_H_
#define UTILIDADES_H_



/************************************************************************************************************/
/**************************************************UTILIDADES************************************************/
/************************************************************************************************************/

int menu(void);
void saltoDeLinea(int cantidad);
void incializarArrayEnCero(int array[], int cantidad);

/************************************************************************************************************/
/***********************************************PEDIR FUNCIONES**********************************************/
/************************************************************************************************************/

int pedirEnteroConRango(char mensaje[], char mensajeError[], int minimo, int maximo);
int pedirEntero(char mensaje[]);
float pedirFloat(char mensaje[]);

/************************************************************************************************************/
/************************************************VALIDACIONES************************************************/
/************************************************************************************************************/

int comprobarIndexOcupado(eProductos lista[], int lenghtArray, int numero);
int comprobarEspaciosOcupadosEstructura(eProductos lista[], int lenghtArray);
int comprobarEspaciosVaciosEstructura(eProductos lista[], int lenghtArray);
int validarExisteNacionalidad(eNacionalidad lista[], int lenghtArray, int id);
int validarExisteTipoProducto(eTipoProducto lista[], int lenghtArray, int id);

#endif /* UTILIDADES_H_ */
