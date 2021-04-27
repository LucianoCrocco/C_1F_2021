/*
 * Estructuras.c
 *
 *  Created on: 24 abr. 2021
 *      Author: luciano
 */


/************************************************HARDCODEOS*************************************************/

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Estructuras.h"
#include "Utilidades.h"


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


void inicializarIsEmptyTipoProductos(eTipoProducto lista[], int lenghtArray){
	int i;
	for(i=0;i<lenghtArray;i++){
		lista[i].isEmpty = VACIO;
	}
}

void inicializarIsEmptyNacionalidades(eNacionalidad lista[], int lenghtArray){
	int i;
	for(i=0;i<lenghtArray;i++){
		lista[i].isEmpty = VACIO;
	}
}



/*******************************************ALTA-BAJA-MODIFICACION**********************************************/

//								CASE 1

void altaListaEstructura(eProductos lista[], int lenghtArray, eTipoProducto lista2[], int lenghtArray2, eNacionalidad lista3[], int lenghtArray3){
	int index;

	index = comprobarEspaciosVaciosEstructura(lista, lenghtArray);
	if(index != -1){
		cargarDatosEstructura(lista, index, lista2, lenghtArray2, lista3, lenghtArray3);
	} else {
		printf("\nNo hay espacios disponibles en la memoria\n");
	}
}


void cargarDatosEstructura(eProductos lista[], int index, eTipoProducto lista2[], int lenghtArray2, eNacionalidad lista3[], int lenghtArray3){
	int validacion;

	mostrarListadoTipoProducto(lista2, lenghtArray2);
	lista[index].idTipo = pedirEntero("Ingrese el ID del tipo de producto desea dar de alta: ");
	validacion=validarExisteTipoProducto(lista2,lenghtArray2,lista[index].idTipo);
	while(validacion == -1){
		printf("\nError... El ID ingresado es inexistente, ingrese uno valido\n");
		lista[index].idTipo = pedirEntero("Ingrese el ID del tipo de producto desea dar de alta: ");
		validacion=validarExisteTipoProducto(lista2,lenghtArray2,lista[index].idTipo);
	}


	lista[index].idProducto=pedirEntero("Ingrese el ID del producto: ");
	validacion = comprobarIndexOcupado(lista, index, lista[index].idProducto);
	while(validacion != VACIO){
		printf("\nError... El ID ingresado ya fue asigando a otro producto, ingrese uno nuevamente\n");
		lista[index].idProducto=pedirEntero("Ingrese el ID del producto: ");
		validacion = comprobarIndexOcupado(lista, index, lista[index].idProducto);
	}

	printf("Ingrese la descripcion del producto: ");
	__fpurge(stdin);
	scanf("%[^\n]",lista[index].descripcion);

	mostrarListadoNacionalidad(lista3, lenghtArray3);
	lista[index].idNacionalidad=pedirEntero("Ingrese el ID de la nacionalidad: ");
	validacion=validarExisteNacionalidad(lista3,lenghtArray3,lista[index].idNacionalidad);
	while(validacion == -1){
		printf("\nError... El ID ingresado es inexistente, ingrese uno valido\n");
		lista[index].idNacionalidad=pedirEntero("Ingrese el ID de la nacionalidad: ");
		validacion=validarExisteNacionalidad(lista3,lenghtArray3,lista[index].idNacionalidad);
	}


	lista[index].isEmpty=OCUPADO;

	lista[index].precio = pedirFloat("Ingrese el precio del producto: ");



}

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


//								CASE 2
void bajaListaEstructura(eProductos lista[], int lenghtArray){
	int datoAComparar;
	int index;

	datoAComparar = pedirEntero("Ingrese el id del producto a dar de baja: ");

	index = comprobarIndexOcupado(lista,lenghtArray,datoAComparar);
	if(index == VACIO){
		printf("\nError... el ID del producto ingresado no es valido\n");
	} else {
		lista[index].isEmpty = VACIO;
		printf("\nProducto borrado\n");
	}

}

//								CASE 3

