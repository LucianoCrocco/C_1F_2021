/*
 * eTipoProducto.c
 *
 *  Created on: 2 may. 2021
 *      Author: luciano
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Utilidades.h"
#include "eTipoProducto.h"

/************************************************************************************************************/
/*************************************************HARDCODEOS*************************************************/
/************************************************************************************************************/

void inicializarIsEmptyTipoProductos(eTipoProducto lista[], int lenghtArray){
	int i;
	for(i=0;i<lenghtArray;i++){
		lista[i].isEmpty = VACIO;
	}
}


void hardocodearDatosUnaStructTipoProductos(eTipoProducto lista[]){
	int i;

	int idTipo[4]={1000, 1001, 1002, 1003};
	char descripcionTipo[4][STRING_LENGHT]={"Iphone", "Ipad", "Mac", "Accesorios"};
	int isEmpty[4]= {OCUPADO, OCUPADO, OCUPADO, OCUPADO};

	for(i=0;i<4;i++){
		lista[i].idTipo=idTipo[i];
		strcpy(lista[i].descripcionTipo,descripcionTipo[i]);
		lista[i].isEmpty=isEmpty[i];
	}

}

/************************************************************************************************************/
/************************************************VALIDACIONES************************************************/
/************************************************************************************************************/

int comprobarEspaciosOcupadosEstructuraTipo(eTipoProducto lista[], int lenghtArray){
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

int comprobarEspaciosVaciosEstructuraTipo(eTipoProducto lista[], int lenghtArray){

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

int comprobarIndexOcupadoTipo(eTipoProducto lista[], int lenghtArray, int numero){
	int i;
	int retorno;

	retorno = -1;

	for(i=0;i<lenghtArray;i++){
		if(lista[i].idTipo == numero && lista[i].isEmpty == OCUPADO){
			retorno = i;
			break;
		}
	}
	return retorno;
}

/************************************************************************************************************/
/****************************************************A.B.M***************************************************/
/************************************************************************************************************/

//								CASE 1 Y 3

void mostrarListadoTipoProducto(eTipoProducto  lista[], int lenghtArray){
	int i;
	for(i=0;i<lenghtArray;i++){
		if(lista[i].isEmpty == OCUPADO){
			mostrarUnElementoTipoProducto(lista[i]);
		}
	}
}


void mostrarUnElementoTipoProducto(eTipoProducto unElemento){
	printf("Id: %d\tDescripcion: %s\n", unElemento.idTipo, unElemento.descripcionTipo);
}


//								CASE 12
int buscarIdTipoEspecifico(char nombre[], eTipoProducto listaTipo[], int lenghtTipo){

	int i;
	int idRetorno;

	idRetorno = 1;

	for(i=0;i<lenghtTipo;i++){
		if(listaTipo[i].isEmpty == OCUPADO && strcmp(listaTipo[i].descripcionTipo, nombre) == 0){
			idRetorno = listaTipo[i].idTipo;
		}
	}

	return idRetorno;
}


//								CASE 16
void altaListaEstructuraTipo(eTipoProducto listaTipo[], int lenghtTipo){
	int index;

	index = comprobarEspaciosVaciosEstructuraTipo(listaTipo, lenghtTipo);
	if(index != -1){
		cargarDatosEstructuraTipo(listaTipo, lenghtTipo, index);
	} else {
		printf("\nNo hay espacios disponibles en la memoria\n");
	}
}


void cargarDatosEstructuraTipo(eTipoProducto listaTipo[], int lenghtTipo, int index){
	int validacion;

	listaTipo[index].idTipo=pedirEnteroConRango("Ingrese el ID del nuevo tipo de producto: ", "Error... Ingrese un ID mayor a 1 y menor a 10.000", 1, 10000);
	validacion=comprobarIndexOcupadoTipo(listaTipo, lenghtTipo, listaTipo[index].idTipo);
	while(validacion != -1){
		listaTipo[index].idTipo=pedirEnteroConRango("Error... El ID ingresado ya existe\nIngrese el ID del nuevo tipo de producto: ", "Error... Ingrese un ID mayor a 1 y menor a 1'.000", 1, 10000);
		validacion=comprobarIndexOcupadoTipo(listaTipo, lenghtTipo, listaTipo[index].idTipo);
	}

	printf("Ingrese la descripcion del tipo: ");
	__fpurge(stdin);
	scanf("%[^\n]",listaTipo[index].descripcionTipo);

	listaTipo[index].isEmpty=OCUPADO;

}

//								CASE 17
int bajaListaEstructuraTipo(eTipoProducto listaTipo[], int lenghtTipo){
	int datoAComparar;
	int index;

	mostrarListadoTipoProducto(listaTipo, lenghtTipo);
	datoAComparar = pedirEntero("Ingrese el id del tipo a dar de baja: ");

	index = comprobarIndexOcupadoTipo(listaTipo,lenghtTipo,datoAComparar);
	if(index == -1){
		printf("\nError... el ID del producto ingresado no es valido\n");
	} else {
		listaTipo[index].isEmpty = VACIO;
		printf("\nProducto borrado\n");
	}

	return listaTipo[index].idTipo;
}


//								CASE 18
void modificarTipo(eTipoProducto listaTipo[], int lenghtTipo){
	int datoABuscar;
	int index;

	mostrarListadoTipoProducto(listaTipo, lenghtTipo);
	datoABuscar = pedirEntero("\nIngrese el ID del Tipo para modificar los datos: ");

	index = comprobarIndexOcupadoTipo(listaTipo,lenghtTipo,datoABuscar);
	if(index == -1){
		printf("\nError... el dato comparado ingresado no es valido/no existe\n");
	} else {
		modificarDatoTipo(listaTipo ,index);
	}
}

void modificarDatoTipo(eTipoProducto listaTipo[], int index){
	int flagModifico;
	int opciones;

	flagModifico = 0;

	do {
		opciones=pedirEnteroConRango("1. Cambiar la descripcion del tipo de producto\n2. Salir\nIngrese una opcion: ", "Error...Ingrese una opcion valida" , 1 ,2);
		switch(opciones){
		case 1:
			printf("Ingrese la nueva descripcion del tipo: ");
			__fpurge(stdin);
			scanf("%[^\n]",listaTipo[index].descripcionTipo);
			flagModifico++;
			break;
		}

	}while(opciones != 2);

	if(flagModifico==0){
		printf("\nNo se modificaron datos.\n");
	} else {
		printf("\nDatos modificados correctamente.\n");
	}
}
