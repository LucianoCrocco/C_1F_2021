/*
 * nexoEstructuras.c
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
#include "eTipoProducto.h"
#include "eProductos.h"
#include "nexoEstructuras.h"

/*******************************************ALTA-BAJA-MODIFICACION**********************************************/

//								CASE 1
void altaListaEstructura(eProductos lista[], int lenghtArray, eTipoProducto lista2[], int lenghtArray2, eNacionalidad lista3[], int lenghtArray3){
	int index;

	index = comprobarEspaciosVaciosEstructura(lista, lenghtArray);
	if(index != -1){
		cargarDatosEstructura(lista, lenghtArray, index, lista2, lenghtArray2, lista3, lenghtArray3);
	} else {
		printf("\nNo hay espacios disponibles en la memoria\n");
	}
}


void cargarDatosEstructura(eProductos lista[], int lenghtArray, int index, eTipoProducto lista2[], int lenghtArray2, eNacionalidad lista3[], int lenghtArray3){
	int validacion;

	mostrarListadoTipoProducto(lista2, lenghtArray2);
	lista[index].idTipo = pedirEntero("Ingrese el ID del tipo de producto desea dar de alta: ");
	validacion=comprobarIndexOcupadoTipo(lista2,lenghtArray2,lista[index].idTipo);
	while(validacion == -1){
		lista[index].idTipo = pedirEntero("Error... El ID ingresado es inexistente, ingrese uno valido\nIngrese el ID del tipo de producto desea dar de alta: ");
		validacion=comprobarIndexOcupadoTipo(lista2,lenghtArray2,lista[index].idTipo);
	}


	lista[index].idProducto=pedirEnteroConRango("Ingrese el ID del producto: ", "Ingrese un ID mayor a 1 y menor a 10.000", 1, 10000);
	validacion = comprobarIndexOcupado(lista, lenghtArray, lista[index].idProducto);
	while(validacion != -1){
		lista[index].idProducto=pedirEntero("Error... El ID ingresado ya fue asigando a otro producto, ingrese uno nuevamente\nIngrese el ID del producto: ");
		validacion = comprobarIndexOcupado(lista, index, lista[index].idProducto);
	}

	printf("Ingrese la descripcion del producto: ");
	__fpurge(stdin);
	scanf("%[^\n]",lista[index].descripcion);

	mostrarListadoNacionalidad(lista3, lenghtArray3);
	lista[index].idNacionalidad=pedirEntero("Ingrese el ID de la nacionalidad: ");
	validacion=comprobarIndexOcupadoNacionalidad(lista3,lenghtArray3,lista[index].idNacionalidad);
	while(validacion == -1){
		lista[index].idNacionalidad=pedirEntero("Error... El ID ingresado es inexistente, ingrese uno valido\nIngrese el ID de la nacionalidad: ");
		validacion=comprobarIndexOcupadoNacionalidad(lista3,lenghtArray3,lista[index].idNacionalidad);
	}


	lista[index].isEmpty=OCUPADO;

	lista[index].precio = pedirFloat("Ingrese el precio del producto: ");

}


//								CASE 3

void modificarProductos(eProductos lista[], int lenghtArray, eTipoProducto lista2[], int lenghtArray2, eNacionalidad lista3[], int lenghtArray3){

	int datoABuscar;
	int index;

	datoABuscar = pedirEntero("\nIngrese el ID del producto para modificar los datos: ");

	index = comprobarIndexOcupado(lista,lenghtArray,datoABuscar);
	if(index == -1){
		printf("\nError... el dato comparado ingresado no es valido/no existe\n");
	} else {
		modificarDatosProductos(lista, index, lista2, lenghtArray2, lista3, lenghtArray3);
	}
}

