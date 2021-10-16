/*
 * eProductos.h
 *
 *  Created on: 2 may. 2021
 *      Author: luciano
 */

#ifndef EPRODUCTOS_H_
#define EPRODUCTOS_H_

#define VACIO 0
#define OCUPADO -1
#define STRING_LENGHT 100

typedef struct{

	int idProducto;
	char descripcion[STRING_LENGHT];
	float precio;
	int isEmpty;

	int idTipo;//FK
	int idNacionalidad;//FK

}eProductos;

/************************************************************************************************************/
/************************************************VALIDACIONES************************************************/
/************************************************************************************************************/

int comprobarIndexOcupado(eProductos lista[], int lenghtArray, int numero);
int comprobarEspaciosOcupadosEstructura(eProductos lista[], int lenghtArray);
int comprobarEspaciosVaciosEstructura(eProductos lista[], int lenghtArray);

/************************************************************************************************************/
/*************************************************HARDCODEOS*************************************************/
/************************************************************************************************************/

void hardocodearDatosUnaStructProductos(eProductos lista[]);
void inicializarIsEmptyProductos(eProductos lista[], int lenghtArray);

/************************************************************************************************************/
/****************************************************A.B.M***************************************************/
/************************************************************************************************************/

//CASE 2:
void bajaListaEstructura(eProductos lista[], int lenghtArray);

//CASE 4 Y 9:
void mostrarListadoProductos(eProductos lista[], int lenghtArray);
void mostrarUnElementoProductos(eProductos unProducto);

//CASE 5:
void insertionSortNumbPrecio(eProductos lista[], int lenghtArray);

//CASE 6:
void insertionSortNumbDescripcion(eProductos lista[], int lenghtArray);

//CASE 7:
void productosMasCaros(eProductos lista[], int lenghtArray);
void printProductosMasCaros(eProductos lista[], int lenghtArray);


#endif /* EPRODUCTOS_H_ */
