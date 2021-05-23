/*
 * eNacionalidad.c
 *
 *  Created on: 2 may. 2021
 *      Author: luciano
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Utilidades.h"
#include "eNacionalidad.h"

/************************************************************************************************************/
/*************************************************HARDCODEOS*************************************************/
/************************************************************************************************************/

void hardocodearDatosUnaStructNacionalidades(eNacionalidad lista[]){
	int i;

	int idNacionalidad[3]={1, 2, 3};
	char descripcionNacionalidad[3][STRING_LENGHT]={"EEUU", "CHINA", "OTROS"};
	int isEmpty[3]= {OCUPADO, OCUPADO, OCUPADO};

	for(i=0;i<3;i++){
		lista[i].idNacionalidad=idNacionalidad[i];
		strcpy(lista[i].descripcionNacionalidad,descripcionNacionalidad[i]);
		lista[i].isEmpty=isEmpty[i];
	}

}


void inicializarIsEmptyNacionalidades(eNacionalidad lista[], int lenghtArray){
	int i;
	for(i=0;i<lenghtArray;i++){
		lista[i].isEmpty = VACIO;
	}
}

/************************************************************************************************************/
/************************************************VALIDACIONES************************************************/
/************************************************************************************************************/

int comprobarIndexOcupadoNacionalidad(eNacionalidad lista[], int lenghtArray, int numero){
	int i;
	int retorno;

	retorno = -1;

	for(i=0;i<lenghtArray;i++){
		if(lista[i].idNacionalidad==numero && lista[i].isEmpty == OCUPADO){
			retorno=i;
			break;
		}
	}
	return retorno;
}

int comprobarEspaciosOcupadosEstructuraNacion(eNacionalidad lista[], int lenghtArray){
	int i;
	int retorno;

	retorno = -1;

	for(i=0;i<lenghtArray;i++){
		if(lista[i].isEmpty == OCUPADO){
			retorno = i;
			break;
		}
	}
	return retorno;
}

int comprobarEspaciosVaciosEstructuraNacion(eNacionalidad lista[], int lenghtArray){
	int i;
	int retorno;

	retorno = -1;

	for(i=0;i<lenghtArray;i++){
		if(lista[i].isEmpty == VACIO){
			retorno = i;
			break;
		}
	}
	return retorno;
}
/************************************************************************************************************/
/****************************************************A.B.M***************************************************/
/************************************************************************************************************/

//								CASE 1 y 3

void mostrarListadoNacionalidad(eNacionalidad lista[], int lenghtArray){
	int i;
	for(i=0;i<lenghtArray;i++){
		if(lista[i].isEmpty == OCUPADO){
			mostrarUnElementoNacionalidad(lista[i]);
		}
	}
}


void mostrarUnElementoNacionalidad(eNacionalidad unElemento){
	printf("Id: %d\tNacionalidad: %s\n", unElemento.idNacionalidad, unElemento.descripcionNacionalidad);
}


//								CASE 13
void insertionSortNumbNacionalidad(eNacionalidad listaNacion[], int lenghtArray){
	int i;
	int j;
	eNacionalidad aux;


	for(i=1;i<lenghtArray;i++){
		if(listaNacion[i].isEmpty==OCUPADO){
			aux = listaNacion[i];
			j=i-1;
			while(j>=0 && strcmp(aux.descripcionNacionalidad,listaNacion[j].descripcionNacionalidad) < 0){
				listaNacion[j+1] = listaNacion[j];
				j--;
			}
			listaNacion[j+1]= aux; //insercion
		}
	}
}


//								CASE 19
void altaListaEstructuraNacionalidad(eNacionalidad listaNacion[], int lenghtArray){

	int index;

	index = comprobarEspaciosVaciosEstructuraNacion(listaNacion, lenghtArray);
	if(index != -1){
		cargarDatosEstructuraNacionalidad(listaNacion, lenghtArray, index);
	} else {
		printf("\nNo hay espacios disponibles en la memoria\n");
	}

}

void cargarDatosEstructuraNacionalidad(eNacionalidad listaNacion[], int lenghtArray, int index){
	int validacion;

	listaNacion[index].idNacionalidad=pedirEnteroConRango("Ingrese el ID de la nueva nacionalidad: ", "Error... Ingrese un ID mayor a 1 y menor a 300", 1, 300);
	validacion=comprobarIndexOcupadoNacionalidad(listaNacion,lenghtArray,listaNacion[index].idNacionalidad);
	while(validacion != -1){
		listaNacion[index].idNacionalidad=pedirEnteroConRango("Error... El ID ingresado ya existe\nIngrese el ID de la nueva nacionalidad: ", "Error... Ingrese un ID mayor a 1 y menor a 300", 1, 300);
		validacion=comprobarIndexOcupadoNacionalidad(listaNacion,lenghtArray,listaNacion[index].idNacionalidad);
	}

	printf("Ingrese la descripcion de la nacionalidad: ");
	__fpurge(stdin);
	scanf("%[^\n]",listaNacion[index].descripcionNacionalidad);

	listaNacion[index].isEmpty = OCUPADO;
}

//								CASE 20
int bajaListaEstructuraNacionalidad(eNacionalidad listaNacion[], int lenghtArray){
	int datoAComparar;
	int index;

	mostrarListadoNacionalidad(listaNacion, lenghtArray);
	datoAComparar = pedirEntero("Ingrese el id de la nacionalidad a dar de baja: ");

	index = comprobarIndexOcupadoNacionalidad(listaNacion, lenghtArray, datoAComparar);
	if(index == -1){
		printf("\nError... el ID de la nacionalidad ingresado no es valido\n");
	} else {
		listaNacion[index].isEmpty = VACIO;
		printf("\nProducto borrado\n");
	}
	return listaNacion[index].idNacionalidad;
}


//								CASE 21
void modificarNacionalidad(eNacionalidad listaNacion[], int lenghtArray){
	int datoABuscar;
	int index;

	mostrarListadoNacionalidad(listaNacion, lenghtArray);
	datoABuscar = pedirEntero("\nIngrese el ID de la nacionalidad para modificar los datos: ");

	index = comprobarIndexOcupadoNacionalidad(listaNacion,lenghtArray,datoABuscar);
	if(index == -1){
		printf("\nError... el dato comparado ingresado no es valido/no existe\n");
	} else {
		modificarDatoNacionalidad(listaNacion ,index);
	}
}

void modificarDatoNacionalidad(eNacionalidad listaNacion[], int index){
	int flagModifico;
	int opciones;

	flagModifico = 0;

	do {
		opciones=pedirEnteroConRango("1. Cambiar la descripcion de la nacionalidad\n2. Salir\nIngrese una opcion: ", "Error...Ingrese una opcion valida" , 1 ,2);
		switch(opciones){
		case 1:
			printf("Ingrese la nueva descripcion de la nacionalidad: ");
			__fpurge(stdin);
			scanf("%[^\n]",listaNacion[index].descripcionNacionalidad);
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

