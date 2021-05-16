/*
 * eServicio.c
 *
 *  Created on: 4 may. 2021
 *      Author: luciano
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "Utilidades.h"
#include "eServicio.h"

void inicializarIsEmptyServicios(eServicio lista[], int lenghtArray){
	int i;

	for(i=0;i<lenghtArray;i++){
		lista[i].isEmpty = VACIO;
	}
}

void hardocodearDatosUnaStructServicios(eServicio lista[]){
	int i;

	int id[4]={20000, 20001, 20002, 20003};
	char descripcion[4][STRING_LENGHT_SERVICIO]={"LIMPIEZA", "PARCHE", "CENTRADO", "CADENA"};
	float precio[4]={250, 300, 400, 350};
	int isEmpty[4]= {OCUPADO, OCUPADO, OCUPADO, OCUPADO};

	for(i=0;i<4;i++){
		lista[i].id=id[i];
		strcpy(lista[i].descripcion,descripcion[i]);
		lista[i].precio=precio[i];
		lista[i].isEmpty=isEmpty[i];
	}

}


int comprobarEspaciosVaciosEstructuraServicios(eServicio lista[], int lenghtArray){
    int i;
    int retorno;

    retorno = -1;

    for(i=0;i<lenghtArray;i++){
        if(lista[i].isEmpty==VACIO){
        	retorno = i;
			break;
        }
    }

    return retorno;
}


int comprobarEspaciosOcupadosEstructuraServicios(eServicio lista[], int lenghtArray){
    int i;
    int retorno;

    retorno = -1;

    for(i=0;i<lenghtArray;i++){
        if(lista[i].isEmpty==OCUPADO){
        	retorno = 1;
			break;
        }
    }
    return retorno;
}

//PARTE 5
void mostrarListadoServicios(eServicio  lista[], int lenghtArray){
	int i;
	for(i=0;i<lenghtArray;i++){
		if(lista[i].isEmpty == OCUPADO){
			mostrarUnElementoServicios(lista[i]);
		}
	}
}


void mostrarUnElementoServicios(eServicio unElemento){
	printf("Id: %d\tDescripcion: %s\tPrecio: %f\n", unElemento.id, unElemento.descripcion, unElemento.precio);
}


int comprobarIndexOcupadoServicios(eServicio lista[], int lenghtArray, int numero){
	int i;
	int retorno;

	retorno = -1;

	for(i=0;i<lenghtArray;i++){
		if(lista[i].id == numero && lista[i].isEmpty == OCUPADO){
			retorno = i;
			break;
		}
	}
	return retorno;
}
