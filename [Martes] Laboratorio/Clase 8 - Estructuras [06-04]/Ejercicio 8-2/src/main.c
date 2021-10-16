/*
 * Luciano Crocco 1ºF
 * Ejercicio 10-3:
 *
	Ejercicio 8-2:
	Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los siguientes datos:
	idProducto (numerico)
	descripcion (alfanumérico)
	nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
	tipo (numérico, por el momento utilizaremos un define: IPHONE -MAC - IPAD - ACCESORIOS)
	precio (numérico decimal)
	Realizar un programa que permita interactuar con un menú de usuarios con las siguientes opciones:
	1) ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array.
	2) BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
	3) MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio o el tipo.
	4) LISTADO Productos.
	5) LISTADO ordenado por precio.
	6) LISTADO ordenado por descripción.

	Falta hacer un menu mas eficiente y correguir algunas funciones.
 */


#include <stdio_ext.h>
#include <stdlib.h>
#include "Funciones.h"

#define LENGHT_PRODUCTOS 25

int main (void){

	setbuf(stdout,NULL);

	eProductos listadoDeProductos[LENGHT_PRODUCTOS];

	inicializarIsEmptyEstructura(listadoDeProductos, LENGHT_PRODUCTOS);
	hardocodearElementos(listadoDeProductos);

	int opcion;
	int validacion;

	do{
	opcion = pedirEnteroConRango("---LISTA DE OPCIONES---\n\n1. Alta producto\n2. Baja Producto\n3. Modificar producto\n4. Listado Productos\n5. Listado ordenado por precio\n6. Listado ordenado por descripcion\n7. Salir: ", "Error... Ingrese un indice valido", 1, 7);

		switch(opcion){
			case 1:
				altaLogicaListaEstrucutra(listadoDeProductos, LENGHT_PRODUCTOS);
				break;
			case 2:
				bajaLogicaListaEstrucutra(listadoDeProductos, LENGHT_PRODUCTOS);
				break;
			case 3:
				modificarEstructura(listadoDeProductos, LENGHT_PRODUCTOS);
				break;
			case 4:
				validacion=comprobarEspaciosOcupadosEstructura(listadoDeProductos, LENGHT_PRODUCTOS);
				if(validacion != -1){
					mostrarListadoEstructura(listadoDeProductos, LENGHT_PRODUCTOS);
				} else {
					printf("\n--------No hay productos cargados--------\n\n");
				}
				break;
			case 5:
				validacion=comprobarEspaciosOcupadosEstructura(listadoDeProductos, LENGHT_PRODUCTOS);
					if(validacion != -1){
						//simpleBubbleSortNumbsPrecio(listadoDeProductos, LENGHT_PRODUCTOS);
						insertionSortNumbPrecio(listadoDeProductos, LENGHT_PRODUCTOS);
						mostrarListadoEstructura(listadoDeProductos, LENGHT_PRODUCTOS);
					} else {
						printf("\n--------No hay productos cargados--------\n\n");
					}
				break;
			case 6:
				validacion=comprobarEspaciosOcupadosEstructura(listadoDeProductos, LENGHT_PRODUCTOS);
					if(validacion != -1){
						insertionSortNumbDescripcion(listadoDeProductos, LENGHT_PRODUCTOS);
						mostrarListadoEstructura(listadoDeProductos, LENGHT_PRODUCTOS);
					} else {
						printf("\n--------No hay productos cargados--------\n\n");
					}
					break;
			default:
				printf("\nGracias por utilizar el programa.");
				break;
		}
	}while(opcion != 7);


	return EXIT_SUCCESS;

}

