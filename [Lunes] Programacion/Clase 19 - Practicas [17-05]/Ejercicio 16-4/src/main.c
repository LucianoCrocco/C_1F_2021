/******************************************************************************

Luciano Crocco 1ºF
Ejercicio 16-4

Realizar una función que respete el siguiente prototipo:
int Ordenador(eProducto*,int , int(*pFunc)(eProducto*, eProducto*));

La función Ordenador recibirá como parámetros:
el array de productos, dado por el puntero a eProducto
la cantidad de elementos del array
el criterio de ordenamiento, dado por la función pFunc.

Veamos un  ejemplo de la función criterio:
int CompararPorMarca(eProducto*,eProducto*);
int ComparaPorPrecio(eProducto*,eProducto*);


*******************************************************************************/
#include <stdio_ext.h>
#include <stdlib.h>
#include "eProducto.h"

#define LENGHT_PRODUCTOS 3

int main()
{
	int opcion;
	eProducto listaProductos[LENGHT_PRODUCTOS];

	hardocodearDatosUnaStructProductos(listaProductos);
    setbuf(stdout,NULL);

    do {
    	if(pedirEnteroConRango(&opcion, "1. Ordenar por Marca\n2. Ordenar por Precio\n3. Salir: ", "Error... Ingrese una opcion valida", 1, 3, 0) != 0){
    		switch(opcion){
				case 1:
					Ordenador(listaProductos, LENGHT_PRODUCTOS, CompararPorMarca);
					mostrarListadoProductos(listaProductos, LENGHT_PRODUCTOS);
					break;
				case 2:
					Ordenador(listaProductos, LENGHT_PRODUCTOS, ComparaPorPrecio);
					mostrarListadoProductos(listaProductos, LENGHT_PRODUCTOS);
					break;
    		}
    	}
    }while(opcion != 3);

    return EXIT_SUCCESS;
}


