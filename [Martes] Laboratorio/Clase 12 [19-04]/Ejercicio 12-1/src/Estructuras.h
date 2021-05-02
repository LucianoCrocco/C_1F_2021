/*
 * Estructuras.h
 *
 *  Created on: 24 abr. 2021
 *      Author: luciano
 */

#ifndef ESTRUCTURAS_H_
#define ESTRUCTURAS_H_

#define VACIO 0
#define OCUPADO -1
#define STRING_LENGHT 100

typedef struct {

	int idNacionalidad;
	char descripcionNacionalidad[STRING_LENGHT];
	int isEmpty;

}eNacionalidad;

typedef struct{

	int idTipo;
	char descripcionTipo[STRING_LENGHT];
	int isEmpty;

}eTipoProducto;

typedef struct{

	int idProducto;
	char descripcion[STRING_LENGHT];
	float precio;
	int isEmpty;

	int idTipo;//FK
	int idNacionalidad;//FK

}eProductos;

typedef struct{

	int id;
	int contador;
	int isEmpty;

}eAuxiliar;

/************************************************************************************************************/
/************************************************ESTRUCTURAS*************************************************/
/************************************************************************************************************/

int comprobarEspaciosOcupadosEstructura(eProductos lista[], int lenghtArray);
int comprobarEspaciosVaciosEstructura(eProductos lista[], int lenghtArray);



/************************************************HARDCODEOS*************************************************/

void hardocodearDatosUnaStructNacionalidades(eNacionalidad lista[]);
void inicializarIsEmptyNacionalidades(eNacionalidad lista[], int lenghtArray);

void hardocodearDatosUnaStructTipoProductos(eTipoProducto lista[]);
void inicializarIsEmptyTipoProductos(eTipoProducto lista[], int lenghtArray);

void hardocodearDatosUnaStructProductos(eProductos lista[]);
void inicializarIsEmptyProductos(eProductos lista[], int lenghtArray);

//CASE 1:
void altaListaEstructura(eProductos lista[], int lenghtArray, eTipoProducto lista2[], int lenghtArray2, eNacionalidad lista3[], int lenghtArray3);
void cargarDatosEstructura(eProductos lista[], int index, eTipoProducto lista2[], int lenghtArray2, eNacionalidad lista3[], int lenghtArray3);

//CASE 2:
void bajaListaEstructura(eProductos lista[], int lenghtArray);

//CASE 1 Y 3 TIPO PRODUCTO:
void mostrarListadoTipoProducto(eTipoProducto  lista[], int lenghtArray);
void mostrarUnElementoTipoProducto(eTipoProducto unElemento);

//CASE 3:
void modificarProductos(eProductos lista[], int lenghtArray, eTipoProducto lista2[], int lenghtArray2, eNacionalidad lista3[], int lenghtArray3);
void modificarDatosProductos(eProductos lista[], int index, eTipoProducto lista2[], int lenghtArray2, eNacionalidad lista3[], int lenghtArray3);

//CASE 4:
void mostrarListadoProductos(eProductos lista[], int lenghtArray);
void mostrarUnElementoProductos(eProductos unProducto);

//CASE 7:
void productosMasCaros(eProductos lista[], int lenghtArray);
void printProductosMasCaros(eProductos lista[], int lenghtArray);

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

//CASE 1 Y 3 NACIONALIDAD:
void mostrarListadoNacionalidad(eNacionalidad lista[], int lenghtArray);
void mostrarUnElementoNacionalidad(eNacionalidad unElemento);

//CASE 11:
void calcularTiposConMasProductos(eProductos lista[], int lenghtArray, eTipoProducto listaTipo[], int lenghtTipo);
void inicializarAuxiliarComoTipo(eTipoProducto listaTipo[], eAuxiliar listaAuxiliar[], int lenghtTipo);
void contadorDeMaximosTipoProducto(eProductos lista[], int lenghtArray, eAuxiliar listaAuxiliar[], int lenghtTipo);
int calcularMaximoTipoProducto(eAuxiliar listaAuxiliar[], int lenghtTipo);
void printMasTipoProductos(eAuxiliar lista[], eTipoProducto listaTipo[], int lenghtArray, int maximo);

//CASE 12:
void calcularNacionalidadFabricaIphone(eProductos lista[], int lenghtArray, eTipoProducto listaTipo[], int lenghtTipo, eNacionalidad listaNacionalidad[], int lenghtNacionalidad);
void inicializarAuxiliarComoNacionalidad(eNacionalidad listaNacionalidad[], eAuxiliar listaAuxiliar[], int lenghtNacionalidad);
int buscarIdTipoEspecifico(char nombre[], eTipoProducto listaTipo[], int lenghtTipo);
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

#endif /* ESTRUCTURAS_H_ */
