/*
 * main.c
 *
 *  Created on: 4 may. 2021
 *      Author: luciano
 */

#include <stdio_ext.h>
#include <stdlib.h>

#include "Utilidades.h"
#include "eServicio.h"
#include "eTrabajo.h"
#include "eBicicleta.h"
#include "nexoEstructuras.h"

#define LENGHT_TRABAJO 20
#define LENGHT_BICICLETAS 5
#define LENGHT_SERVICIO 7


int main (void){

	setbuf(stdout,NULL);

	eServicio listaServicios[LENGHT_SERVICIO];
	inicializarIsEmptyServicios(listaServicios,LENGHT_SERVICIO);
	hardocodearDatosUnaStructServicios(listaServicios);

	eTrabajo listaTrabajos[LENGHT_TRABAJO];
	inicializarIsEmptyTrabajos(listaTrabajos,LENGHT_TRABAJO);
	hardcodearStructTrabajo(listaTrabajos);

	eBicicleta listaBicicletas[LENGHT_BICICLETAS];
	inicializarIsEmptyBicicleta(listaBicicletas,LENGHT_BICICLETAS);
	hardcodearStructBicicleta(listaBicicletas);

	int opcion;
	int flagTrabajos;
	int flagServicios;
	int flagBicicletas;

	flagBicicletas = -1;
	flagServicios = -1;
	flagBicicletas = -1;

	do{
		opcion = menu();

		flagTrabajos = comprobarEspaciosOcupadosEstructuraTrabajo(listaTrabajos, LENGHT_TRABAJO);
		flagServicios = comprobarEspaciosOcupadosEstructuraServicios(listaServicios,LENGHT_SERVICIO);
		flagBicicletas = comprobarEspaciosOcupadosEstructuraBicicleta(listaBicicletas,LENGHT_BICICLETAS);

		switch(opcion){
			case 1:
				if(flagServicios != -1 && flagBicicletas != -1){
					if(altaDatosTrabajos(listaTrabajos, LENGHT_TRABAJO,listaServicios,LENGHT_SERVICIO,listaBicicletas,LENGHT_BICICLETAS)){
						puts("\nDatos cargado correctamente\n");
					} else {
						puts("\nNo hay espacio disponible en la lista de trabajos\n");
					}
				} else {
					if(flagServicios != -1){
						puts("\nNo se pueden hacer trabajos porque no hay servicios disponibles\n");
					} else {
						puts("\nNo se pueden hacer trabajos porque no hay Bicicletas en el local\n");
					}
				}
				break;
			case 2:
				if(flagServicios != -1 && flagTrabajos != -1 && flagBicicletas != -1){
					if(modificarTrabajos(listaTrabajos, LENGHT_TRABAJO,listaServicios,LENGHT_SERVICIO,listaBicicletas,LENGHT_BICICLETAS)!=1){
						puts("\nError... el ID ingresado no es valido/no existe\n");
					}
				} else {
					if(flagTrabajos == -1){
						puts("\nNo hay trabajos cargados para modificar!\n");
					} else {
						if(flagServicios != -1){
							puts("\nNo se pueden modificar trabajos porque no hay servicios disponibles\n");
						} else {
							puts("\nNo se pueden modificar trabajos porque no hay Bicicletas en el local\n");
						}
					}
				}
				break;
			case 3:
				if(flagServicios != -1 && flagTrabajos != -1 && flagBicicletas != -1){
					if(bajaListaEstructuraTrabajo(listaTrabajos, LENGHT_TRABAJO)){
						puts("\nTrabajo borrado correctamente\n");
					} else {
						puts("\nError... el ID ingresado no es valido/no existe\n");
					}
				} else {
					if(flagTrabajos == -1){
						puts("\nNo hay trabajos cargados para dar de baja!\n");
					} else {
						if(flagTrabajos == -1) {
							puts("\nNo se pueden dar de baja trabajos porque no hay servicios disponibles\n");
						} else {
							puts("\nNo se pueden dar de baja trabajos porque no hay Bicicletas en el local\n");
						}
					}
				}
				break;
			case 4:
				if(flagServicios != -1 && flagTrabajos != -1 && flagBicicletas){
					puts("\nTrabajos ordenados por anio y/o marca");
					ordenarTrabajosPorAnioOMarca(listaTrabajos, LENGHT_TRABAJO, listaBicicletas,LENGHT_BICICLETAS);
					mostrarListadoTrabajos(listaTrabajos, LENGHT_TRABAJO);
				} else {
					if(flagTrabajos == -1){
						puts("\nNo hay trabajos cargados para mostrar!\n");
					} else {
						if(flagTrabajos == -1) {
							puts("\nNo se pueden mostrar trabajos porque no hay servicios disponibles\n");
						} else {
							puts("\nNo se pueden mostrar trabajos porque no hay Bicicletas en el local\n");
						}
					}
				}
				break;
			case 5:
				if(flagServicios != -1){
					mostrarListadoServicios(listaServicios,LENGHT_SERVICIO);
				} else {
					if(flagServicios == -1){
						puts("\nNo se pueden hacer trabajos porque no hay servicios disponibles\n");
					}
				}
				break;
			case 6:
				if(flagServicios != -1 && flagTrabajos != -1 && flagBicicletas){
					printTotalEnPesosTrabajos(listaTrabajos, LENGHT_TRABAJO,listaServicios,LENGHT_SERVICIO);
				} else {
					if(flagTrabajos == -1){
						puts("\nNo hay trabajos cargados para calcular el total de trabajos en pesos!\n");
					} else {
						if(flagTrabajos == -1) {
							puts("\nNo se puede calcular el total de trabajos en pesos trabajos porque no hay servicios disponibles\n");
						} else {
							puts("\nNo se puede calcular el total de trabajos en pesos porque no hay Bicicletas en el local\n");
						}
					}
				}
				break;
			case 7:
				if(flagServicios != -1 && flagTrabajos != -1 && flagBicicletas){
					puts("\nTrabajos ordenados por marca");
					ordenarTrabajosPorMarca(listaTrabajos, LENGHT_TRABAJO, listaBicicletas,LENGHT_BICICLETAS);
					mostrarListadoTrabajos(listaTrabajos, LENGHT_TRABAJO);
				} else {
					if(flagTrabajos == -1){
						puts("\nNo hay trabajos cargados para mostrar!\n");
					} else {
						if(flagTrabajos == -1) {
							puts("\nNo se pueden mostrar trabajos porque no hay servicios disponibles\n");
						} else {
							puts("\nNo se pueden mostrar trabajos porque no hay Bicicletas en el local\n");
						}
					}
				}
				break;
			case 8:
				if(flagServicios != -1 && flagTrabajos != -1 && flagBicicletas){
					calcularServiciosConMasTrabajos(listaTrabajos, LENGHT_TRABAJO,listaServicios,LENGHT_SERVICIO);
				} else {
					if(flagTrabajos == -1){
						puts("\nNo hay trabajos cargados para mostrar el servicio mas realizado!\n");
					} else {
						if(flagTrabajos == -1) {
							puts("\nNo se puede mostrar el servicio mas realizado porque no hay servicios disponibles\n");
						} else {
							puts("\nNo se puede mostrar el servicio mas realizado porque no hay Bicicletas en el local\n");
						}
					}
				}
				break;
			case 9:
				if(flagServicios != -1 && flagTrabajos != -1 && flagBicicletas){
					mostrarListadoServiciosYBicicletas(listaTrabajos, LENGHT_TRABAJO,listaServicios,LENGHT_SERVICIO,listaBicicletas,LENGHT_BICICLETAS);
				} else {
					if(flagTrabajos == -1){
						puts("\nNo hay trabajos cargados para mostrar el servicio con las bicicletas!\n");
					} else {
						if(flagTrabajos == -1) {
							puts("\nNo se puede mostrar el servicio con las bicicletas porque no hay servicios disponibles\n");
						} else {
							puts("\nNo se puede mostrar el servicio con las bicicletas porque no hay Bicicletas en el local\n");
						}
					}
				}
				break;
			default:
				puts("\nGracias por utilizar el programa!");
				break;
		}

	}while(opcion != 10);



	return EXIT_SUCCESS;
}
