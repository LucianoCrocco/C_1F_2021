/*
 * eProducto.c
 *
 *  Created on: 18 may. 2021
 *      Author: luciano
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "eProducto.h"

eProducto* crearProductoHardcodeado(void){

	eProducto hardcodeado={1,"Compu", 125.60, OCUPADO};
	eProducto* pHardcodeado;
	pHardcodeado = &hardcodeado;
/* Cualquiera de las dos opciones son correctas.
	pHardcodeado->isEmpty = OCUPADO;
	pHardcodeado->idProducto = 1;
	pHardcodeado->precio = 1500.20;
	strcpy(pHardcodeado->descripcion, "Hola que tal");*/


	return pHardcodeado;
}

void mostrarUnElementoProductos(eProducto* unProducto){

	printf("ID del producto: %d\n", unProducto->idProducto);
	printf("Descripcion: %s\n", unProducto->descripcion);
	printf("Precio: %.2f\n\n", unProducto->precio);
}
