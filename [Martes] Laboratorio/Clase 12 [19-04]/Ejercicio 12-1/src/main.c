/*
 * Luciano Crocco 1ºF
 * Ejercicio 12-1:
 */
#include <stdio.h>
#include <stdlib.h>
#include "Estructuras.h"
#include "Utilidades.h"
#include "Ordenamientos.h"

#define LENGHT_PRODUCTOS 25
#define LENGHT_TIPO_PRODUCTOS 10
#define LENGHT_NACIONALIDADES 9

int main(void){

	int opcion;
	int validacion;

	eProductos listadoDeProductos[LENGHT_PRODUCTOS];
	inicializarIsEmptyProductos(listadoDeProductos, LENGHT_PRODUCTOS);
	hardocodearDatosUnaStructProductos(listadoDeProductos);

	eTipoProducto listadoDeTiposProductos[LENGHT_TIPO_PRODUCTOS];
	inicializarIsEmptyTipoProductos(listadoDeTiposProductos, LENGHT_PRODUCTOS);
	hardocodearDatosUnaStructTipoProductos(listadoDeTiposProductos);

	eNacionalidad listadoDeNacionalidades[LENGHT_NACIONALIDADES];
	inicializarIsEmptyNacionalidades(listadoDeNacionalidades, LENGHT_NACIONALIDADES);
	hardocodearDatosUnaStructNacionalidades(listadoDeNacionalidades);




	setbuf(stdout,NULL);

	do{
		opcion = menu();
		switch(opcion){
			case 1:
				altaListaEstructura(listadoDeProductos,LENGHT_PRODUCTOS,listadoDeTiposProductos,LENGHT_TIPO_PRODUCTOS,listadoDeNacionalidades,LENGHT_NACIONALIDADES);
				break;
			case 2:
				validacion=comprobarEspaciosOcupadosEstructura(listadoDeProductos, LENGHT_PRODUCTOS);
					if(validacion != -1){
						saltoDeLinea(1);
						bajaListaEstructura(listadoDeProductos,LENGHT_PRODUCTOS);
					} else {
						printf("\n--------No hay productos cargados--------\n\n");
					}
				break;
			case 3:
				validacion=comprobarEspaciosOcupadosEstructura(listadoDeProductos, LENGHT_PRODUCTOS);
					if(validacion != -1){
						saltoDeLinea(1);
						modificarProductos(listadoDeProductos,LENGHT_PRODUCTOS,listadoDeTiposProductos,LENGHT_TIPO_PRODUCTOS,listadoDeNacionalidades,LENGHT_NACIONALIDADES);
					} else {
						printf("\n--------No hay productos cargados--------\n\n");
					}
				break;

			case 4:
				validacion=comprobarEspaciosOcupadosEstructura(listadoDeProductos, LENGHT_PRODUCTOS);
				if(validacion != -1){
					saltoDeLinea(1);
					mostrarListadoProductos(listadoDeProductos, LENGHT_PRODUCTOS);
				} else {
					printf("\n--------No hay productos cargados--------\n\n");
				}
				break;
			case 5:
				validacion=comprobarEspaciosOcupadosEstructura(listadoDeProductos, LENGHT_PRODUCTOS);
				if(validacion != -1){
					insertionSortNumbPrecio(listadoDeProductos, LENGHT_PRODUCTOS);
					saltoDeLinea(1);
					mostrarListadoProductos(listadoDeProductos, LENGHT_PRODUCTOS);
				} else {
					printf("\n--------No hay productos cargados--------\n\n");
				}
				break;

			case 6:
				validacion=comprobarEspaciosOcupadosEstructura(listadoDeProductos, LENGHT_PRODUCTOS);
				if(validacion != -1){
					insertionSortNumbDescripcion(listadoDeProductos, LENGHT_PRODUCTOS);
					saltoDeLinea(1);
					mostrarListadoProductos(listadoDeProductos, LENGHT_PRODUCTOS);
				} else {
					printf("\n--------No hay productos cargados--------\n\n");
				}
				break;
			case 7:
				validacion=comprobarEspaciosOcupadosEstructura(listadoDeProductos, LENGHT_PRODUCTOS);
				if(validacion != -1){
					saltoDeLinea(1);
					productosMasCaros(listadoDeProductos, LENGHT_PRODUCTOS);
				} else {
					printf("\n--------No hay productos cargados--------\n\n");
				}
				break;

			case 8:
				validacion=comprobarEspaciosOcupadosEstructura(listadoDeProductos, LENGHT_PRODUCTOS);
				if(validacion != -1){
					printPromediosPorTipo(listadoDeProductos,LENGHT_PRODUCTOS,listadoDeTiposProductos,LENGHT_TIPO_PRODUCTOS);
				} else {
					printf("\n--------No hay productos cargados--------\n\n");
				}
				break;
			case 9:

				validacion=comprobarEspaciosOcupadosEstructura(listadoDeProductos, LENGHT_PRODUCTOS);
				if(validacion != -1){
					mostrarListadoProductosConDescTipo(listadoDeProductos,LENGHT_PRODUCTOS,listadoDeTiposProductos,LENGHT_TIPO_PRODUCTOS);
				} else {
					printf("\n--------No hay productos cargados--------\n\n");
				}
				break;
			case 10:
				validacion=comprobarEspaciosOcupadosEstructura(listadoDeProductos, LENGHT_PRODUCTOS);
				if(validacion != -1){
					mostrarListadoTipoProductoYProducto(listadoDeProductos,LENGHT_PRODUCTOS,listadoDeTiposProductos,LENGHT_TIPO_PRODUCTOS);
				} else {
					printf("\n--------No hay productos cargados--------\n\n");
				}
				break;

			case 11:
				validacion=comprobarEspaciosOcupadosEstructura(listadoDeProductos, LENGHT_PRODUCTOS);
				if(validacion != -1){
					calcularTiposConMasProductos(listadoDeProductos,LENGHT_PRODUCTOS,listadoDeTiposProductos,LENGHT_TIPO_PRODUCTOS);
				} else {
					printf("\n--------No hay productos cargados--------\n\n");
				}
				break;
			case 12:
				validacion=comprobarEspaciosOcupadosEstructura(listadoDeProductos, LENGHT_PRODUCTOS);
				if(validacion != -1){
					calcularNacionalidadFabricaIphone(listadoDeProductos,LENGHT_PRODUCTOS,listadoDeTiposProductos,LENGHT_TIPO_PRODUCTOS, listadoDeNacionalidades, LENGHT_NACIONALIDADES);
				} else {
					printf("\n--------No hay productos cargados--------\n\n");
				}
				break;
			case 13:
				validacion=comprobarEspaciosOcupadosEstructura(listadoDeProductos, LENGHT_PRODUCTOS);
				if(validacion != -1){
					insertionSortNumbNacionalidad(listadoDeNacionalidades, LENGHT_NACIONALIDADES);
					saltoDeLinea(2);
					printProductosOrdenadosPorNacionalidad(listadoDeProductos, LENGHT_PRODUCTOS, listadoDeNacionalidades, LENGHT_NACIONALIDADES);
				} else {
					printf("\n--------No hay productos cargados--------\n\n");
				}
				break;
			case 14:
				validacion=comprobarEspaciosOcupadosEstructura(listadoDeProductos, LENGHT_PRODUCTOS);
				if(validacion != -1){
					saltoDeLinea(2);
					calcularNacionConMasProductos(listadoDeProductos, LENGHT_PRODUCTOS, listadoDeNacionalidades, LENGHT_NACIONALIDADES);
				} else {
					printf("\n--------No hay productos cargados--------\n\n");
				}
				break;
			case 15:
				validacion=comprobarEspaciosOcupadosEstructura(listadoDeProductos, LENGHT_PRODUCTOS);
				if(validacion != -1){
					saltoDeLinea(1);
					printPromediosPorNacion(listadoDeProductos, LENGHT_PRODUCTOS, listadoDeNacionalidades, LENGHT_NACIONALIDADES);
				} else {
					printf("\n--------No hay productos cargados--------\n\n");
				}
				break;
			default:
				printf("\nGracias por utilizar el programa.");
				break;
		}
	}while(opcion != 16);

	return EXIT_SUCCESS;
}

