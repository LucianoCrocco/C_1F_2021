/*
 * Funciones.h
 *
 *  Created on: 12 abr. 2021
 *      Author: luciano
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#define LENGHT_STRING 100
#include <stdio_ext.h>
#include <stdlib.h>

typedef struct {

	char nombre[LENGHT_STRING];
	int goles;
	int partidosJugados;
	float promedioDeGoles;

}eJugador;

eJugador pedirDatos(void);

float calcularPromedio(eJugador miJugador);

void mostrarJugador(eJugador);


#endif /* FUNCIONES_H_ */
