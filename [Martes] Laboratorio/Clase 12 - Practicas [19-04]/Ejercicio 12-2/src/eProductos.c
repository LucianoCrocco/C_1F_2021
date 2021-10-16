/*
 * eProductos.c
 *
 *  Created on: 2 may. 2021
 *      Author: luciano
 */


#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Utilidades.h"
#include "eProductos.h"


/************************************************************************************************************/
/************************************************VALIDACIONES************************************************/
/************************************************************************************************************/


int comprobarIndexOcupado(eProductos lista[], int lenghtArray ,int numero){
	int i;
	int retorno;

	retorno = -1;

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


/************************************************************************************************************/
/*************************************************HARDCODEOS*************************************************/
/************************************************************************************************************/


void hardocodearDatosUnaStructProductos(eProductos lista[]){
	int i;

	//podria agregar una variable cantidad para no poner 3 siempre.

	int idProducto[3]={1100, 1000, 1200};
	char descripcion[3][STRING_LENGHT]={"Cargador", "Computadora", "Tablet"};
	int nacionalidad[3]={1, 2, 3};
	int tipo[3]={1003, 1002, 1001};
	float precio[3]={100, 1250.40, 300};
	int isEmpty[3]= {OCUPADO, OCUPADO, OCUPADO};


	for(i=0;i<3;i++){
		lista[i].idProducto=idProducto[i];
		strcpy(lista[i].descripcion,descripcion[i]);
		lista[i].idNacionalidad=nacionalidad[i];
		lista[i].idTipo=tipo[i];
		lista[i].precio=precio[i];
		lista[i].isEmpty=isEmpty[i];
	}

}


void inicializarIsEmptyProductos(eProductos lista[], int lenghtArray){
    int i;
    for(i=0;i<lenghtArray;i++){
    	lista[i].isEmpty = VACIO;
    }
}

/************************************************************************************************************/
/****************************************************A.B.M***************************************************/
/************************************************************************************************************/

//								CASE 2
void bajaListaEstructura(eProductos lista[], int lenghtArray){
	int datoAComparar;
	int index;

	datoAComparar = pedirEntero("Ingrese el id del producto a dar de baja: ");

	index = comprobarIndexOcupado(lista,lenghtArray,datoAComparar);
	if(index == -1){
		printf("\nError... el ID del producto ingresado no es valido\n");
	} else {
		lista[index].isEmpty = VACIO;
		printf("\nProducto borrado\n");
	}

}


//								CASE 4 Y 9
void mostrarListadoProductos(eProductos lista[], int lenghtArray){
	int i;
	for(i=0;i<lenghtArray;i++){
		if(lista[i].isEmpty == OCUPADO){
			mostrarUnElementoProductos(lista[i]);
		}
	}
}

void mostrarUnElementoProductos(eProductos unProducto){

	printf("ID del producto: %d\n", unProducto.idProducto);
	printf("Descripcion: %s\n", unProducto.descripcion);
	printf("ID Nacionalidad: %d\n", unProducto.idNacionalidad);
	printf("ID Tipo: %d\n", unProducto.idTipo);
	printf("Precio: %.2f\n\n", unProducto.precio);
}


//								CASE 5
void insertionSortNumbPrecio(eProductos lista[], int lenghtArray){
	int i;
	int j;
	eProductos aux;


	for(i=1;i<lenghtArray;i++){
		if(lista[i].isEmpty == OCUPADO){
			aux = lista[i];
			j=i-1;
			while(j>=0 && aux.precio < lista[j].precio){
				lista[j+1] = lista[j];
				j--;
			}
			lista[j+1]= aux; //insercion
		}
	}
}

//								CASE 6
void insertionSortNumbDescripcion(eProductos lista[], int lenghtArray){
	int i;
	int j;
	eProductos aux;


	for(i=1;i<lenghtArray;i++){
		if(lista[i].isEmpty == OCUPADO){
			aux = lista[i];
			j=i-1;
			while(j>=0 && strcmp(aux.descripcion,lista[j].descripcion) < 0){
				lista[j+1] = lista[j];
				j--;
			}
			lista[j+1]= aux; //insercion
		}
	}
}


//								CASE 7
void productosMasCaros(eProductos lista[], int lenghtArray){

	eProductos auxiliar[lenghtArray];

	inicializarIsEmptyProductos(auxiliar,lenghtArray);

	int i;
	int flag;
	int j;

	j=0;
	flag = 0;


	for(i=0;i<lenghtArray;i++){
		if(lista[i].isEmpty == OCUPADO && flag == 0){
			auxiliar[0]=lista[i];
			flag++;
		} else {
			if(auxiliar[j].precio == lista[i].precio && lista[i].isEmpty == OCUPADO){
				j++;
				auxiliar[j]=lista[i];
			} else {
				if(auxiliar[j].precio < lista[i].precio && lista[i].isEmpty == OCUPADO){
					inicializarIsEmptyProductos(auxiliar,lenghtArray);
					auxiliar[0]=lista[i];
					j=0;
				}
			}
		}
	}

	printProductosMasCaros(auxiliar,lenghtArray);
}

void printProductosMasCaros(eProductos lista[], int lenghtArray){
	int i;

	for(i=0;i<lenghtArray;i++){
		if(lista[i].isEmpty==OCUPADO){
			mostrarUnElementoProductos(lista[i]);
		}
	}
}