void modificarProductos(eProductos lista[], int lenghtArray, eTipoProducto lista2[], int lenghtArray2, eNacionalidad lista3[], int lenghtArray3){

	int datoABuscar;
	int index;

	datoABuscar = pedirEntero("\nIngrese el ID del producto para modificar los datos: ");

	index = comprobarIndexOcupado(lista,lenghtArray,datoABuscar);
	if(index == VACIO){
		printf("\nError... el dato comparado ingresado no es valido\n");
	} else {
		modificarDatosProductos(lista, index, lista2, lenghtArray2, lista3, lenghtArray3);
	}
}

void modificarDatosProductos(eProductos lista[], int index, eTipoProducto lista2[], int lenghtArray2, eNacionalidad lista3[], int lenghtArray3){
	int opciones;
	int flagModifico;

	flagModifico = 0;

	do {
		saltoDeLinea(1);
		opciones = pedirEnteroConRango("1. Cambiar Descripcion \n2. Cambiar Nacionalidad\n3. Cambiar Tipo\n4. Cambiar Precio\n5. Salir\nIngrese una opcion: ", "Error... Ingrese una opcion valida", 1, 5);
		switch(opciones){
			case 1:
				printf("Ingrese la nueva descripcion del producto: ");
				__fpurge(stdin);
				scanf("%[^\n]",lista[index].descripcion);
				flagModifico++;
				break;
			case 2:
				lista[index].idNacionalidad=pedirEnteroConRango("---Paises Disponibles---\n1. EEUU\n2. CHINA\n3. OTRO\nIngrese una opcion: ", "Error... Ingrese una opcion valida", 1, 3);
				flagModifico++;
				break;
			case 3:
				mostrarListadoTipoProducto(lista2, lenghtArray2);
				lista[index].idTipo = pedirEnteroConRango("Ingrese que tipo de producto desea dar de alta: ", "Error... Ingrese una opcion valida", 1000, 1003);
				flagModifico++;
				break;
			case 4:
				lista[index].precio = pedirFloat("Ingrese el nuevo precio del producto: ");
				flagModifico++;
				break;
		}
	}while(opciones != 5);

	if(flagModifico==0){
		printf("\nNo se modificaron datos.\n");
	} else {
		printf("\nDatos modificados correctamente.\n");
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

//								CASE 8

void printPromediosPorTipo(eProductos lista[], int lenghtArray, eTipoProducto lista2[], int lenghtArray2){
	int i;

	for(i=0;i<lenghtArray2;i++){
		if(lista2[i].isEmpty == OCUPADO){
			mostrarUnElementoTipoProducto(lista2[i]);
			printUnPromedioTipoProducto(lista,lenghtArray, lista2, lenghtArray2, lista2[i].idTipo);
		}
	}
}

void printUnPromedioTipoProducto(eProductos lista[], int lenghtArray, eTipoProducto lista2[], int lenghtArray2, int tipo){

	float promedio;

	promedio=precioPromedioPorTipo(lista,lenghtArray,tipo);

	if(promedio != -1){
		printf("El promedio es: %.2f\n\n", promedio);
	} else {
		printf("No se ingresaron datos de este tipo \n\n");
	}
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
		if(lista[i].isEmpty == OCUPADO && lista[i].idTipo==tipo){
			coincidencias++;
			acumulador += lista[i].precio;
		}
	}
	if(coincidencias != 0){
		promedio = acumulador / coincidencias;
	}

	return promedio;

}

//								CASE 9

void mostrarListadoProductosConDescTipo(eProductos lista[], int lenghtArray, eTipoProducto listaTipo[], int lenghtTipo){
	int i;
	for(i=0;i<lenghtArray;i++){
		buscarListadoProductosConDescTipo(lista[i], listaTipo, lenghtTipo);
	}
}

void buscarListadoProductosConDescTipo(eProductos lista, eTipoProducto listaTipo[], int lenghtTipo){
	int i;

	for(i=0;i<lenghtTipo;i++){
		if(lista.idTipo==listaTipo[i].idTipo && (lista.isEmpty == OCUPADO && listaTipo[i].isEmpty == OCUPADO)){
			mostrarUnElementoTipoProducto(listaTipo[i]);
			mostrarUnElementoProductos(lista);
		}
	}
}

//								CASE 10

void mostrarListadoTipoProductoYProducto(eProductos lista[], int lenghtArray, eTipoProducto listaTipo[], int lenghtTipo){
	int i;
	int validacion;
	for(i=0;i<lenghtTipo;i++){
		if(listaTipo[i].isEmpty==OCUPADO){
			mostrarUnElementoTipoProducto(listaTipo[i]);
			saltoDeLinea(1);
			validacion = mostrarUnElementoTipoProductoYProducto(lista,lenghtArray,listaTipo[i]);
			if(validacion == -1){
				printf("\t---No hay elementos de este tipo---\n\n");
			}
		}
	}
}

int mostrarUnElementoTipoProductoYProducto(eProductos lista[], int lenghtArray, eTipoProducto unElemento){
	int i;
	int encontro;

	encontro = -1;

	for(i=0;i<lenghtArray;i++){
		if(unElemento.idTipo == lista[i].idTipo && lista[i].isEmpty == OCUPADO){
			mostrarUnElementoProductos(lista[i]);
			encontro = 1;
		}
	}
	return encontro;
}


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


//								CASE 11

void calcularTiposConMasProductos(eProductos lista[], int lenghtArray, eTipoProducto listaTipo[], int lenghtTipo){
	eAuxiliar auxiliar[lenghtTipo];
	int contador;

	inicializarAuxiliarComoTipo(listaTipo,auxiliar,lenghtTipo);
	contadorDeMaximosTipoProducto(lista, lenghtArray, auxiliar, lenghtTipo);
	contador=calcularMaximoTipoProducto(auxiliar,lenghtTipo);
	printMasTipoProductos(auxiliar,listaTipo,lenghtTipo,contador);

}

void inicializarAuxiliarComoTipo(eTipoProducto listaTipo[], eAuxiliar listaAuxiliar[], int lenghtTipo){
	int i;

	for(i=0;i<lenghtTipo;i++){
		listaAuxiliar[i].id=listaTipo[i].idTipo;
		listaAuxiliar[i].contador=0;
		listaAuxiliar[i].isEmpty=listaTipo[i].isEmpty;
	}
}

void contadorDeMaximosTipoProducto(eProductos lista[], int lenghtArray, eAuxiliar listaAuxiliar[], int lenghtTipo){
	int i;
	int j;

	for(i=0;i<lenghtTipo;i++){
		if(listaAuxiliar[i].isEmpty == OCUPADO){
			for(j=0;j<lenghtArray;j++){
				if(lista[j].isEmpty == OCUPADO && listaAuxiliar[i].id==lista[j].idTipo){
					listaAuxiliar[i].contador++;
				}
			}
		}
	}
}

int calcularMaximoTipoProducto(eAuxiliar listaAuxiliar[], int lenghtTipo){

	int i;
	int flag;
	int j;
	int contadorMaximo;

	flag = 0;
	contadorMaximo = 0;

	for(i=0;i<lenghtTipo;i++){
		if(listaAuxiliar[i].isEmpty==OCUPADO && flag == 0){
			j = i;
			contadorMaximo = listaAuxiliar[j].contador;
			flag++;
		} else {
			if(listaAuxiliar[j].contador < listaAuxiliar[i].contador){
				j = i;
				contadorMaximo = listaAuxiliar[j].contador;
			}
		}
	}
	return contadorMaximo;
}


void printMasTipoProductos(eAuxiliar lista[], eTipoProducto listaTipo[], int lenghtArray, int maximo){
	int i;
	int j;

	for(i=0;i<lenghtArray;i++){
		if(lista[i].isEmpty==OCUPADO){
			for(j=0;j<lenghtArray;j++){
				if(lista[i].id == listaTipo[j].idTipo && lista[i].contador == maximo){
					mostrarUnElementoTipoProducto(listaTipo[j]);
				}
			}
		}
	}
}
