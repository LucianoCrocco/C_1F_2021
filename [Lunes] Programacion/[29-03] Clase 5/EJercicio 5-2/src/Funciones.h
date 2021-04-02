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

void cargarNumeros(int arrayNumeros[], int tamanio, int min, int max);

void mostrarNumeros(int arrayNumeros[], int tamanio);

int sumarNumeros(int arrayNumeros[], int tamanio);

int validarNumero(int numero, int min, int max);

int contadorPositivos(int arrayNumeros[], int tamanio);

int contadorNegativos(int arrayNumeros[], int tamanio);

void printContadorNumerosNegativos(int arrayNumeros[], int tamanio);

void printContadorNumerosPositivos(int arrayNumeros[], int tamanio);

int sumarNumerosPares(int arrayNumeros[], int tamanio);

int verificarParidad(int numero, int tamanio);

void printSumarNumerosPares(int arrayNumeros[], int tamanio);

int calcularNumeroImparMasGrande(int arrayNumeros[], int tamanio);

void printNumeroImparMasGrande(int arrayNumeros[], int tamanio);

void printNumerosPares(int arrayNumeros[], int tamanio);

void printNumerosPosImpares(int arrayNumeros[], int tamanio);



#endif /* FUNCIONES_H_ */
