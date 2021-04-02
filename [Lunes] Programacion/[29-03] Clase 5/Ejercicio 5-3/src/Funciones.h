/*
 * Funciones.h
 *
 *  Created on: 29 mar. 2021
 *      Author: luciano
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>

void inicializarArray(int arrayNumeros[], int tamanio, int valor);

int pedirPosicion(char mensaje[], char mensajeError[], int arrayNumeros[], int tamanio);

int validarNumero(int numero, int min, int max);

void cargarNumeroArray(int arrayNumeros[], int tamanio, int numero, int posicion);

int pedirEntero(char mensaje[], char mensajeError[], int minimo, int maximo);

int sumarPosONeg(int arrayNumeros[], int tamanio, char tipo);

int promediarPositivos(int arrayNumeros[], int tamanio);

void printSumaPositivos(int arrayNumeros[], int tamanio);

int contadorNegativos(int arrayNumeros[], int tamanio);

void printsumaNegAntecesores(int arrayNumeros[], int tamanio);

#endif /* FUNCIONES_H_ */
