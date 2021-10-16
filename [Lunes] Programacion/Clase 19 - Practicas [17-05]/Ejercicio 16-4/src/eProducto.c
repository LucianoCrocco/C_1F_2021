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

void hardocodearDatosUnaStructProductos(eProducto* lista){
	int i;

	int idProducto[3]={1100, 1000, 1200};
	char descripcion[3][STRING_LENGHT]={"Cargador", "Computadora", "Tablet"};
	float precio[3]={100, 1250.40, 300};
	int isEmpty[3]= {OCUPADO, OCUPADO, OCUPADO};


	for(i=0;i<3;i++){
		lista[i].idProducto=idProducto[i];
		strcpy(lista[i].descripcion,descripcion[i]);
		lista[i].precio=precio[i];
		lista[i].isEmpty=isEmpty[i];
	}

}

int Ordenador(eProducto* lista,int len, int(*pFunc)(eProducto*, eProducto*)){
	int i;
	int j;

	if(lista != NULL && len >= 0){
		for(i=0;i<len-1;i++){
			if(lista[i].isEmpty == OCUPADO){
				for(j=i+1;j<len;j++){
					if(lista[j].isEmpty == OCUPADO){
						if(pFunc(&lista[i], &lista[j]) == 0){
							puts("\nError...\n");
						}
					}
				}
			}
		}
	} else{
		return 0;
	}
	return 1;
}

int CompararPorMarca(eProducto* primerElemento, eProducto* segundoElemento){
	eProducto aux;
	if (primerElemento != NULL && segundoElemento != NULL){
		if(strcmp(primerElemento->descripcion,segundoElemento->descripcion) > 0){
			aux = *primerElemento;
			*primerElemento = *segundoElemento;
			*segundoElemento = aux;
		}
	} else {
		return 0;
	}
	return 1;
}
int ComparaPorPrecio(eProducto* primerElemento, eProducto* segundoElemento){
	eProducto aux;
	if (primerElemento != NULL && segundoElemento != NULL){
		if(primerElemento->precio < segundoElemento->precio){
			aux = *primerElemento;
			*primerElemento = *segundoElemento;
			*segundoElemento = aux;
		}
	} else {
		return 0;
	}
	return 1;
}


int pedirEnteroConRango(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
	int numero;
	int rtn;

	rtn = 0;

	if(mensaje !=NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
		printf("%s",mensaje);
		scanf("%d",&numero);
		while((numero < minimo || numero > maximo) && reintentos >= 0){
			printf("\n%s\n\n",mensajeError);
			printf("%s",mensaje);
			scanf("%d",&numero);
		}
	} else {
		return 0;
	}

	if((numero >= minimo && numero <= maximo) && reintentos >= 0){
		rtn = 1;
		*pResultado = numero;
	}

	return rtn;
}


void mostrarListadoProductos(eProducto* lista, int lenghtArray){
	int i;
	for(i=0;i<lenghtArray;i++){
		if(lista[i].isEmpty == OCUPADO){
			mostrarUnElementoProductos(&lista[i]);
		}
	}
}

void mostrarUnElementoProductos(eProducto* unProducto){

	printf("ID del producto: %d\n", unProducto->idProducto);
	printf("Descripcion: %s\n", unProducto->descripcion);
	printf("ID Nacionalidad: %d\n", unProducto->idProducto);
	printf("Precio: %.2f\n\n", unProducto->precio);
}
