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
#include "nexoEstructuras.h"

#define LENGHT_TRABAJO 25
#define LENGHT_SERVICIO 7


int main (void){

	setbuf(stdout,NULL);

	eServicio listaServicios[LENGHT_SERVICIO];
	inicializarIsEmptyServicios(listaServicios,LENGHT_SERVICIO);
	hardocodearDatosUnaStructServicios(listaServicios);

	eTrabajo listaTrabajos[LENGHT_TRABAJO];
	inicializarIsEmptyTrabajos(listaTrabajos,LENGHT_TRABAJO);


	int opcion;
	int flagTrabajos;
	int flagServicios;

	do{
		opcion = menu();

		flagTrabajos = comprobarEspaciosOcupadosEstructuraTrabajo(listaTrabajos, LENGHT_TRABAJO);
		flagServicios = comprobarEspaciosOcupadosEstructuraServicios(listaServicios,LENGHT_SERVICIO);

		switch(opcion){
			case 1:
				if(flagServicios != -1){
					altaEstructuraTrabajo(listaTrabajos, LENGHT_TRABAJO,listaServicios,LENGHT_SERVICIO);
				} else {
					puts("\nNo se pueden hacer trabajos porque no hay servicios disponibles\n");
				}
				break;
			case 2:
				if(flagServicios != -1 && flagTrabajos != -1){
					modificarTrabajos(listaTrabajos, LENGHT_TRABAJO,listaServicios,LENGHT_SERVICIO);
				} else{
					if(flagTrabajos == -1){
						puts("\nNo hay trabajos cargados para modificar!\n");
					} else {
						puts("\nNo se pueden hacer trabajos porque no hay servicios disponibles\n");
					}
				}
				break;
			case 3:
				if(flagServicios != -1 && flagTrabajos != -1){
					bajaListaEstructuraTrabajo(listaTrabajos, LENGHT_TRABAJO);
				} else{
					if(flagTrabajos == -1){
						puts("\nNo hay trabajos cargados para dar de baja!\n");
					} else {
						puts("\nNo se pueden hacer trabajos porque no hay servicios disponibles\n");
					}
				}
				break;
			case 4:
				if(flagServicios != -1 && flagTrabajos != -1){
					ordenarTrabajosPorAnioYMarca(listaTrabajos, LENGHT_TRABAJO);
					mostrarListadoTrabajos(listaTrabajos, LENGHT_TRABAJO);
				} else{
					if(flagTrabajos == -1){
						puts("\nNo hay trabajos cargados para listar!\n");
					} else {
						puts("\nNo se pueden hacer trabajos porque no hay servicios disponibles\n");
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
				if(flagServicios != -1 && flagTrabajos != -1){
					printTotalEnPesosTrabajos(listaTrabajos, LENGHT_TRABAJO,listaServicios,LENGHT_SERVICIO);
				} else{
					if(flagTrabajos == -1){
						puts("\nNo hay trabajos cargados para calcular el total en pesos!\n");
					} else {
						puts("\nNo se pueden hacer trabajos porque no hay servicios disponibles\n");
					}
				}
				break;
			default:
				puts("\nGracias por utilizar el programa!");
				break;
		}

	}while(opcion != 7);



	return EXIT_SUCCESS;
}
