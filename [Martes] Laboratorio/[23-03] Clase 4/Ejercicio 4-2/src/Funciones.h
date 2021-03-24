/*
 * Funcion.h
 *
 *  Created on: 23 mar. 2021
 *      Author: luciano
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio_ext.h>
#include <stdlib.h>
#include "Validaciones.h"

char pedirOpcion (char mensaje[], char mensajeError[]);
float pedirTemperatura(char mensaje[], char mensajeError[], float minimo, float maximo);
float trasnformarTemperatura(char opcion, float temperatura);
void mostrarResultado(char mensaje [], char tipoDeEscala[],float temperatura, float temperaturaInvertida);

#endif /* FUNCIONES_H_ */
