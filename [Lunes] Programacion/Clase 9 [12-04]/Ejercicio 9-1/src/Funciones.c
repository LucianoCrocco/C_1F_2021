/*
 * Funciones.c
 *
 *  Created on: 12 abr. 2021
 *      Author: luciano
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"


void hardocodearElementos(eProductos lista[]){
	int i;
	int idProducto[3]={1100, 1000, 1200};
	char descripcion[3][STRING_LENGHT]={"Cargador", "Computadora", "Tablet"};
	int nacionalidad[3]={2, 2, 1};
	int tipo[3]={4, 2, 3};
	float precio[3]={100, 1250.40, 300};
	int isEmpty[3]= {OCUPADO, OCUPADO, OCUPADO};

	for(i=0;i<3;i++){
		lista[i].idProducto=idProducto[i];
		strcpy(lista[i].descripcion,descripcion[i]);
		lista[i].nacionalidad=nacionalidad[i];
		lista[i].tipo=tipo[i];
		lista[i].precio=precio[i];
		lista[i].isEmpty=isEmpty[i];
	}

}

int pedirEnteroConRango(char mensaje[], char mensajeError[], int minimo, int maximo){
	int numero;

	printf("%s",mensaje);
	scanf("%d",&numero);
	while((numero < minimo || numero > maximo)){
		printf("\n%s\n\n",mensajeError);
		printf("%s",mensaje);
		scanf("%d",&numero);
	}

	return numero;

}

int pedirEntero(char mensaje[], char mensajeError[]){

	int numero;

	printf("%s",mensaje);
	scanf("%d",&numero);

	return numero;

}

float pedirFloat(char mensaje[], char mensajeError[]){

	float numero;

	printf("%s",mensaje);
	scanf("%f",&numero);

	return numero;

}

void mostrarListadoEstructura(eProductos lista[], int lenghtArray){
	int i;
	printf("\n");
	for(i=0;i<lenghtArray;i++){
		if(lista[i].isEmpty == OCUPADO){
			mostrarUnElementoEstrucutra(lista[i]);
		}
	}
}

void mostrarUnElementoEstrucutra(eProductos unProducto){
	printf("Id del producto: %d\n", unProducto.idProducto);
	printf("Descripcion: %s\n", unProducto.descripcion);
	printf("Nacionalidad(1-> USA --- 2-> CHINA --- 3-> OTRO): %d\n", unProducto.nacionalidad);
	printf("Tipo (1-> IPHONE --- 2-> MAC --- 3-> IPAD --- 4-> ACCESORIOS): %d\n", unProducto.tipo);
	printf("Precio: %.2f\n\n", unProducto.precio);
}

void inicializarIsEmptyEstructura(eProductos lista[], int lenghtArray){
    int i;
    for(i=0;i<lenghtArray;i++){
    	lista[i].isEmpty = VACIO;
    }
}

int comprobarEspaciosVaciosEstructura(eProductos lista[], int lenghtArray){
    int i;
    int valorARetornar;
    valorARetornar = -1;
    for(i=0;i<lenghtArray;i++){
        if(lista[i].isEmpty==VACIO){
			valorARetornar = i;
			break;
        }
    }
    return valorARetornar;
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

void altaLogicaListaEstrucutra(eProductos lista[], int lenghtArray){
	int posicion;

	posicion = comprobarEspaciosVaciosEstructura(lista, lenghtArray);
	if(posicion != -1){
		lista[posicion].idProducto=pedirEntero("Ingrese el ID del producto: ", "Error, ingrese un id valido");

		printf("Ingrese la descripcion: ");
		__fpurge(stdin);
		scanf("%[^\n]",lista[posicion].descripcion);

		lista[posicion].nacionalidad=pedirEnteroConRango("Ingrese la nacionalidad del producto (1. USA -- 2.CHINA -- 3. OTRO): ", "Error, ingrese un id valido", 1, 3);

		lista[posicion].tipo=pedirEnteroConRango("Ingrese el tipo de producto (1. IPHONE -- 2. MAC -- 3. IPAD -- 4. ACCESORIOS): ", "Error, ingrese un id valido", 1, 4);

		lista[posicion].precio=pedirFloat("Ingrese el precio del producto: ", "Error... Ingrese un precio valido");

		lista[posicion].isEmpty=OCUPADO;
	}
}

void bajaLogicaListaEstrucutra(eProductos lista[], int lenghtArray){
	int posicion;
	int validacion;
	int i;

	posicion = pedirEntero("Ingrese el ID del producto a buscar: ", "Error... el ID no es valido");
	validacion = buscarIdEstrucutra(lista,lenghtArray,posicion);
	if(validacion == -1){
		printf("Error... el ID no es valido\n");
	} else {
		for(i=0;i<lenghtArray;i++){
			if(lista[i].idProducto == posicion && lista[i].isEmpty == OCUPADO){
				lista[i].isEmpty = VACIO;
				printf("\nProducto borrado\n");
				break;
			}
		}
	}

}

int buscarIdEstrucutra(eProductos lista[], int lenghtArray, int numero){
	int i;
	int validacion;

	validacion = -1;

	for(i=0;i<lenghtArray;i++){
		if(lista[i].idProducto == numero){
			validacion = i;
			break;
		}
	}
	return validacion;
}

void modificarEstructura(eProductos lista[], int lenghtArray){
	int id;
	int posicion;
	int auxiliar;
	float aux;

	printf("Ingrese el ID del producto a buscar: ");
	scanf("%d",&id);
	posicion = buscarIdEstrucutra(lista, lenghtArray, id);
	if(posicion != -1){
		printf("\n\n---Se encontro el ID a buscar---\n\n");
		auxiliar=pedirEnteroConRango("Que desea modificar?\n1. Precio\n2. Tipo: ", "Error, ingrese un numero valido", 1, 2);
		switch(auxiliar){
			case 1:
				aux=pedirFloat("Ingrese el nuevo precio del producto: ", "Error... Ingrese un numero valido");
				lista[posicion].precio=aux;
				break;
			case 2:
				auxiliar=pedirEnteroConRango("Ingrese el tipo de producto (1. IPHONE -- 2. MAC -- 3. IPAD -- 4. ACCESORIOS): ", "Error, ingrese un id valido", 1, 4);
				lista[posicion].tipo=auxiliar;
				break;
		}
	} else {
		printf("\n---El ID ingresado es invalido---\n\n");
	}

}
//			NO FUNCIONA, REVISAR
void insertionSortNumbPrecio(eProductos lista[], int lenghtArray){
	int i;
	int j;
	eProductos aux;


	for(i=1;i<lenghtArray;i++){
		aux = lista[i];
		j=i-1;
		while(j>=0 && aux.precio < lista[j].precio){
			lista[j+1] = lista[j];
			j--;
		}
		lista[j+1]= aux; //insercion
	}
}


void simpleBubbleSortNumbsPrecio(eProductos lista[], int lenghtArray){
	int i;
	int j;
	eProductos auxiliar;

	for(i=0;i<lenghtArray-1;i++){
		for(j=i+1;j<lenghtArray;j++){
			if(lista[i].precio > lista[j].precio){
				auxiliar = lista[i];
				lista[i] = lista[j];
				lista[j] = auxiliar;
			}
		}
	}
}

void insertionSortNumbDescripcion(eProductos lista[], int lenghtArray){
	int i;
	int j;
	eProductos aux;


	for(i=1;i<lenghtArray;i++){
		aux = lista[i];
		j=i-1;
		while(j>=0 && strcmp(aux.descripcion,lista[j].descripcion) < 0){
			lista[j+1] = lista[j];
			j--;
		}
		lista[j+1]= aux; //insercion
	}
}

int buscarElMaximo(eProductos lista[], int lenghtArray){
	int i;
	float maximo;
	int retorno;

	for(i=0;i<lenghtArray;i++){
		if(i==0){
			maximo = lista[i].precio;
			retorno = i;
		} else {
			if(maximo < lista[i].precio){
				maximo = lista[i].precio;
				retorno = i;
			}
		}
	}
	return retorno;
}

void printMaximos(eProductos lista[], int lenghtArray){
	int posicion;
	posicion = buscarElMaximo(lista, lenghtArray);

	printf("\n\n----El elemento de mayor precio ----\n\n");
	mostrarUnElementoEstrucutra(lista[posicion]);
}

float precioPromedioPorTipo(eProductos lista[], int lenghtArray, int tipo){
	int i;
	int coincidencias;
	float acumulador;
	float promedio;

	coincidencias=0;
	acumulador = 0;
	promedio = -1;

	for(i=0;i<lenghtArray;i++){
		if(lista[i].isEmpty == OCUPADO){
			if(lista[i].tipo==tipo){
				coincidencias++;
				acumulador += lista[i].precio;
			}
		}
	}
	if(coincidencias != 0){
		promedio = acumulador / coincidencias;
	}

	return promedio;

}

void printPromediosPorTipo(eProductos lista[], int lenghtArray){
	float precioIphone;
	float precioMac;
	float precioIpad;
	float precioAccesorios;

	precioIphone=precioPromedioPorTipo(lista,lenghtArray,1);
	precioMac=precioPromedioPorTipo(lista,lenghtArray,2);
	precioIpad=precioPromedioPorTipo(lista,lenghtArray,3);
	precioAccesorios=precioPromedioPorTipo(lista,lenghtArray,4);

	if(precioIphone != -1){
		printf("\nEl precio promedio de los Iphone es de: %.2f\n", precioIphone);
	} else {
		printf("\nNo se compraron Iphone's\n");
	}

	if(precioMac != -1){
		printf("\nEl precio promedio de las Mac es de: %.2f\n", precioMac);
	} else {
		printf("\nNo se compraron Mac's\n");
	}

	if(precioIpad != -1){
		printf("\nEl precio promedio de los Ipad's es de: %.2f\n", precioIpad);
	} else {
		printf("\nNo se compraron Ipad's\n");
	}

	if(precioAccesorios != -1){
		printf("\nEl precio promedio de los Accesorios es de: %.2f\n", precioAccesorios);
	} else {
		printf("\nNo se compraron Accesorios\n");
	}
}


