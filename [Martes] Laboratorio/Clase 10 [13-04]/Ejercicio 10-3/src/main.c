/*
 * Luciano Crocco 1ºF
 * Ejercicio 10-3:
 */
#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

#define LENGHT_PRODUCTOS 25
#define LENGHT_TIPO_PRODUCTOS 4
#define LENGHT_NACIONALIDADES 3

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
				altaListaEstructura(listadoDeProductos,LENGHT_PRODUCTOS,listadoDeTiposProductos,LENGHT_TIPO_PRODUCTOS);
				break;
			case 2:
				bajaListaEstructura(listadoDeProductos,LENGHT_PRODUCTOS);
				break;
			case 3:
				modificarProductos(listadoDeProductos,LENGHT_PRODUCTOS,listadoDeTiposProductos,LENGHT_TIPO_PRODUCTOS);
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
					//mostrarListadoProductosConDescTipo(listadoDeProductos,LENGHT_PRODUCTOS,listadoDeTiposProductos,LENGHT_TIPO_PRODUCTOS);
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
			default:
				printf("\nGracias por utilizar el programa.");
				break;
		}
	}while(opcion != 11);

	return EXIT_SUCCESS;
}
