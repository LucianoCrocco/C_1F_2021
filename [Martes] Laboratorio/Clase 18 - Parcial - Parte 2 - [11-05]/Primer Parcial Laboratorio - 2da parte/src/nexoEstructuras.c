/*
 * nexoEstructuras.c
 *
 *  Created on: 4 may. 2021
 *      Author: luciano
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "Utilidades.h"
#include "eTrabajo.h"
#include "eServicio.h"
#include "eBicicleta.h"
#include "eAuxiliar.h"
#include "nexoEstructuras.h"


int generar_ID(int indexGenerado, int numeroInicializador){
	int idRetornado;

	idRetornado=indexGenerado+numeroInicializador;

	return idRetornado;

}

//PARTE 1
int altaDatosTrabajos(eTrabajo listaTrabajos[], int lenghtTrabajos, eServicio listaServicios[], int lenghtServicios, eBicicleta listaBicicletas[], int lenghtBicicletas){
	int validacion;
	int index;
	int rtn;

	rtn = 0;

	index=comprobarEspaciosVaciosEstructuraTrabajo(listaTrabajos, lenghtTrabajos);

	if(index != -1) {
		listaTrabajos[index].id=generar_ID(index, 1);

		mostrarListadoServicios(listaServicios, lenghtServicios);
		listaTrabajos[index].idServicio = pedirEntero("Ingrese el ID del servicio que desea realizar: ");
		validacion = comprobarIndexOcupadoServicios(listaServicios,lenghtServicios, listaTrabajos[index].idServicio);
		while(validacion == -1){
			listaTrabajos[index].idServicio = pedirEntero("Error...Ingrese en ID valido\nIngrese el ID del servicio que desea realizar: ");
			validacion = comprobarIndexOcupadoServicios(listaServicios,lenghtServicios, listaTrabajos[index].idServicio);
		}

		mostrarListadoBicicletas(listaBicicletas,lenghtBicicletas);
		listaTrabajos[index].idBicicleta=pedirEntero("Ingrese el ID de la Bicicleta a la cual se le realiza el trabajo: ");
		validacion=comprobarIndexOcupadoBicicleta(listaBicicletas,lenghtBicicletas,listaTrabajos[index].idBicicleta);
		while(validacion == -1){
			listaTrabajos[index].idBicicleta=pedirEntero("Error...Ingrese en ID valido\nIngrese el ID de la Bicicleta a la cual se le realiza el trabajo: ");
				validacion=comprobarIndexOcupadoBicicleta(listaBicicletas,lenghtBicicletas,listaTrabajos[index].idBicicleta);

		}
		listaTrabajos[index].fecha=pedirFecha(listaTrabajos[index]);

		listaTrabajos[index].isEmpty = OCUPADO;

		rtn = 1;
	}

	return rtn;
}


//PARTE 2

int modificarTrabajos(eTrabajo listaTrabajos[], int lenghtTrabajos, eServicio listaServicios[], int lenghtServicios, eBicicleta listaBicicletas[], int lenghtBicicletas){

	int datoABuscar;
	int index;
	int reintentos;
	int rtn;

	reintentos = 0;
	rtn = 0;

	datoABuscar = pedirEntero("\nIngrese el ID del trabajo para modificar los datos: ");
	index = comprobarIndexOcupadoTrabajo(listaTrabajos,lenghtTrabajos,datoABuscar);
	while(index == -1 && reintentos < 3){
		datoABuscar = pedirEntero("\n\t---Error...El ID del trabajo ingresado NO es valido---\n\nIngrese el ID del trabajo para modificar los datos: ");
		index = comprobarIndexOcupadoTrabajo(listaTrabajos,lenghtTrabajos,datoABuscar);
		reintentos++;
	}

	if(index != -1){
		rtn = 1;
		if(modificarDatosTrabajos(listaTrabajos, index, lenghtTrabajos, listaServicios, lenghtServicios, listaBicicletas, lenghtBicicletas) == -1){
			puts("\nNo se modificaron los datos del trabajo\n");
		} else {
			puts("\nDatos modificados correctamente!\n");
		}
	}
	return rtn;
}

int modificarDatosTrabajos(eTrabajo listaTrabajos[], int index,int lenghtTrabajos, eServicio listaServicios[], int lenghtServicios, eBicicleta listaBicicletas[], int lenghtBicicletas){
	int opciones;
	int flagModifico;
	int validacion;
	int rtn;

	flagModifico = 0;

	rtn = 0;

	do {
		saltoDeLinea(1);
		opciones = pedirEnteroConRango("1. Cambiar la Bicicleta a la cual se le hace el trabajo\n2. Cambiar el Servicio\n3. Salir\nIngrese una opcion: ", "Error... Ingrese una opcion valida", 1, 3);
		switch(opciones){
			case 1:
				mostrarListadoBicicletas(listaBicicletas,lenghtBicicletas);
				listaTrabajos[index].idBicicleta=pedirEntero("Ingrese el ID de la nueva Bicicleta: ");
				validacion=comprobarIndexOcupadoBicicleta(listaBicicletas,lenghtBicicletas,listaTrabajos[index].idBicicleta);
				while(validacion == -1){
					listaTrabajos[index].idBicicleta=pedirEntero("Error...Ingrese en ID valido\nIngrese el ID de la nueva Bicicleta: ");
					validacion=comprobarIndexOcupadoBicicleta(listaBicicletas,lenghtBicicletas,listaTrabajos[index].idBicicleta);

				}
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

	if(flagModifico!=0){
		rtn = 1;
	}

	return rtn;
}

void ordenarTrabajosPorAnioOMarca(eTrabajo listaTrabajo[], int lenghtTrabajo, eBicicleta listaBicicletas[], int lenghtBicicletas){
	int i;
	int j;

	eTrabajo aux;
	eBicicleta auxUno;
	eBicicleta auxDos;

	for(i=0;i<lenghtTrabajo-1;i++){
		if(listaTrabajo[i].isEmpty == OCUPADO){
			auxUno=buscarIDYAsignarBicicleta(listaBicicletas, lenghtBicicletas, listaTrabajo[i].idBicicleta);
			for(j=i+1;j<lenghtTrabajo;j++){
				if(listaTrabajo[j].isEmpty==OCUPADO){
					auxDos=buscarIDYAsignarBicicleta(listaBicicletas, lenghtBicicletas, listaTrabajo[j].idBicicleta);
					if(listaTrabajo[i].fecha.anio < listaTrabajo[j].fecha.anio){
						aux = listaTrabajo[i];
						listaTrabajo[i]=listaTrabajo[j];
						listaTrabajo[j] = aux;
					} else {
						if(listaTrabajo[i].fecha.anio == listaTrabajo[j].fecha.anio && strcmp (auxUno.marca,auxDos.marca) < 0){
							aux = listaTrabajo[i];
							listaTrabajo[i]=listaTrabajo[j];
							listaTrabajo[j] = aux;
						}
					}
				}
			}
		}
	}
}

eBicicleta buscarIDYAsignarBicicleta(eBicicleta listaBicicletas[], int lenghtBicicletas, int idBicicleta){
	int i;
	eBicicleta aux;

	for(i=0;i<lenghtBicicletas;i++){
		if(listaBicicletas[i].isEmpty == OCUPADO && listaBicicletas[i].id == idBicicleta){
			aux=listaBicicletas[i];
			break;
		}
	}

	return aux;

}

void printTotalEnPesosTrabajos(eTrabajo listaTrabajos[], int lenghtTrabajos, eServicio listaServicios[], int lenghtServicios){
	float total;

	total = calcularTotalEnPesosTrabajos(listaTrabajos, lenghtTrabajos, listaServicios, lenghtServicios);

	printf("\nEl total en pesos por los servicios realizados es: %.2f", total);

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

//PARTE G
void ordenarTrabajosPorMarca(eTrabajo listaTrabajo[], int lenghtTrabajo, eBicicleta listaBicicletas[], int lenghtBicicletas){
	int i;
	int j;

	eTrabajo aux;
	eBicicleta auxUno;
	eBicicleta auxDos;

	for(i=0;i<lenghtTrabajo-1;i++){
		if(listaTrabajo[i].isEmpty == OCUPADO){
			auxUno=buscarIDYAsignarBicicleta(listaBicicletas, lenghtBicicletas, listaTrabajo[i].idBicicleta);
			for(j=i+1;j<lenghtTrabajo;j++){
				if(listaTrabajo[j].isEmpty==OCUPADO){
					auxDos=buscarIDYAsignarBicicleta(listaBicicletas, lenghtBicicletas, listaTrabajo[j].idBicicleta);
					if(strcmp (auxUno.marca,auxDos.marca) < 0){
						aux = listaTrabajo[i];
						listaTrabajo[i]=listaTrabajo[j];
						listaTrabajo[j] = aux;
					}
				}
			}
		}
	}
}

//PARTE H
void inicializarAuxiliarComoServicio(eServicio listaServicios[], int lenghtServicios, eAuxiliar listaAuxiliar[]){
	int i;

	for(i=0;i<lenghtServicios;i++){
		listaAuxiliar[i].id=listaServicios[i].id;
		listaAuxiliar[i].contador=0;
		listaAuxiliar[i].isEmpty=listaServicios[i].isEmpty;
	}
}


void calcularServiciosConMasTrabajos(eTrabajo listaTrabajos[], int lenghtTrabajos, eServicio listaServicios[], int lenghtServicios){
	eAuxiliar auxiliar[lenghtServicios];
	int contador;

	inicializarAuxiliarComoServicio(listaServicios, lenghtServicios, auxiliar);
	contadorDeMaximosServicios(listaTrabajos, lenghtTrabajos, auxiliar, lenghtServicios);
	contador=calcularMaximoServicio(auxiliar,lenghtServicios);
	printMasServiciosUtilizados(auxiliar,listaServicios,lenghtServicios,contador);

}

void contadorDeMaximosServicios(eTrabajo listaTrabajos[], int lenghtTrabajos, eAuxiliar listaAuxiliar[], int lenghtServicios){
	int i;
	int j;

	for(i=0;i<lenghtServicios;i++){
		if(listaAuxiliar[i].isEmpty == OCUPADO){
			for(j=0;j<lenghtTrabajos;j++){
				if(listaTrabajos[j].isEmpty == OCUPADO && listaAuxiliar[i].id==listaTrabajos[j].idServicio){
					listaAuxiliar[i].contador++;
				}
			}
		}
	}
}

void printMasServiciosUtilizados(eAuxiliar lista[], eServicio listaServicios[], int lenghtServicios, int maximo){
	int i;
	int j;

	for(i=0;i<lenghtServicios;i++){
		if(lista[i].isEmpty==OCUPADO){
			for(j=0;j<lenghtServicios;j++){
				if(lista[i].id == listaServicios[j].id && lista[i].contador == maximo && listaServicios[j].isEmpty == OCUPADO){
					mostrarUnElementoServicios(listaServicios[j]);
				}
			}
		}
	}
}

//PARTE I
void mostrarListadoServiciosYBicicletas(eTrabajo listaTrabajos[], int lenghtTrabajos, eServicio listaServicios[], int lenghtServicios, eBicicleta listaBicicletas[], int lenghtBicicletas){
	int i;
	int validacion;
	for(i=0;i<lenghtServicios;i++){
		if(listaServicios[i].isEmpty==OCUPADO){
			mostrarUnElementoServicios(listaServicios[i]);
			saltoDeLinea(1);
			validacion = mostrarUnElementoBicicletaServicio(listaTrabajos,lenghtTrabajos,listaBicicletas,lenghtBicicletas,listaServicios[i]);
			if(validacion == -1){
				printf("\t---No hay elementos de este tipo---\n\n");
			}
		}
	}
}

int mostrarUnElementoBicicletaServicio(eTrabajo listaTrabajos[], int lenghtTrabajos, eBicicleta listaBicicletas[], int lenghtBicicletas, eServicio unElemento){
	int i;
	int encontro;
	eBicicleta aux;

	encontro = -1;

	for(i=0;i<lenghtTrabajos;i++){
		if(listaTrabajos[i].isEmpty == OCUPADO && unElemento.id == listaTrabajos[i].idServicio){
			aux=buscarIDYAsignarBicicleta(listaBicicletas, lenghtBicicletas, listaTrabajos[i].idBicicleta);
			mostrarUnElementoBicicleta(aux);
			encontro = 1;
		}
	}
	return encontro;
}
