/*
 * Funciones.h
 *
 *  Created on: 18 abr. 2021
 *      Author: luciano
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio_ext.h>
#include <string.h>

#define MAX_ALUMNOS 2
#define MAX_CADENA 30

void InicializarAlumnos(int[], int);

/*-1 si no encontro espacio disponible */
int CargarUnAlumno(int[], float[], float[], float[], char[][30], int);

int BuscarLibre(int[], int);

int buscarLegajo(int[], int, int);

void MostrarUnAlumno(int, float, float, float, char[]);

void MostrarTodosLosAlumnos(int[], float[], float[], float[], char[][30], int);

void askModificarAlumnos(int[], float[], float[], float[], char[][30], int);

void modificarUnLegajo(int posicion, float[], float[], float[], char[][30]);

void askBajaAlumnos(int[], float[], float[], float[], char[][30], int);

#endif /* FUNCIONES_H_ */
