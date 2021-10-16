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

eProducto* cargarProducto(void){
	eProducto* pProducto;
	 pProducto = (eProducto*)calloc(sizeof(eProducto),1);

	printf("En la pila/stack: %p--- En el Heap/Monton:%p\n\n", &pProducto, pProducto);

	return pProducto;
}

eProducto* cargarProductoConParametros(int id, char* descripcion, float precio, int emptyness){
	eProducto* pProducto;

	pProducto = cargarProducto();

	if(pProducto != NULL){
		if(eProducto_setId(pProducto, id)){
			strcpy(pProducto->descripcion,"descripcion");
			pProducto->precio=precio;
			pProducto->isEmpty=emptyness;
		}
	}
	return pProducto;
}

void mostrarUnElementoProductos(eProducto* unProducto){
	int id;

	id = eProducto_getId(unProducto);

	if(unProducto != NULL && id != -1){
		printf("ID del producto: %d\n", id);
		printf("Descripcion: %s\n", unProducto->descripcion);
		printf("Precio: %.2f\n\n", unProducto->precio);
	}
}


//getters y setters
int eProducto_setId(eProducto* miProducto, int valor){//Puntero a la estructura y el ID que voy a implementar.
	int exito;
	exito = 0;

	if(miProducto != NULL && (valor > 0 && valor < 1000)){//AL ser un ID puedo ponerle un rango. Normalmente son positivos y no negativos
		miProducto->idProducto = valor;
		exito = 1;
	}

	return exito;
}

int eProducto_getId(eProducto* this){
	int id;

	id = -1;//El valor ilogico que le damos si es NULL el puntero.

	if(this != NULL){
		id = this->idProducto;
	}

	return id;
}

// O

int eProducto_getId(eProducto* this, int* id){


	if(this != NULL){
		id = this->idProducto;
	} else {
		return 0;
	}

	return 1;
}

