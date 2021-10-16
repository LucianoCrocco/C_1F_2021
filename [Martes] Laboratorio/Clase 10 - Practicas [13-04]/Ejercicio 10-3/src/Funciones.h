/*
 * Funciones.h
 *
 *  Created on: 12 abr. 2021
 *      Author: luciano
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/************************************************************************************************************/
/************************************************MACROS UTILES***********************************************/
/************************************************************************************************************/

#define VACIO 0
#define OCUPADO -1
#define STRING_LENGHT 100

//		PAISES
#define EEUU 1
#define CHINA 2
#define OTRO 3

//		TIPO DE PRODUCTOS
#define IPHONE 1000
#define MAC 1001
#define IPAD 1002
#define ACCESORIOS 1003

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
	int nacionalidad;
	int tipo;
	float precio;
	int isEmpty;

	int idTipo;//FK
	int idNacionalidad;//FK
}eProductos;

/************************************************************************************************************/
/**************************************************UTILIDADES************************************************/
/************************************************************************************************************/

int menu(void);
void saltoDeLinea(int cantidad);

/************************************************************************************************************/
/***********************************************PEDIR FUNCIONES**********************************************/
/************************************************************************************************************/

int pedirEnteroConRango(char mensaje[], char mensajeError[], int minimo, int maximo);
int pedirEntero(char mensaje[]);
float pedirFloat(char mensaje[]);

/************************************************************************************************************/
/************************************************VALIDACIONES************************************************/
/************************************************************************************************************/

int comprobarNoRepiteIntProducto(eProductos lista[], int lenghtArray ,int numero);

/************************************************************************************************************/
/************************************************ESTRUCTURAS*************************************************/
/************************************************************************************************************/

void hardocodearDatosUnaStructNacionalidades(eNacionalidad lista[]);
void inicializarIsEmptyNacionalidades(eNacionalidad lista[], int lenghtArray);

void hardocodearDatosUnaStructTipoProductos(eTipoProducto lista[]);
void inicializarIsEmptyTipoProductos(eTipoProducto lista[], int lenghtArray);

void hardocodearDatosUnaStructProductos(eProductos lista[]);
void inicializarIsEmptyProductos(eProductos lista[], int lenghtArray);

int comprobarEspaciosOcupadosEstructura(eProductos lista[], int lenghtArray);
int comprobarEspaciosVaciosEstructura(eProductos lista[], int lenghtArray);

//CASE 1 Y 3:
void mostrarListadoTipoProducto(eTipoProducto  lista[], int lenghtArray);
void mostrarUnElementoTipoProducto(eTipoProducto unElemento);

//CASE 1:
void altaListaEstructura(eProductos lista[], int lenghtArray, eTipoProducto lista2[], int lenghtArray2);
void cargarDatosEstructura(eProductos lista[], int index, eTipoProducto lista2[], int lenghtArray2);


//CASE 2:
void bajaListaEstructura(eProductos lista[], int lenghtArray);
int comprobarDatoIntEIndex(eProductos lista[], int lenghtArray, int numero);

//CASE 3:
void modificarProductos(eProductos lista[], int lenghtArray, eTipoProducto lista2[], int lenghtArray2);
void modificarDatosProductos(eProductos lista[], int index, eTipoProducto lista2[], int lenghtArray2);

//CASE 4:
void mostrarListadoProductos(eProductos lista[], int lenghtArray);
void mostrarUnElementoProductos(eProductos unProducto);

//CASE 5:
void insertionSortNumbPrecio(eProductos lista[], int lenghtArray);

//CASE 6:
void insertionSortNumbDescripcion(eProductos lista[], int lenghtArray);

//CASE 7:
void productosMasCaros(eProductos lista[], int lenghtArray);
void printProductosMasCaros(eProductos lista[], int lenghtArray);

//CASE 8:
float precioPromedioPorTipo(eProductos lista[], int lenghtArray, int tipo);
void printPromediosPorTipo(eProductos lista[], int lenghtArray, eTipoProducto lista2[], int lenghtArray2);
void printUnPromedioTipoProducto(eProductos lista[], int lenghtArray, eTipoProducto lista2[], int lenghtArray2, int tipo);

//CASE 9:
//Re-veer por el tema de los switch
//void mostrarListadoProductosConDescTipo(eProductos lista[], int lenghtArray, eTipoProducto listaTipo[], int lenghtTipo);

//CASE 10:
void mostrarListadoTipoProductoYProducto(eProductos lista[], int lenghtArray, eTipoProducto listaTipo[], int lenghtTipo);
int mostrarUnElementoTipoProductoYProducto(eProductos lista[], int lenghtArray, eTipoProducto unElemento);
#endif /* FUNCIONES_H_ */
