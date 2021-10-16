/*
 * Luciano Crocco 1ºF
 * Ejercicio 7-1
 *CON ARRAY PARELELOS
Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los siguientes datos:
1 -> idProducto (numerico)
2 -> descripcion (alfanumérico)
3 -> nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
4 -> tipo (numérico, por el momento utilizaremos un define:  MAC - IPHONE - IPAD - ACCESORIOS)
5 -> precio (numérico decimal)

Realizar un programa que permita interactuar con un menú de usuarios con las siguientes opciones:

1 -> ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array.
2 -> BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
3 -> MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio o el tipo.
4 -> LISTADO Productos.
5 -> LISTADO ordenado por precio.
6 -> LISTADO ordenado por descripción.


 */

#include <stdio_ext.h>
#include <stdlib.h>
#include "Funciones.h"
#define MAX_PRODUCTOS 10
#define MAX_CADENA 30

int main (void){

	int idProducto[MAX_PRODUCTOS];// = {1000, 1004, 1100};
	float nacionalidad[MAX_PRODUCTOS];//  = {10, 5.5, 7.5};
	float tipo[MAX_PRODUCTOS];//  = {5, 10, 5.5};
	float precio[MAX_PRODUCTOS];

	//char nombres[FILAS][COLUMNAS];
	char descripcion[MAX_PRODUCTOS][MAX_CADENA];//  = {"Juan", "Pepe", "Ana"};

	int opcion;
	int index;


	InicializarProductos(idProducto, MAX_PRODUCTOS);

	do
	{
		printf("1. ALTA\n");
		printf("2. BAJA\n");
		printf("3. MODIFICACION\n");
		printf("4. ORDENAR y MOSTRAR\n");
		printf("10. Salir\n");
		printf("Elija una opcion:");
		scanf("%d", &opcion);

		switch(opcion)
		{
			case 1:

				index = CargarUnAlumno(idProducto, nacionalidad, tipo, precio, descripcion, MAX_PRODUCTOS);
				if(index==-1)
				{
					printf("No hay espacio disponible en la lista...");
				}
				else
				{
					printf("Alumno cargado con exito!!!");
				}

			break;
			case 2:
				askBajaAlumnos(idProducto, nacionalidad, tipo, precio, descripcion, MAX_PRODUCTOS);
				break;
			case 3:
				askModificarAlumnos(idProducto, nacionalidad, tipo, precio, descripcion, MAX_PRODUCTOS);
			break;
			case 4:
			   MostrarTodosLosAlumnos(idProducto, nacionalidad, tipo, precio, descripcion, MAX_PRODUCTOS);
			break;
			case 5:
				break;
			case 6:
				break;
		}
	}while(opcion!=10);

	return EXIT_SUCCESS;
}