void modificarDatosProductos(eProductos lista[], int index, eTipoProducto lista2[], int lenghtArray2, eNacionalidad lista3[], int lenghtArray3){
	int opciones;
	int flagModifico;
	int validacion;

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
				mostrarListadoNacionalidad(lista3, lenghtArray3);
				lista[index].idNacionalidad=pedirEntero("Ingrese el ID de la nacionalidad: ");
				validacion=comprobarIndexOcupadoNacionalidad(lista3,lenghtArray3,lista[index].idNacionalidad);
				while(validacion == -1){
					lista[index].idNacionalidad=pedirEntero("Error... El ID ingresado es inexistente, ingrese uno valido\nIngrese el ID de la nacionalidad: ");
					validacion=comprobarIndexOcupadoNacionalidad(lista3,lenghtArray3,lista[index].idNacionalidad);
				}
				flagModifico++;
				break;
			case 3:
				mostrarListadoTipoProducto(lista2, lenghtArray2);
				lista[index].idTipo = pedirEntero("Ingrese el ID del tipo de producto desea dar de alta: ");
				validacion=comprobarIndexOcupadoTipo(lista2,lenghtArray2,lista[index].idTipo);
				while(validacion == -1){
					lista[index].idTipo = pedirEntero("Error... El ID ingresado es inexistente, ingrese uno valido\nIngrese el ID del tipo de producto desea dar de alta: ");
					validacion=comprobarIndexOcupadoTipo(lista2,lenghtArray2,lista[index].idTipo);
				}
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
			saltoDeLinea(1);
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


//								CASE 11
void calcularTiposConMasProductos(eProductos lista[], int lenghtArray, eTipoProducto listaTipo[], int lenghtTipo){
	eAuxiliar auxiliar[lenghtTipo];
	int contador;

	inicializarAuxiliarComoTipo(listaTipo,auxiliar,lenghtTipo);
	contadorDeMaximosTipoProducto(lista, lenghtArray, auxiliar, lenghtTipo);
	contador=calcularMaximoTipoProducto(auxiliar,lenghtTipo);
	printMasTipoProductos(auxiliar,listaTipo,lenghtTipo,contador);

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
				if(lista[i].id == listaTipo[j].idTipo && lista[i].contador == maximo && listaTipo[j].isEmpty == OCUPADO){
					mostrarUnElementoTipoProducto(listaTipo[j]);
				}
			}
		}
	}
}


//								CASE 12
void calcularNacionalidadFabricaIphone(eProductos lista[], int lenghtArray, eTipoProducto listaTipo[], int lenghtTipo, eNacionalidad listaNacionalidad[], int lenghtNacionalidad){

	int idTipo;

	eAuxiliar auxiliar[lenghtNacionalidad];
	inicializarAuxiliarComoNacionalidad(listaNacionalidad, auxiliar, lenghtNacionalidad);
	idTipo=buscarIdTipoEspecifico("Iphone", listaTipo,lenghtTipo);
	contadorNacionalidadIphone(lista,lenghtArray,auxiliar,lenghtNacionalidad,idTipo);
	printNacionlidadSoloIphone(auxiliar, listaNacionalidad, lenghtNacionalidad);


}


void contadorNacionalidadIphone(eProductos lista[], int lenghtArray, eAuxiliar listaAuxiliar[], int lenghtNacionalidad, int idACompararTipo){

	int i;
	int j;

	for(i=0;i<lenghtNacionalidad;i++){
		if(listaAuxiliar[i].isEmpty == OCUPADO){
			for(j=0;j<lenghtArray;j++){
				if(lista[j].isEmpty == OCUPADO && lista[j].idNacionalidad == listaAuxiliar[i].id){
					if(!(lista[j].idTipo == idACompararTipo)){
						listaAuxiliar[i].contador=0;
						break;
					} else {
						if(lista[j].idTipo == idACompararTipo){
							listaAuxiliar[i].contador--;
						}
					}
				}
			}
		}
	}

}

void printNacionlidadSoloIphone(eAuxiliar lista[], eNacionalidad listaNacionalidad[], int lenghtNacionalidad){
	int i;
	int j;
	int flagPrint;

	flagPrint = 0;


	for(i=0;i<lenghtNacionalidad;i++){
		if(lista[i].isEmpty==OCUPADO){
			for(j=0;j<lenghtNacionalidad;j++){
				if(lista[i].id == listaNacionalidad[j].idNacionalidad && lista[i].contador != 0){
					mostrarUnElementoNacionalidad(listaNacionalidad[j]);
					flagPrint++;
				}
			}
		}
	}

	if(flagPrint==0){
		printf("\n-----No hay nacionalidades que solo fabriquen Iphone----\n");
	}
}

//								CASE 13
void printProductosOrdenadosPorNacionalidad(eProductos lista[], int lenghtArray, eNacionalidad listaNacion[], int lenghtNacion){
	int i;
	int j;

	for(i=0;i<lenghtNacion;i++){
		if(listaNacion[i].isEmpty == OCUPADO){
			mostrarUnElementoNacionalidad(listaNacion[i]);
			for(j=0;j<lenghtArray;j++){
				if(lista[j].isEmpty==OCUPADO){
					if(listaNacion[i].idNacionalidad == lista[j].idNacionalidad){
						mostrarUnElementoProductos(lista[j]);
					}
				}
			}
		}
	}
}


