/*
 * array.h
 *
 *  Created on: 29 may. 2021
 *      Author: luciano
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdio.h>
#include <stdlib.h>

#define TAM 5


int pedirEntero(char* mensaje, int* pResultado);
int cargarVector (int* pVector, int tamanio, int* arrayNumeros);
int mostrarVector(int* pVector, int tamanio);
int reemplazarEnVector(int* pVector, int tamanio, int numero);

#endif /* ARRAY_H_ */
