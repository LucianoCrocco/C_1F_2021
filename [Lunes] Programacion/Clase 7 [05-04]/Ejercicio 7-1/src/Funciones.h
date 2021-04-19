/*
 * Funciones.h
 *
 *  Created on: 19 abr. 2021
 *      Author: luciano
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

void InicializarProductos(int[], int);

/*-1 si no encontro espacio disponible */
int CargarUnProducto(int[], float[], float[], float[], char[][30], int);

int BuscarLibre(int[], int);

int buscarIdProducto(int[], int, int);

void MostrarUnProducto(int, float, float, float, char[]);

void MostrarTodosLosProducto(int[], float[], float[], float[], char[][30], int);

void askModificarProducto(int[], float[], float[], float[], char[][30], int);

void modificarUnProducto(int posicion, float[], float[], float[], char[][30]);

void askBajaProducto(int[], float[], float[], float[], char[][30], int);

#endif /* FUNCIONES_H_ */