//								CASE 14

void calcularNacionConMasProductos(eProductos lista[], int lenghtArray,eNacionalidad listaNacion[], int lenghtNacion){
	eAuxiliar auxiliar[lenghtNacion];
	int contador;

	inicializarAuxiliarComoNacionalidad(listaNacion, auxiliar, lenghtNacion);
	contadorDeMaximosNacionProducto(lista, lenghtArray, auxiliar, lenghtNacion);
	contador=calcularMaximoNacionProducto(auxiliar,lenghtNacion);
	printMasNacionProductos(auxiliar, listaNacion, lenghtNacion, contador);
}

void contadorDeMaximosNacionProducto(eProductos lista[], int lenghtArray, eAuxiliar listaAuxiliar[], int lenghtNacion){
	int i;
	int j;

	for(i=0;i<lenghtNacion;i++){
		if(listaAuxiliar[i].isEmpty == OCUPADO){
			for(j=0;j<lenghtArray;j++){
				if(lista[j].isEmpty == OCUPADO && listaAuxiliar[i].id==lista[j].idNacionalidad){
					listaAuxiliar[i].contador++;
				}
			}
		}
	}
}

int calcularMaximoNacionProducto(eAuxiliar listaAuxiliar[], int lenghtNacion){

	int i;
	int flag;
	int j;
	int contadorMaximo;

	flag = 0;
	contadorMaximo = 0;

	for(i=0;i<lenghtNacion;i++){
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

void printMasNacionProductos(eAuxiliar lista[], eNacionalidad listaNacion[], int lenghtArray, int maximo){
	int i;
	int j;

	for(i=0;i<lenghtArray;i++){
		if(lista[i].isEmpty==OCUPADO){
			for(j=0;j<lenghtArray;j++){
				if(lista[i].id == listaNacion[j].idNacionalidad && lista[i].contador == maximo && listaNacion[j].isEmpty==OCUPADO){
					mostrarUnElementoNacionalidad(listaNacion[j]);
				}
			}
		}
	}
}


//								CASE 15
void printPromediosPorNacion(eProductos lista[], int lenghtArray, eNacionalidad lista2[], int lenghtArray2){
	int i;

	for(i=0;i<lenghtArray2;i++){
		if(lista2[i].isEmpty == OCUPADO){
			mostrarUnElementoNacionalidad(lista2[i]);
			printUnPromedioPorNacionalidad(lista,lenghtArray, lista2, lenghtArray2, lista2[i].idNacionalidad);
		}
	}
}

void printUnPromedioPorNacionalidad(eProductos lista[], int lenghtArray, eNacionalidad lista2[], int lenghtArray2, int nacionalidad){

	float promedio;

	promedio=precioPromedioPorNacionalidad(lista,lenghtArray,nacionalidad);

	if(promedio != -1){
		printf("El promedio es: %.2f\n\n", promedio);
	} else {
		printf("No se ingresaron datos de este tipo \n\n");
	}
}

float precioPromedioPorNacionalidad(eProductos lista[], int lenghtArray, int nacionalidad){
	int i;
	int coincidencias;
	float acumulador;
	float promedio;

	coincidencias=0;
	acumulador = 0;
	promedio = -1;

	for(i=0;i<lenghtArray;i++){
		if(lista[i].isEmpty == OCUPADO && lista[i].idNacionalidad==nacionalidad){
			coincidencias++;
			acumulador += lista[i].precio;
		}
	}
	if(coincidencias != 0){
		promedio = acumulador / coincidencias;
	}

	return promedio;

}

//						BAJA EN CASCADA TIPO
void cascadaProductosYTipo(eProductos lista[], int lenghtArray, int idTipoCascada){

	int i;

	for(i=0;i<lenghtArray;i++){
		if(lista[i].isEmpty == OCUPADO && lista[i].idTipo == idTipoCascada){
			lista[i].isEmpty = VACIO;
		}
	}
}

//						BAJA EN CASCADA NACIONALIDAD
void cascadaProductosYNacionalidad(eProductos lista[], int lenghtArray, int idNacionalidadCascada){
	int i;

	for(i=0;i<lenghtArray;i++){
		if(lista[i].isEmpty==OCUPADO && lista[i].idNacionalidad == idNacionalidadCascada){
			lista[i].isEmpty=VACIO;
		}
	}
}




