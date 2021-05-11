/*
 * nexoEstructuras.c
 *
 *  Created on: 4 may. 2021
 *      Author: luciano
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include "Utilidades.h"
#include "eTrabajo.h"
#include "eServicio.h"
#include "nexoEstructuras.h"

int generar_ID(int indexGenerado, int numeroInicializador){
	int idRetornado;

	idRetornado=indexGenerado+numeroInicializador;

	return idRetornado;

}

void altaEstructuraTrabajo(eTrabajo listaTrabajos[], int lenghtTrabajos, eServicio listaServicios[], int lenghtServicios){
	int index;

	index=comprobarEspaciosVaciosEstructuraTrabajo(listaTrabajos, lenghtTrabajos);

	if(index != -1){
		cargarDatosTrabajos(listaTrabajos, lenghtTrabajos, index, listaServicios, lenghtServicios);
		puts("\Trabajo cargado correctamente.");
	} else {
		puts("\nNo hay espacios disponibles para cargar trabajos");
	}
}

void cargarDatosTrabajos(eTrabajo listaTrabajos[], int lenghtTrabajos, int index, eServicio listaServicios[], int lenghtServicios){
	int validacion;

	mostrarListadoServicios(listaServicios, lenghtServicios);
	listaTrabajos[index].idServicio = pedirEntero("Ingrese el ID del servicio que desea realizar: ");
	validacion = comprobarIndexOcupadoServicios(listaServicios,lenghtServicios, listaTrabajos[index].idServicio);
	while(validacion == -1){
		listaTrabajos[index].idServicio = pedirEntero("Error...Ingrese en ID valido\nIngrese el ID del servicio que desea realizar: ");
		validacion = comprobarIndexOcupadoServicios(listaServicios,lenghtServicios, listaTrabajos[index].idServicio);
	}


	listaTrabajos[index].id=generar_ID(index, 1);


	printf("Ingrese la marca de la bicicleta: ");
	__fpurge(stdin);
	scanf("%[^\n]",listaTrabajos[index].marcaBicicleta);

	listaTrabajos[index].rodadoBicicleta=pedirEntero("Ingrese el rodado de la bicicleta: ");

	listaTrabajos[index].fecha=pedirFecha(listaTrabajos[index]);

	listaTrabajos[index].isEmpty = OCUPADO;
}



//PARTE 2

void modificarTrabajos(eTrabajo listaTrabajos[], int lenghtTrabajos, eServicio listaServicios[], int lenghtServicios){

	int datoABuscar;
	int index;

	datoABuscar = pedirEntero("\nIngrese el ID del producto para modificar los datos: ");

	index = comprobarIndexOcupadoTrabajo(listaTrabajos,lenghtTrabajos,datoABuscar);
	if(index == -1){
		printf("\nError... el dato comparado ingresado no es valido/no existe\n");
	} else {
		modificarDatosTrabajos(listaTrabajos, index, lenghtTrabajos, listaServicios, lenghtServicios);
	}
}

void modificarDatosTrabajos(eTrabajo listaTrabajos[], int index,int lenghtTrabajos, eServicio listaServicios[], int lenghtServicios){
	int opciones;
	int flagModifico;
	int validacion;

	flagModifico = 0;

	do {
		saltoDeLinea(1);
		opciones = pedirEnteroConRango("1. Cambiar Marca de la Bicicleta \n2. Cambiar el Servicio\n3. Salir\nIngrese una opcion: ", "Error... Ingrese una opcion valida", 1, 3);
		switch(opciones){
			case 1:
				printf("Ingrese la nueva marca de la bicileta: ");
				__fpurge(stdin);
				scanf("%[^\n]",listaTrabajos[index].marcaBicicleta);
				flagModifico++;
				break;
			case 2:
				mostrarListadoServicios(listaServicios, lenghtServicios);
				listaTrabajos[index].idServicio=pedirEntero("Ingrese el ID del Servicio: ");
				validacion=comprobarIndexOcupadoServicios(listaServicios,lenghtServicios,listaTrabajos[index].idServicio);
				while(validacion == -1){
					listaTrabajos[index].idServicio=pedirEntero("Error... El ID ingresado es inexistente, ingrese uno valido\nIngrese el ID del Servicio: ");
					validacion=comprobarIndexOcupadoServicios(listaServicios,lenghtServicios,listaTrabajos[index].idServicio);
				}
				flagModifico++;
				break;
		}
	}while(opciones != 3);

	if(flagModifico==0){
		printf("\nNo se modificaron datos.\n");
	} else {
		printf("\nDatos modificados correctamente.\n");
	}
}

void printTotalEnPesosTrabajos(eTrabajo listaTrabajos[], int lenghtTrabajos, eServicio listaServicios[], int lenghtServicios){
	float total;

	total = calcularTotalEnPesosTrabajos(listaTrabajos, lenghtTrabajos, listaServicios, lenghtServicios);

	printf("\nEl total en pesos por los servicios realizados es: %f", total);

}

float calcularTotalEnPesosTrabajos(eTrabajo listaTrabajos[], int lenghtTrabajos, eServicio listaServicios[], int lenghtServicios){
	int i;
	int j;

	float acumuladorPrecio;

	acumuladorPrecio=0;

	for(i=0;i<lenghtServicios;i++){
		if(listaServicios[i].isEmpty==OCUPADO){
			for(j=0;j<lenghtServicios;j++){
				if(listaTrabajos[j].isEmpty == OCUPADO){
					if(listaTrabajos[j].idServicio == listaServicios[i].id){
						acumuladorPrecio+=listaServicios[j].precio;
					}
				}
			}
		}
	}
	return acumuladorPrecio;
}
