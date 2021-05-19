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

eProducto* cargarProducto(void){//Constructor por defecto
	eProducto* pProducto;

	/*			USO DE MALLOC PARA RESERVAR MEMORIA EN EL HEAP || Memory Allocator
	 * pProducto = (eProducto*)malloc(sizeof(eProducto));//Polimorfismo

	printf("En la pila/stack: %p--- En el Heap/Monton:%p\n\n", &pProducto, pProducto);

	if(pProducto != NULL){
		pProducto->idProducto= 15;
		strcpy(pProducto->descripcion,"Coca Cola");
		pProducto->precio=120.50;
		pProducto->isEmpty=OCUPADO;
	}*/

	/*			USO DE CALLOC PARA RESERVAR MEMORIA EN EL HEAP ||
	 * Calloc inicializa en 0 todos los elementos*/
	 pProducto = (eProducto*)calloc(sizeof(eProducto),1);//El 1 indica la cantidad que necesito (array o no)

	printf("En la pila/stack: %p--- En el Heap/Monton:%p\n\n", &pProducto, pProducto);

	return pProducto;
}

eProducto* cargarProductoConParametros(int id, char* descripcion, float precio, int emptyness){
	eProducto* pProducto;

	pProducto = cargarProducto();

	if(pProducto != NULL){
		pProducto->idProducto= id;
		strcpy(pProducto->descripcion,"descripcion");
		pProducto->precio=precio;
		pProducto->isEmpty=emptyness;
	}
	return pProducto;
}

void mostrarUnElementoProductos(eProducto* unProducto){

	if(unProducto != NULL){
		printf("ID del producto: %d\n", unProducto->idProducto);
		printf("Descripcion: %s\n", unProducto->descripcion);
		printf("Precio: %.2f\n\n", unProducto->precio);
	}
}
