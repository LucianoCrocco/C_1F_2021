/*
 * Funciones.h
 *
 *  Created on: 12 abr. 2021
 *      Author: luciano
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#define STRING_LENGHT 100

//		TIPO DE PRODUCTOS
#define IPHONE 1
#define MAC 2
#define IPAD 3
#define ACCESORIOS 4
//		PAISES
#define USA 1
#define CHINA 2
#define OTRO 3
//		ESPACIO
#define VACIO 0
#define OCUPADO -1


typedef struct {
	int idProducto;
	char descripcion[STRING_LENGHT];
	int nacionalidad;
	int tipo;
	float precio;
	int isEmpty;
}eProductos;

void hardocodearElementos(eProductos lista[]);


int pedirEnteroConRango(char mensaje[], char mensajeError[], int minimo, int maximo);
int pedirEntero(char mensaje[], char mensajeError[]);

void mostrarListadoEstructura(eProductos lista[], int lenghtArray);
void mostrarUnElementoEstrucutra(eProductos unProducto);
void inicializarIsEmptyEstructura(eProductos lista[], int lenghtArray);
int comprobarEspaciosVaciosEstructura(eProductos lista[], int lenghtArray);
int comprobarEspaciosOcupadosEstructura(eProductos lista[], int lenghtArray);
void altaLogicaListaEstrucutra(eProductos lista[], int lenghtArray);
void bajaLogicaListaEstrucutra(eProductos lista[], int lenghtArray);
int buscarIdEstrucutra(eProductos lista[], int lenghtArray, int numero);
void modificarEstructura(eProductos lista[], int lenghtArray);

void insertionSortNumbPrecio(eProductos lista[], int lenghtArray);
void insertionSortNumbDescripcion(eProductos lista[], int lenghtArray);
void simpleBubbleSortNumbsPrecio(eProductos lista[], int lenghtArray);

void printMaximos(eProductos lista[], int lenghtArray);
int buscarElMaximo(eProductos lista[], int lenghtArray);
float precioPromedioPorTipo(eProductos lista[], int lenghtArray, int tipo);
void printPromediosPorTipo(eProductos lista[], int lenghtArray);

#endif /* FUNCIONES_H_ */
