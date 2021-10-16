/*
 * Utilidades.c
 *
 *  Created on: 24 abr. 2021
 *      Author: luciano
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Estructuras.h"
#include "Utilidades.h"

/************************************************************************************************************/
/**************************************************UTILIDADES************************************************/
/************************************************************************************************************/

int menu(void){

	int opcionMenu;
	printf("\n-----OPCIONES-----\n");
	printf("1. Alta producto\n");
	printf("2. Baja producto\n");
	printf("3. Modificacion producto\n");
	printf("4. Listado producto\n");
	printf("5. Listado producto ordenado por precio\n");
	printf("6. Listado producto ordenado por descripcion\n");;
	printf("7. El/los  productos mas caros\n");
	printf("8. Precio promedio por tipo de producto. Se deberá mostrar la descripción del tipo y a continuación el precio promedio.\n");
	printf("9. El listado de todos los productos con la descripción del tipo\n");
	printf("10. Por cada tipo la lista de productos\n");
	printf("11. El/los tipos de productos con mas productos elaborados\n");
	printf("12. Salir\n");
	opcionMenu=pedirEnteroConRango("Ingrese una opcion: ", "Error...Ingrese una opcion valida", 1, 12);

	return opcionMenu;
}

void saltoDeLinea(int cantidad){
	int i;
	for(i=0;i<cantidad;i++){
		printf("\n");
	}
}

void incializarArrayEnCero(int array[], int cantidad){
	int i;

	for(i=0;i<cantidad;i++){
		array[i]=0;
	}
}

/************************************************************************************************************/
/***********************************************PEDIR FUNCIONES**********************************************/
/************************************************************************************************************/

int pedirEnteroConRango(char mensaje[], char mensajeError[], int minimo, int maximo){
	int numero;

	printf("%s",mensaje);
	scanf("%d",&numero);
	while(numero < minimo || numero > maximo){
		printf("\n%s\n\n",mensajeError);
		printf("%s",mensaje);
		scanf("%d",&numero);
	}

	return numero;
}


int pedirEntero(char mensaje[]){

	int numero;

	printf("%s",mensaje);
	scanf("%d",&numero);

	return numero;

}


float pedirFloat(char mensaje[]){

	float numero;

	printf("%s",mensaje);
	scanf("%f",&numero);

	return numero;

}


/************************************************************************************************************/
/************************************************VALIDACIONES************************************************/
/************************************************************************************************************/

int comprobarIndexOcupado(eProductos lista[], int lenghtArray ,int numero){
	int i;
	int retorno;

	retorno = VACIO;

	for(i=0;i<lenghtArray;i++){
		if(lista[i].idProducto == numero && lista[i].isEmpty == OCUPADO){
			retorno = i;
			break;
		}
	}
	return retorno;
}


int comprobarEspaciosVaciosEstructura(eProductos lista[], int lenghtArray){
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


int comprobarEspaciosOcupadosEstructura(eProductos lista[], int lenghtArray){
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

int validarExisteNacionalidad(eNacionalidad lista[], int lenghtArray, int id){
	int i;
	int retorno;

	retorno = -1;

	for(i=0;i<lenghtArray;i++){
		if(lista[i].idNacionalidad==id){
			retorno=1;
			break;
		}
	}
	return retorno;
}

int validarExisteTipoProducto(eTipoProducto lista[], int lenghtArray, int id){
	int i;
	int retorno;

	retorno = -1;

	for(i=0;i<lenghtArray;i++){
		if(lista[i].idTipo==id){
			retorno=1;
			break;
		}
	}
	return retorno;
}

