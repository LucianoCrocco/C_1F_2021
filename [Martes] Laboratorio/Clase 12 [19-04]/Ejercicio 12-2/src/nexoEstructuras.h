/*
 * nexoEstructuras.h
 *
 *  Created on: 2 may. 2021
 *      Author: luciano
 */

#ifndef NEXOESTRUCTURAS_H_
#define NEXOESTRUCTURAS_H_

#define VACIO 0
#define OCUPADO -1
#define STRING_LENGHT 100

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Utilidades.h"
#include "eNacionalidad.h"
#include "eTipoProducto.h"
#include "eProductos.h"
#include "eAuxiliar.h"


/************************************************************************************************************/
/****************************************************A.B.M***************************************************/
/************************************************************************************************************/

//CASE 1:
void altaListaEstructura(eProductos lista[], int lenghtArray, eTipoProducto lista2[], int lenghtArray2, eNacionalidad lista3[], int lenghtArray3);
void cargarDatosEstructura(eProductos lista[], int lenghtArray, int index, eTipoProducto lista2[], int lenghtArray2, eNacionalidad lista3[], int lenghtArray3);

//CASE 3:
void modificarProductos(eProductos lista[], int lenghtArray, eTipoProducto lista2[], int lenghtArray2, eNacionalidad lista3[], int lenghtArray3);
void modificarDatosProductos(eProductos lista[], int index, eTipoProducto lista2[], int lenghtArray2, eNacionalidad lista3[], int lenghtArray3);

//CASE 8:
float precioPromedioPorTipo(eProductos lista[], int lenghtArray, int tipo);
void printPromediosPorTipo(eProductos lista[], int lenghtArray, eTipoProducto lista2[], int lenghtArray2);
void printUnPromedioTipoProducto(eProductos lista[], int lenghtArray, eTipoProducto lista2[], int lenghtArray2, int tipo);

//CASE 9:
void mostrarListadoProductosConDescTipo(eProductos lista[], int lenghtArray, eTipoProducto listaTipo[], int lenghtTipo);
void buscarListadoProductosConDescTipo(eProductos lista, eTipoProducto listaTipo[], int lenghtTipo);

//CASE 10:
void mostrarListadoTipoProductoYProducto(eProductos lista[], int lenghtArray, eTipoProducto listaTipo[], int lenghtTipo);
int mostrarUnElementoTipoProductoYProducto(eProductos lista[], int lenghtArray, eTipoProducto unElemento);

//CASE 11:
void calcularTiposConMasProductos(eProductos lista[], int lenghtArray, eTipoProducto listaTipo[], int lenghtTipo);
void contadorDeMaximosTipoProducto(eProductos lista[], int lenghtArray, eAuxiliar listaAuxiliar[], int lenghtTipo);
int calcularMaximoTipoProducto(eAuxiliar listaAuxiliar[], int lenghtTipo);
void printMasTipoProductos(eAuxiliar lista[], eTipoProducto listaTipo[], int lenghtArray, int maximo);

//CASE 12:
void calcularNacionalidadFabricaIphone(eProductos lista[], int lenghtArray, eTipoProducto listaTipo[], int lenghtTipo, eNacionalidad listaNacionalidad[], int lenghtNacionalidad);
void contadorNacionalidadIphone(eProductos lista[], int lenghtArray, eAuxiliar listaAuxiliar[], int lenghtNacionalidad, int idACompararTipo);
void printNacionlidadSoloIphone(eAuxiliar lista[], eNacionalidad listaNacionalidad[], int lenghtNacionalidad);

//CASE 13:
void printProductosOrdenadosPorNacionalidad(eProductos lista[], int lenghtArray, eNacionalidad listaNacion[], int lenghtNacion);

//CASE 14:
void calcularNacionConMasProductos(eProductos lista[], int lenghtArray, eNacionalidad listaNacion[], int lenghtNacion);
void contadorDeMaximosNacionProducto(eProductos lista[], int lenghtArray, eAuxiliar listaAuxiliar[], int lenghtNacion);
int calcularMaximoNacionProducto(eAuxiliar listaAuxiliar[], int lenghtNacion);
void printMasNacionProductos(eAuxiliar lista[], eNacionalidad listaNacion[], int lenghtArray, int maximo);

//CASE 15:
void printPromediosPorNacion(eProductos lista[], int lenghtArray, eNacionalidad lista2[], int lenghtArray2);
void printUnPromedioPorNacionalidad(eProductos lista[], int lenghtArray, eNacionalidad lista2[], int lenghtArray2, int nacionalidad);
float precioPromedioPorNacionalidad(eProductos lista[], int lenghtArray, int nacionalidad);

#endif /* NEXOESTRUCTURAS_H_ */
